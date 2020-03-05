#include "../include/ProviderModule.h"
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
#include <fstream>
#include "../include/Member.h"

using namespace std;

int ProviderModule::init(uint id)
{
  if (providers.find(id) == providers.end())
    return -1;

  cout << "\n\n\nWelcome to the Provider terminal";
  int choice = 0;
  uint sel=0;

  while (choice != 4)
  {
    cout << "\n\n\nWhat is your purpose?\n\n"
        << "1. Validate Member\n"
        << "2. Provide Service\n"
        << "3. Provider directory\n"
        << "4. Exit\n";
    cin >> choice;
    cout << "\n\n";
    switch(choice)
    {
      case 1:
        int isSuspended;
        cout << "What is the member ID you wish to validate?";
        if (cin.fail())
        {
          cin.ignore(INT_MAX, '\n');
          cin.clear();
          cout << "Invalid input...\n\n";
        }
        else
        {
          cin >> sel;
        }
        isSuspended = validate_member(sel);
        if (isSuspended == 1)
        {
          cout << "Member ID " << sel << " status: SUSPENDED\n";
        }
        else if (isSuspended == 0)
        {
          cout << "Member ID " << sel << " status: VALID\n";
        }
        else if (isSuspended < 0)
        {
          cout << "Member ID " << sel << " not found\n";
        }
        break;
      case 2:
      {
        Service new_service;
        new_service.build();
        provide_service(new_service);   

        break;
      }
      case 3:
        get_provider_directory();
        break;
      case 4:
        break;
      default:
        cin.clear();
        cin.ignore();
        cout << "You did not select a valid response\n\n";
    }
  }

  return 0;
}

int ProviderModule::validate_member(uint id)
{
  int returnCode = -1;
  unordered_map<uint, Member>::iterator i = members.find(id);
  if (i != members.end())
  {
    returnCode = i->second.get_suspended();
  }


  return returnCode;
}
int ProviderModule::provide_service(Service& service)
{
  int return_code = 0;
  fstream outFile;
  outFile.open("database/services.csv", fstream::out | fstream::app);
  if (outFile.is_open())
  {
  outFile << service.get_service_name() << "\n" << service.get_member_id() << "\n" << service.get_provider_id() << "\n" << service.get_date_added() << "\n" << service.get_service_date() << "\n" << service.get_service_code() << "\n" << service.get_comments() << "\n";
  }
  else
  {
    return_code = -1;
  }
  return return_code;
}
int ProviderModule::get_provider_directory()
{
  directory.generate_directory();
  return 0;
}

ProviderModule::ProviderModule()
{
  char *name, *city, *state;
  bool suspended;
  uint zip, id;

  // Initialize members map by reading from the members.csv file
  fstream inFile;
  inFile.open("database/members.csv");
  //while (!inFile.eof())
    name = new char[1000];
    city = new char[1000];
    state = new char[1000];
  while (inFile.getline(name,999))
  {
    inFile >> id;
    inFile.ignore();
    inFile.getline(city, 999);
    inFile.getline(state,999);
    inFile >> zip;
    inFile.ignore();
    inFile >> suspended;
    inFile.ignore();

    //cout << "DEBUG: " << name << id << city << state << zip;
    if (suspended)
    {
      //cout << "SUSPENDED";
      //cout << "\n";
    }
    members.insert(make_pair(id,Member(name, id, city, state, zip, suspended)));
  }
  delete [] name;
  delete [] city;
  delete [] state;
  inFile.close();

  // Initialize providers map by reading from the providers.csv file
  inFile.open("database/providers.csv");
  //while (!inFile.eof())
    name = new char[1000];
    city = new char[1000];
    state = new char[1000];
  while (inFile.getline(name,999))
  {
    inFile >> id;
    inFile.ignore();
    inFile.getline(city, 999);
    inFile.getline(state,999);
    inFile >> zip;
    inFile.ignore();

    //cout << "DEBUG: " << name << id << city << state << zip;
    //cout << "\n";
    providers.insert(make_pair(id,Provider(name, id, city, state, zip)));
  }
  inFile.close();
  delete [] name;
  delete [] city;
  delete [] state;


}


ProviderModule::~ProviderModule()
{

}
