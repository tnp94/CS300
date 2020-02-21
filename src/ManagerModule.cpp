#include "../include/ManagerModule.h"
#include <iostream>

using namespace std;

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
        break;
      case 2:
        cout << "\nGenerate Provider Report\n\n"
            << "What is the provider number of the provider you want a report for?\n";
            cin >> id_number;
            return_code = provider_report(id_number);
        break;
      case 3:
        break;
      case 4:
        break;
      default:
        cout << "You did not select a valid response\n\n";
    }
  }

   return 0;
}

int ManagerModule::weekly_report() {

   return 0;
}

int ManagerModule::summary_report() {

   return 0;
}

std::string ManagerModule::person_report(Person& person) {

   std::string a_string;
   return a_string;
}

int ManagerModule::provider_report(uint provider_id) {
  // Check provider map for provider with provider_id
  // If not found, return -1
  // Else, pass provider to person_report and print return with the rest of the report
  cout << "Debug: This is provider_report.\n";

   return 0;
}

int ManagerModule::member_report(uint member_id) {
  // Check member map for member with member_id
  // If not found, return -1
  // Else, pass member to person_report and print return with the rest of the report

   return 0;
}

ManagerModule::ManagerModule()
{

}


ManagerModule::~ManagerModule()
{

}
