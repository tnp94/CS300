#include "../include/ManagerModule.h"
#include <iostream>

using namespace std;

int ManagerModule::init() {
  cout << "\n\n\nWelcome to the manager's terminal\n\n";
  int choice = 0;
  while (choice != 4)
  {
    cout << "What is your purpose?\n\n"
        << "1. \n"
        << "2. \n"
        << "3. \n"
        << "4. Exit\n";
    cin >> choice;
    switch(choice)
    {
      case 1:
        break;
      case 2:
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

   return 0;
}

int ManagerModule::member_report(uint provider_id) {

   return 0;
}

ManagerModule::ManagerModule()
{

}


ManagerModule::~ManagerModule()
{

}
