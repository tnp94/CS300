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

//let user choose which function to use
int InteractiveModule::init() {
   cout << "\n\n\nWelcome to the database interactive terminal\n\n\n";
   int choice = 0;
   string id = "0";

   while (choice != 9) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');

      // TODO suspend person
      cout << "\n\nWhat is your purpose?\n\n"
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
      cin.ignore(INT_MAX, '\n');
      cout << "\n\n";

      switch(choice) {
         case 1:
            cout << "What is the member ID of the member you would like to display: ";
            cin >> id;
            cin.ignore(INT_MAX, '\n');

            if (cin.fail()) {
               cin.clear();
               cout << "Invalid input...\n\n";
            } else
               display_person(id, members);

            break;

         case 2:
            Member new_member;
            add_person(new_member, members);
            break;

         case 3:
            cout << "Please enter the member ID";
            cin >> id;
            cin.ignore(INT_MAX, '\n');

            if (cin.fail()) {
               cin.clear();
               cout << "Invalid input...\n\n";
            } else 
               edit_person(id, members);

            break;

         case 4:
            cout << "Please enter the id you want remove:\n";
            cin >> id;
               cin.ignore(INT_MAX, '\n');

            if (cin.fail()) {
               cin.clear();
               cout << "Invalid input...\n\n";
            } else
               remove_person(id, members);

            break;

         case 5:
            cout << "What is the provider ID of the provider you would like to display: ";
            cin >> id;
            cin.ignore(INT_MAX, '\n');

            if (cin.fail()) {
               cin.clear();
               cout << "Invalid input...\n\n";
            } else
               display_person(id, providers);

            break;

         case 6:
            Provider new_provider;
            add_person(new_provider, providers);
            break;

         case 7:
            cout << "What is the provider ID of the provider you would like to edit: ";
            cin >> id;
            cin.ignore(INT_MAX, '\n');

            if (cin.fail()) {
               cin.clear();
               cout << "Invalid input...\n\n";
            } else
               edit_person(id, providers);

            break;

         case 8:
            cout << "What is the provider number of the provider you would like to remove: ";
            cin >> id;
            cin.ignore(INT_MAX, '\n');

            if (cin.fail()) {
               cin.clear();
               cout << "Invalid input...\n\n";
            } else
               remove_person(id, providers);

            break;

         case 9:
            write_out();
            return 0;

         default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "You did not select a valid response\n\n";
      }
   }
   return 0;
}

//add_member(): add a member into map, use the member_id as primary key.
int InteractiveModule::add_person(Person& to_add, unordered_map<string, person> map) {
   uint zip;
   std::string name, city, state, verification, id;
   bool correct = false;
   bool id_exists = false;

   while (!correct) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Add new member...\n\n";
      cout << "Enter new member name:\n";
      cin >> name;
      cin.ignore(INT_MAX, '\n');

      do {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         //TODO check vlid id
         cout << "Enter new member id:\n";
         cin >> id;
         cin.ignore(INT_MAX, '\n');
         id_exists = (members.find(id) != members.end());
         if (id_exists) {
            cout << "A member already exists with that id number\n\n";
         }
      } while (cin.fail() || id_exists);

      cout << "Enter new member city:\n";
      cin >> city;
      cin.ignore(INT_MAX, '\n');
      cout << "Enter new member state:\n";
      cin >> state;
      cin.ignore(INT_MAX, '\n');

      do {
         cin.clear();
         cin.ignore();
         cout << "Enter new member zip:\n";
         cin >> zip;
         cin.ignore(INT_MAX, '\n');
      } while (cin.fail());


      do {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         cout << "The following member ready to add:\n"
            << "Name: " << name
            << "\nID: " << id
            << "\nCity: " << city
            << "\nState: " << state
            << "\nZip: " << zip
            << "\n\nIs this information correct? (y/n): ";

         cin >> verification;
         cin.ignore(INT_MAX, '\n');
         if (verification == "y") {
            cout << "Adding member...\n\n";
            correct = true;
         }
         else if (verification == "n") {
            cout << "Information rejected...\n";
            return -1;
         }
         else {
            cout << "Invalid input...\n";
         }
      } while(cin.fail());
   }

   Member member(name, id, city, state, zip, false);
   members.insert(make_pair(id, member));
   return 0;
}

