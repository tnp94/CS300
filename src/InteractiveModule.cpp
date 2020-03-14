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
#include "../include/Database.h"

using namespace std;

#ifdef TEST
   int valid_id_test() {
      InteractiveModule mod;
      cout << "valid id test\n";
      if(mod.id_is_valid(string("123456789"))) {
         cout << "passed\n";
         return 0;
      }

      cout << "failed\n";
      return -1;
   }
   int invalid_id_test() {
      InteractiveModule mod;
      cout << "invalid id test\n";
      if(!mod.id_is_valid(string("23456789"))) {
         cout << "passed\n";
         return 0;
      }

      cout << "failed\n";
      return -1;
   }
#endif
//let user choose which function to use
int InteractiveModule::init() {
   cout << "\n\n\nWelcome to the database interactive terminal\n\n\n";
   int choice = 0;
   string id = "0";

   while (choice != 9) {
      cin.clear();

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
         case 1: {
                    cout << "What is the member ID of the member you would like to display: ";
                    cin >> id;
                    cin.ignore(INT_MAX, '\n');

                    if (cin.fail()) {
                       cin.ignore(INT_MAX, '\n');
                       cin.clear();
                       cout << "Invalid input...\n\n";
                    } else
                       display_person(id, MEMBER);

                    break;
                 }

         case 2: {
                    Member new_member;
                    new_member.set_suspended(0);
                    add_person(&new_member, MEMBER);
                    break;
                 }

         case 3: {
                    cout << "Please enter the member ID";
                    cin >> id;
                    cin.ignore(INT_MAX, '\n');

                    if (cin.fail()) {
                       cin.clear();
                       cin.ignore(INT_MAX, '\n');
                       cout << "Invalid input...\n\n";
                    } else 
                       edit_person(id, MEMBER);

                    break;
                 }

         case 4: {
                    cout << "Please enter the id you want remove:\n";
                    cin >> id;
                    cin.ignore(INT_MAX, '\n');

                    if (cin.fail()) {
                       cin.clear();
                       cin.ignore(INT_MAX, '\n');
                       cout << "Invalid input...\n\n";
                    } else
                       remove_person(id, MEMBER);

                    break;
                 }

         case 5: {
                    cout << "What is the provider ID of the provider you would like to display: ";
                    cin >> id;
                    cin.ignore(INT_MAX, '\n');

                    if (cin.fail()) {
                       cin.clear();
                       cin.ignore(INT_MAX, '\n');
                       cout << "Invalid input...\n\n";
                    } else
                       display_person(id, PROVIDER);

                    break;
                 }

         case 6: {
                    Provider new_provider;
                    add_person(&new_provider, PROVIDER);
                    break;
                 }

         case 7: {
                    cout << "What is the provider ID of the provider you would like to edit: ";
                    cin >> id;
                    cin.ignore(INT_MAX, '\n');

                    if (cin.fail()) {
                       cin.clear();
                       cin.ignore(INT_MAX, '\n');
                       cout << "Invalid input...\n\n";
                    } else
                       edit_person(id, PROVIDER);

                    break;
                 }

         case 8: {
                    cout << "What is the provider number of the provider you would like to remove: ";
                    cin >> id;
                    cin.ignore(INT_MAX, '\n');

                    if (cin.fail()) {
                       cin.clear();
                       cin.ignore(INT_MAX, '\n');
                       cout << "Invalid input...\n\n";
                    } else
                       remove_person(id, PROVIDER);

                    break;
                 }

         case 9: {
                    write_out();
                    return 0;
                 }

         default: {
                     if(cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                     }
                     cout << "You did not select a valid response\n\n";
                  }
      }
   }
   return 0;
}

bool InteractiveModule::id_is_valid(string id) {
   if(id.size() != 9) {
      cout << "id must be 9 digits\n";
      return false;
   }

   for(string::iterator it = id.begin(); it != id.end(); ++it) {
      if(!isdigit(*it)) {
         cout << "id must be 9 digits\n";
         return false;
      }
   }

   return true;
}

