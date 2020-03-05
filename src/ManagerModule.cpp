#include "../include/ManagerModule.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

//init() : let user choose which function to use.
int ManagerModule::init() {
  cout << "\n\n\nWelcome to the manager's terminal\n\n";
  int choice = 0, id_number;
  int return_code;
  while (choice != 4)
  {
    cout << "What is your purpose?\n\n"
        << "1. Generate Summary Report\n"
        << "2. Generate Provider Report\n"
        << "3. Generate Member report\n"
        << "4. Exit\n";
    cin >> choice;
    switch(choice)
    {
      case 1:
        cout<<"Generate Summary Report\n";
        
        break;
      case 2:
        cout << "\nGenerate Provider Report\n\n"
            << "What is the provider number of the provider you want a report for?\n";
            cin >> id_number;
            return_code = provider_report(id_number);
        break;
      case 3:
        cout<<"Generate Member report\n";
        break;
      case 4:
        cout<<"Generate Member report\n";
        break;
      default:
        cout << "You did not select a valid response\n\n";
    }
  }

   return 0;
}

//weekly_report(): check the time, if it is Friday, display this week's service.
int ManagerModule::weekly_report() {

   return 0;
}

//summary_report(): display all the service in map.
int ManagerModule::summary_report() {
  map<time_t ,Service>::iterator iterator;
    iterator = services.begin();
    cout<<"All service will be listed: "<<endl;
    while(iterator!=services.end()){
        cout<<"The service date: "<<endl;
        cout<<iterator->first<<endl;
        cout<<"The service's information: "<<endl;
        iterator->second.display_info();
   }
   return 0;
}


std::string ManagerModule::person_report(Person& person) {

   std::string a_string;
   return a_string;
}

//provider_report(uint provider_id) : display the service the provider provides.
int ManagerModule::provider_report(uint provider_id) {
  // Check provider map for provider with provider_id
  // If not found, return -1
  // Else, pass provider to person_report and print return with the rest of the report
  cout << "Debug: This is provider_report.\n";

   return 0;
}


//member_report(uint member_id) : display the service the member owns.
int ManagerModule::member_report(uint member_id) {
  // Check member map for member with member_id
  // If not found, return -1
  // Else, pass member to person_report and print return with the rest of the report

   return 0;
}

//ManagerModule(): read the data from csv file into map.
ManagerModule::ManagerModule()
{
      uint member_id;
      uint provider_id;
      char * service_name;
      time_t date_added;
      time_t service_date;
      uint service_code;
      char * comments;

  // Initialize services map by reading from the services.csv file
  fstream inFile;
  inFile.open("database/services.csv");
    service_name = new char[1000];
    comments = new char[1000];
  while (inFile.getline(service_name,999))
  {
    inFile >> member_id;
    inFile >> provider_id;
    inFile >> date_added;
    inFile >> service_date;
    inFile >> service_code;
    inFile.ignore();
    inFile.getline(comments, 999);

    cout << "DEBUG: " << member_id << provider_id << service_name << date_added << service_date << service_code << comments;
    services.insert(make_pair(service_date,Service(member_id, provider_id, service_name, date_added, service_date, service_code,comments)));
    cout << "\n";
  }
  inFile.close();
  delete [] service_name;
  delete [] comments;
}


ManagerModule::~ManagerModule()
{

}
