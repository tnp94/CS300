#include "../include/ManagerModule.h"
#include "../include/Database.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;

//init() : let user choose which function to use.
int ManagerModule::init() {
  cout << "\n\n\nWelcome to the manager's terminal\n\n";
  int choice = 0, id_number;
  weekly_report();


  while (choice != 4) {
    cin.clear();
    cout << "What is your purpose?\n\n"
        << "1. Generate Summary Report\n"
        << "2. Generate Provider Report\n"
        << "3. Generate Member report\n"
        << "4. Exit\n";
    cin >> choice;
    cin.ignore(INT_MAX, '\n');

    switch(choice) {
      case 1:
        cout<<"\nGenerate Summary Report\n";
        if(summary_report())
          cout << "Summary report failed!\n\n";
        break;

      case 2:
        cout << "\nGenerate Provider Report\n\n"
            << "What is the provider number of the provider you want a report for?\n";
            cin >> id_number;
            cin.ignore(INT_MAX, '\n');
            if(provider_report(id_number))
               cout << "Provider report failed!\n\n";
        break;

      case 3:
        cout<<"\nGenerate Member report\n\n"
            << "What is the member number of the member you want a report for?\n";
            cin >> id_number;
            cin.ignore(INT_MAX, '\n');
            if(member_report(id_number))
               cout << "Member report failed!\n\n";
        break;

      case 4:
        return 0;

      default:
        cout << "You did not select a valid response\n\n";
        cin.ignore(INT_MAX, '\n');
        cin.clear();
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
   return 0;
}


std::string ManagerModule::person_report(Person& person) {
   return string(" ");
}

//provider_report(uint provider_id) : display the service the provider provides.
int ManagerModule::provider_report(uint provider_id) {
   return 0;
}


//member_report(uint member_id) : display the service the member owns.
int ManagerModule::member_report(uint member_id) {
   return 0;
}

//ManagerModule(): read the data from csv file into map.
ManagerModule::ManagerModule() {
   Database reader;
   reader.members(members);
   reader.providers(providers);
   reader.services(services);
}


ManagerModule::~ManagerModule() { }
