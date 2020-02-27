#include "../include/ProviderModule.h"
#include <climits>
#include <string>
#include <iostream>
using namespace std;

int ProviderModule::init(uint id)
{
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
        validate_member(sel);
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

return 0;
}
int ProviderModule::provide_service(Service& service)
{

return 0;
}
int ProviderModule::get_provider_directory()
{

return 0;
}
ProviderModule::ProviderModule()
{

}


ProviderModule::~ProviderModule()
{

}