//add_member(): add a member into map, use the member_id as primary key.
int InteractiveModule::add_person(Person* to_add, PersonType type) {
   uint zip;
   std::string name, state, verification, id;
   std::string city, street;
   bool correct = false;
   bool id_exists = false;

   while (!correct) {
     cin.ignore(INT_MAX, '\n');
     cin.clear();
      cout << "Add new member...\n\n";
      cout << "Enter new member name:\n";
      getline(cin, name);

      do {
         cout << "Enter new member id:\n";
         cin >> id;
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         id_exists = (data.members.find(id) != data.members.end());
         if (id_exists) {
            cout << "A member already exists with that id number\n\n";
         }
      } while (cin.fail() || id_exists || !id_is_valid(id));

      cout << "Enter new member street address:\n";
      getline(std::cin, city);
      cout << "Enter new member city:\n";
      getline(std::cin, city);
      cout << "Enter new member state:\n";
      getline(cin, state);

      do {
         cout << "Enter new member zip:\n";
         cin >> zip;
         cin.clear();
         cin.ignore(INT_MAX, '\n');
      } while (cin.fail());


      do {
         do
         {
            cout << "The following member ready to add:\n"
            << "Name: " << name
            << "\nID: " << id
            << "\nStreet: " << id
            << "\nCity: " << city
            << "\nState: " << state
            << "\nZip: " << zip
            << "\n\nIs this information correct? (y/n): ";

            cin >> verification;
            cin.clear();
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
         } while(!(verification == "y" || verification == "n"));
      } while(cin.fail());
   }

   to_add -> set_name(name);
   to_add -> set_id(id);
   to_add -> set_street(street);
   to_add -> set_city(city);
   to_add -> set_state(state);
   to_add -> set_zip(zip);

   // static cast is okay because objects were made by init()
   if(type == PROVIDER)
      data.providers.insert(make_pair(id, *static_cast<Provider*>(to_add)));
   else
      data.members.insert(make_pair(id, *static_cast<Member*>(to_add)));

   return 0;
}

// Edits a member or data.providers record in the database
int InteractiveModule::edit_person(string id, PersonType type) {
   Person *target;
   if(type == PROVIDER) {
      unordered_map<string, Provider>::iterator i = data.providers.find(id);
      if (i == data.providers.end()) {
         cout << "provider with id " << id << " not found\n\n";
         return -1;
      }
      target = &(i -> second);
   } else {
      unordered_map<string, Member>::iterator i = data.members.find(id);
      if (i == data.members.end()) {
         cout << "member with id " << id << " not found\n\n";
         return -1;
      }
      target = &(i -> second);
   }

   cout << "Found the person, the information is: " << endl;
   target -> display_info();

   int choice=0;

   while(choice!=7) {
<<<<<<< HEAD
      cout<<"Which part of information you want to edit? Input 7 to exit and save."<<endl;
      cout<<"1.id"<<endl;
      cout<<"2.Name"<<endl;
      cout<<"3.Street"<<endl;
      cout<<"4.City"<<endl;
      cout<<"5.State"<<endl;
      cout<<"6.Zip"<<endl;
      cout<<"7.Exit"<<endl;

      cin>>choice;
      cin.ignore(INT_MAX, '\n');
      cin.clear();

      switch(choice) {
         case 1: {
                    string new_id = "0";
                    bool valid = false;
                    do {
                       do {
                          cout << "Please input new member id: " << endl;
                          cin >> new_id;
                          cin.ignore(INT_MAX, '\n');
                       } while(!id_is_valid(new_id));

                       if(type == PROVIDER && data.providers.find(new_id) != data.providers.end()) {
                          cout << "A provider already exists with that id\n\n";
                       } else if(type == MEMBER && data.members.find(new_id) != data.members.end()) {
                          cout << "A member already exists with that id\n\n";
                       } else {
                          valid = true;
                       }

                       if(valid) {
                          if(type == PROVIDER) {
                             Provider new_person = *static_cast<Provider*>(target);
                             new_person.set_id(new_id);
                             data.providers.insert(make_pair(new_id, new_person));
                             data.providers.erase(data.providers.find(id));
                             id = new_id;
                             target = &data.providers.find(new_id) -> second;
                          } else {
                             Member new_person = *static_cast<Member*>(target);
                             new_person.set_id(new_id);
                             data.members.insert(make_pair(new_id, new_person));
                             data.members.erase(data.members.find(id));
                             id = new_id;
                             target = &data.providers.find(new_id) -> second;
                          }
                       }
                    } while(!valid);

                    break;
                 }

         case 2: {
                    string new_name = " ";
                    cout << "Please input new name: " << endl;
                    getline(cin, new_name);
                    target -> set_name(new_name);
                    break;
                 }

         case 3: {
                    string new_street = " ";
                    cout << "Please input new street address: " << endl;
                    getline(cin, new_street);
                    target -> set_street(new_street);
                    break;
                 }

         case 4: {
                    string new_city = " ";
                    cout << "Please input new city: " << endl;
                    getline(cin, new_city);
                    target -> set_city(new_city);
                    break;
                 }

         case 5: {
<<<<<<< HEAD
                    string new_state=" ";
                    cout<<"Please input new state: "<<endl;
                    getline(cin, new_state);
=======
                    string new_state = " ";
                    cout << "Please input new state: (TWO letter code)" << endl;
                    cin >> new_state;
>>>>>>> bc345388435eb89230fd30f11ce4673a9499414b
                    target -> set_state(new_state);
                    break;
                 }

         case 6: {
                    uint new_zip = 0;
                    do {
                       cout << "Please input new zip id:\n";
                       cin >> new_zip;

                       if(cin.fail()) {
                          cout << "Please enter a valid zip\n";
                          cin.clear();
                          cin.ignore(INT_MAX, '\n');
                       } else
                          target -> set_zip(new_zip);
                    } while(cin.fail());

                    break;
                 }

         case 7: {
                    break;
                 }

         default: {
                     cout << "You did not select a valid response"<<endl;
                  }
      }
   }
   return 0;
}

