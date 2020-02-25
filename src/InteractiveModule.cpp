#include "../include/InteractiveModule.h"
#include <climits>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include "../include/Person.h"
#include "../include/Member.h"
#include "../include/Provider.h"

using namespace std;
//init(): let user choose which function to use.
int InteractiveModule::init() {
  cout << "\n\n\nWelcome to the database interactive terminal";
  int choice = 0;
  uint id = 0;
  while (choice != 9)
  {
    cout << "\n\n\nWhat is your purpose?\n\n"
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
        if (cin.fail())
        {
          cin.ignore(INT_MAX, '\n');
          cin.clear();
          cout << "Invalid input...\n\n";
        }
        else
        {
          cin >> id;
        }
        display_member(id);
        break;
      case 2:
        add_member();
        break;
      case 3:
        cout<<"Please enter the member number";
        cin >> id;
        if (cin.fail())
        {
          cin.ignore(INT_MAX, '\n');
          cin.clear();
          cout << "Invalid input...\n\n";
        }
        else
        {
          edit_member(id);
        }
        break;
      case 4:
        cout<<"Please enter the id u want remove:"<<endl;
        if (cin.fail())
        {
          cin.ignore(INT_MAX, '\n');
          cin.clear();
          cout << "Invalid input...\n\n";
        }
        else
        {
          cin>>id;
        }
        remove_member(id);
        break;
      case 5:
        break;
      case 6:
        add_provider();
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

//add_member(): add a member into map, use the member_id as primary key.
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
  //save the member into cvs file
  ofstream outFile;
  outFile.open("Member.cvs", ios::app);
  outFile << name << ',' << id<< ',' << city<<','<<state<<','<<zip<<endl;
  // If member with that id is not in the map already...
  members.insert(make_pair(id, member));
  // else fail


   return 0;
}

//edit_member(): search member in map, and use member's set funnction to edit member's information.
int InteractiveModule::edit_member(uint member_id) {

   return 0;
}

//remove_member(): use map's erase function to remove member.
int InteractiveModule::remove_member(uint member_id) {

   return 0;
}

//display_member():search member in map, and use member's display_info() function to display the information.
int InteractiveModule::display_member(uint member_id) {
  cout << "Searching for member with member id " << member_id <<"\n\n";
  // Get member by member_id from the database
  // Call the persons display data function
  unordered_map<uint, Member>::iterator i = members.find(member_id);
  if (i == members.end())
  {
    cout << "Member with member id " << member_id << " not found\n\n";
  }
  else
  {
    cout << "Member found:\n"
        << "Member id: " << i->second.get_id()
        << "\nName: " << i->second.get_name()
        << "\nCity: " << i->second.get_city()
        << "\nState: " << i->second.get_state()
        << "\nZip: " << i->second.get_zip() << endl;
  }
   return 0;
}

//add_provider(): user input information, create a provider object, and insert into map.
int InteractiveModule::add_provider() {

   return 0;
}

//edit_provider(): search provider in map, and use provider's set function to edit information.
int InteractiveModule::edit_provider(uint member_id) {

   return 0;
}

//remove_provider(unit provider_id): use map's erase function, to remove provider in map.
int InteractiveModule::remove_provider(uint provider_id) {

   return 0;
}

//display_provider(unit provider_id): search provider_id in map,and use provider's display_info() to display info.
int InteractiveModule::display_provider(uint provider_id) {

   return 0;
}

//write_out(): write the data in map to cvs file. 
int InteractiveModule::write_out() {

   return 0;
}

//InteractiveModule(): read the data in cvs into map.
InteractiveModule::InteractiveModule()
{

}


InteractiveModule::~InteractiveModule()
{

}
