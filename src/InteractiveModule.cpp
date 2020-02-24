#include "../include/InteractiveModule.h"
#include <string>
#include <iostream>
#include "../include/Person.h"
#include "../include/Member.h"
#include "../include/Provider.h"

using namespace std;

int InteractiveModule::init() {
  cout << "\n\n\nWelcome to the database interactive terminal\n\n";
  int choice = 0;
  uint id = 0;
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
    cout << "\n\n";
    switch(choice)
    {
      case 1:
        cout << "What is the member number of the member you would like to display: ";
        cin >> id;
        display_member(id);
        break;
      case 2:
        add_member();
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      default:
        cin.clear();
        cin.ignore();
        cout << "You did not select a valid response\n\n";
    }
  }

   return 0;
}

int InteractiveModule::add_member() {
  uint id, zip;
  std::string name, city, state, verification;
  bool correct = false;

  while (!correct)
  {
  cout << "Add new member...\n\n";
  cout << "Enter new member name:\n";
  cin >> name;

  do {
  cin.clear();
  cin.ignore();
  cout << "Enter new member id:\n";
  cin >> id;
  } while (cin.fail());

  cout << "Enter new member city:\n";
  cin >> city;
  cout << "Enter new member state:\n";
  cin >> state;

  do {
  cin.clear();
  cin.ignore();
  cout << "Enter new member zip:\n";
  cin >> zip;
  } while (cin.fail());
  

  do
  {
    cin.clear();
    cin.ignore();
    cout << "The following member ready to add:\n";
    cout << "Name: " << name
        << "\nID: " << id
        << "\nCity: " << city
        << "\nState: " << state
        << "\nZip: " << zip
        << "\n\nIs this information correct? (y/n): ";
    cin >> verification;
    if (verification == "y")
    {
      cout << "Adding member...\n\n";
      correct = true;
    }
    else if (verification == "n")
    {
      cout << "Starting over\n";
      correct = false;
    }
    else
    {
      cout << "Invalid input...\n";
    }
  } while(cin.fail());

  

  }
  Member member(name, id, city, state, zip);

   return 0;
}

int InteractiveModule::edit_member(uint member_id) {

   return 0;
}

int InteractiveModule::remove_member(uint member_id) {

   return 0;
}

int InteractiveModule::display_member(uint member_id) {
  // Get member by member_id from the database
  // Call the persons display data function
  cout << "DEBUG: Display Member called\n\n";
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
