#include "../include/ProviderModule.h"
#include "../include/Database.h"
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
#include <fstream>
#include "../include/Member.h"

using namespace std;

int ProviderModule::init(string id) {
  if (providers.find(id) == providers.end())
    return -1;

  cout << "\n\n\nWelcome to the Provider terminal\n\n";
  int choice = 0;
  string sel="0";

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
      case 1: {
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
              }

      case 2: {
      {
        Service new_service;
        if (new_service.build(id))
        {
          provide_service(new_service);   
        }
        break;
      }
              }
      case 3: {
        get_provider_directory();
        break;
              }
      case 4: {
        Database writer;
        writer.write_services(services);
        return 0;
              }

      default: {
        cin.clear();
        cin.ignore();
        cout << "You did not select a valid response\n\n";
               }
    }
  }

  return 0;
}

int ProviderModule::validate_member(string id) {
  int returnCode = -1;
  unordered_map<string, Member>::iterator i = members.find(id);
  if (i != members.end())
  {
    returnCode = i->second.get_suspended();
  }

  return returnCode;
}
int ProviderModule::provide_service(Service& service)
{
}
int ProviderModule::get_provider_directory()
{
  directory.generate_directory();
  return 0;
}

ProviderModule::ProviderModule() {
   Database reader;
   reader.members(members);
   reader.providers(providers);
   reader.services(services);
}

ProviderModule::~ProviderModule() { }