// Edits a member or providers record in the database
int InteractiveModule::edit_person(string id, unordered_map<string, Person> map) {
   unordered_map<uint, Member>::iterator i = map.find(id);

   if (i == map.end()) {
      cout << "person with id " << id << " not found\n\n";
      return -1;
   }

      cout<<"Found the person, the information is: "<<endl;
      i -> display_info();

      int choice=0;

      while(choice!=6) {
         cout<<"Which part of information you want to edit? Input 6 to exit and save."<<endl;
         cout<<"1.id"<<endl;
         cout<<"2.Name"<<endl;
         cout<<"3.City"<<endl;
         cout<<"4.State"<<endl;
         cout<<"5.Zip"<<endl;
         cout<<"6.Exit"<<endl;

         cin>>choice;
         cin.ignore(INT_MAX, '\n');
         cin.clear();

         switch(choice) {
            case 1:
               // TODO while id isnt valid
               uint new_id = 0;
               cout << "Please input new member id: " << endl;
               cin >> new_id;
               cin.ignore(INT_MAX, '\n');

               unordered_map<uint, Person>::iterator new_person = map.find(new_id);

               if (new_member == map.end()) {
                  Person& new_person = *i;
                  new_person.set_id(new_id);
                  map.insert(make_pair(new_id, new_person));
                  map.erase(i);
                  id = new_id;
                  i = map.find(new_id);
               } else 
                  cout << "A member already exists with that id\n\n";

               break;

            case 2:
               string new_name = " ";
               cout << "Please input new name: " << endl;
               cin >> new_name;
               i->second.set_name(new_name);
               break;

            case 3:
               string new_city = " ";
               cout << "Please input new city: " << endl;
               cin >> new_city;
               i->second.set_city(new_city);
               break;

            case 4:
               string new_state=" ";
               cout<<"Please input new state: "<<endl;
               cin>>new_state;
               i->second.set_state(new_state);
               break;

            case 5: 
               do {
                  cin.clear();
                  uint new_zip = 0;
                  cout << "Please input new zip id:\n";
                  cin >> new_zip;
                  cin.ignore(INT_MAX, '\n');

                  if(cin.fail()) {
                     cout << "Please enter a valid zip\n";
                  } else
                     i->second.set_zip(new_zip);
               } while(cin.fail())

               break;

            case 6:
               break;

            default:
               cin.clear();
               cin.ignore(INT_MAX, '\n');
               cout << "You did not select a valid response"<<endl;
         }
      }
   }
   return 0;
}

// use map's erase function to remove member or provider.
int InteractiveModule::remove_person(string id, unordered_map<string, Person> map) {
   cout << "Searching for person with id " << id <<endl;
   unordered_map<uint, Person>::iterator i = map.find(id);
   if (i == map.end()) {
      cout << "Person with ID " << id << " not found\n\n";
      return -1;
   }

   cout << "Found, the information is: \n";
   i -> display_info();

   int choice=0;
   while(choice != 1 && choice != 2) {
      cout << "Input 1 to remove this person, input 2 to exit." << endl;
      cout << "1.Yes" << endl;
      cout << "2.Exit" << endl;

      cin >> choice;
      cin.ignore(INT_MAX, '\n');

      switch(choice) {
         case 1:
            map.erase(i);
            cout << "The person has been removed." << endl;
            break;
         case 2:
            break;
         default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "You did not select a valid response" << endl;
      }
   }
   return 0;
}

// search membor or provider in map, and use display_info() function to display the information.
int InteractiveModule::display_person(string id, unordered_map<string, Person> map) {
   cout << "Searching for person with id " << id <<"\n\n";
   unordered_map<uint, Person>::iterator i = map.find(id);

   if (i == map.end()) {
      cout << "Person with id " << id << " not found\n\n";
      return -1;
   }

   cout << "Person found:\n";
   i -> display_info()
   return 0;
}

// write the data in maps to file. 
int InteractiveModule::write_out() {
   Database writer;
   writer.write_members(members);
   writer.write_providers(providers);
   return 0;
}

//InteractiveModule(): read the data in csv into map.
InteractiveModule::InteractiveModule() {
   Database reader;
   reader.members(members);
   reader.providers(providers);
}

InteractiveModule::~InteractiveModule() { }
