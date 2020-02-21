#include "../include/InteractiveModule.h"
#include <iostream>

using namespace std;

int InteractiveModule::init() {
  cout << "\n\n\nWelcome to the database interactive terminal\n\n";
  int choice = 0;
  while (choice != 9)
  {
    cout << "What is your purpose?\n\n"
        << "1. Display Existing Member\n"
        << "2. Add New Member\n"
        << "3. Edit Member\n"
        << "4. Remove A Member\n"
        << "5. Display Existing Provider\n"
        << "6. Add New Provider\n"
        << "7. Edit Provider\n"
        << "8. Remove A Provider\n"
        << "9. Exit\n";
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

int InteractiveModule::add_member() {

   return 0;
}

int InteractiveModule::edit_member(uint member_id) {

   return 0;
}

int InteractiveModule::remove_member(uint member_id) {

   return 0;
}

int InteractiveModule::display_member(uint member_id) {

   return 0;
}

int InteractiveModule::add_provider(uint provider_id) {

   return 0;
}

int InteractiveModule::edit_provider(uint member_id) {

   return 0;
}

int InteractiveModule::remove_provider(uint provider_id) {

   return 0;
}

int InteractiveModule::display_provider(uint provider_id) {

   return 0;
}

int InteractiveModule::write_out() {

   return 0;
}

InteractiveModule::InteractiveModule()
{

}


InteractiveModule::~InteractiveModule()
{

}