// use map's erase function to remove member or provider.
int InteractiveModule::remove_person(string id, PersonType type) {
   cout << "Searching for person with id " << id <<endl;
   Person* target;
   if(type == PROVIDER) {
      unordered_map<string, Provider>::iterator i = data.providers.find(id);
      if (i == data.providers.end()) {
         cout << "Person with ID " << id << " not found\n\n";
         return -1;
      }
      target = &(i -> second);
      cout << "Found, the information is: \n";
      target -> display_info();

      int choice=0;
      while(choice != 1 && choice != 2) {
         cout << "Input 1 to remove this person, input 2 to exit." << endl;
         cout << "1.Yes" << endl;
         cout << "2.Exit" << endl;

         cin >> choice;
         cin.ignore(INT_MAX, '\n');

         switch(choice) {
            case 1:
               data.providers.erase(i);
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

   unordered_map<string, Member>::iterator i = data.members.find(id);
   if (i == data.members.end()) {
      cout << "Person with ID " << id << " not found\n\n";
      return -1;
   }
   target = &(i -> second);

   cout << "Found, the information is: \n";
   target -> display_info();

   int choice=0;
   while(choice != 1 && choice != 2) {
      cout << "Input 1 to remove this person, input 2 to exit." << endl;
      cout << "1.Yes" << endl;
      cout << "2.Exit" << endl;

      cin >> choice;
      cin.ignore(INT_MAX, '\n');

      switch(choice) {
         case 1:
            data.members.erase(i);
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
int InteractiveModule::display_person(string id, PersonType type) {
   cout << "Searching for person with id " << id <<"\n\n";
   Person* target;
   if(type == PROVIDER) {
      unordered_map<string, Provider>::iterator i = data.providers.find(id);
      if (i == data.providers.end()) {
         cout << "Person with id " << id << " not found\n\n";
         return -1;
      }
      target = &(i -> second);
   }
   else {
      unordered_map<string, Member>::iterator i = data.members.find(id);
      if (i == data.members.end()) {
         cout << "Person with id " << id << " not found\n\n";
         return -1;
      }
      target = &(i -> second);
   }

   cout << "Person found:\n";
   target -> display_info();
   return 0;
}

// write the data in maps to file. 
int InteractiveModule::write_out() {
   data.write_members();
   data.write_providers();
   return 0;
}

//InteractiveModule(): read the data in csv into map.
InteractiveModule::InteractiveModule() { }

InteractiveModule::~InteractiveModule() { }
