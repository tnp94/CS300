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
        cout << "What is the provider number of the provider you would like to display: ";
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
        display_provider(id);
        break;
      case 6:
        add_provider();
        break;
      case 7:
        cout << "What is the provider number of the provider you would like to edit: ";
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
        edit_provider(id);
        break;
      case 8:
        cout << "What is the provider number of the provider you would like to remove: ";
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
        remove_provider(id);
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
  bool id_exists = false;

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
  id_exists = (members.find(id) != members.end());
  if (id_exists)
  {
    cout << "A member already exists with that id number\n\n";
  }
  } while (cin.fail() || id_exists);

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
      cout << "Information rejected...\n";
      return -1;
    }
    else
    {
      cout << "Invalid input...\n";
    }
  } while(cin.fail());

  

  }

  Member member(name, id, city, state, zip, false);
  members.insert(make_pair(id, member));


   return 0;
}

//edit_member(): search member in map, and use member's set funnction to edit member's information.
int InteractiveModule::edit_member(uint member_id) {
   cout << "Searching for member with member id " << member_id <<endl;
    unordered_map<uint, Member>::iterator i = members.find(member_id);
    if (i == members.end())
    {
        cout << "Member with member id " << member_id << " not found\n\n";
    }
    else
    {
        cout<<"Find the member, the information is: "<<endl;
        cout<<"Member id: "<<i->second.get_id()<<endl;
        cout<<"Name :"<<i->second.get_name()<<endl;
        cout<<"City: "<<i->second.get_city()<<endl;
        cout<<"State: "<<i->second.get_state()<<endl;
        cout<<"Zip: "<<i->second.get_zip()<<endl;
        int choice=0;
        while(choice!=6)
        {
            cout<<"Which part of information you want to edit? Input 6 to exit and save."<<endl;
            cout<<"1.Member id"<<endl;
            cout<<"2.Name"<<endl;
            cout<<"3.City"<<endl;
            cout<<"4.State"<<endl;
            cout<<"5.Zip"<<endl;
            cout<<"6.Exit"<<endl;
            cin>>choice;
            switch(choice)
            {
                case 1: {
                    uint new_id = 0;
                    cout << "Please input new member id: " << endl;
                    cin >> new_id;
                    unordered_map<uint, Member>::iterator new_member = members.find(new_id);
                    if (new_member == members.end())
                    {
                      members.insert(make_pair(new_id, Member(i->second.get_name(), new_id, i->second.get_city(), i->second.get_state(), i->second.get_zip(), i->second.get_suspended())));
                      members.erase(i);
                      member_id = new_id;
                      i = members.find(new_id);
                    }
                    else
                    {
                      cout << "A member already exists with that id\n\n";
                    }
                    break;
                }
                case 2: {
                    string new_name = " ";
                    cout << "Please input new name: " << endl;
                    cin >> new_name;
                    i->second.set_name(new_name);
                    break;
                }
                case 3: {
                    string new_city = " ";
                    cout << "Please input new city: " << endl;
                    cin >> new_city;
                    i->second.set_city(new_city);
                    break;
                }
                case 4:{
                    string new_state=" ";
                    cout<<"Please input new state: "<<endl;
                    cin>>new_state;
                    i->second.set_state(new_state);
                    break;
                }
                case 5: {
                    uint new_zip = 0;
                    cout << "Please input new zip id: " << endl;
                    cin >> new_zip;
                    i->second.set_id(new_zip);
                    break;
                }
                case 6:
                    break;
                default:
                    cin.clear();
                    cin.ignore();
                    cout << "You did not select a valid response"<<endl;
            }
        }
    }
   return 0;
}

//remove_member(): use map's erase function to remove member.
int InteractiveModule::remove_member(uint member_id) {
    cout << "Searching for member with member id " << member_id <<endl;
    unordered_map<uint, Member>::iterator i = members.find(member_id);
    if (i == members.end())
    {
        cout << "Member with member id " << member_id << " not found\n\n";
    }
    else
    {
        cout<<"Find the member, the information is: "<<endl;
        cout<<"Member id: "<<i->second.get_id()<<endl;
        cout<<"Name :"<<i->second.get_name()<<endl;
        cout<<"City: "<<i->second.get_city()<<endl;
        cout<<"State: "<<i->second.get_state()<<endl;
        cout<<"Zip: "<<i->second.get_zip()<<endl;
        int choice=0;
        while(choice!=2) {
            cout << "Input 1 to remove this member, input 2 to exit." << endl;
            cout << "1.Yes" << endl;
            cout << "2.Exit" << endl;
            cin>>choice;
            switch(choice)
            {
                case 1:
                    members.erase(i);
                    cout<<"The member has been removed."<<endl;
                    break;
                case 2:
                    break;
                default:
                    cin.clear();
                    cin.ignore();
                    cout << "You did not select a valid response"<<endl;
            }
        }
    }
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
  uint id, zip;
  std::string name, city, state, verification;
  bool correct = false;
  bool id_exists = false;

  while (!correct)
  {
  cout << "Add new provider...\n\n";
  cout << "Enter new provider name:\n";
  cin >> name;

  do {
  cin.clear();
  cin.ignore();
  cout << "Enter new provider id:\n";
  cin >> id;
  id_exists = (providers.find(id) != providers.end());
  if (id_exists)
  {
    cout << "A provider already exists with that id number\n\n";
  }
  } while (cin.fail() || id_exists);

  cout << "Enter new provider city:\n";
  cin >> city;
  cout << "Enter new provider state:\n";
  cin >> state;

  do {
  cin.clear();
  cin.ignore();
  cout << "Enter new provider zip:\n";
  cin >> zip;
  } while (cin.fail());
  

  do
  {
    cin.clear();
    cin.ignore();
    cout << "The following provider ready to add:\n";
    cout << "Name: " << name
        << "\nID: " << id
        << "\nCity: " << city
        << "\nState: " << state
        << "\nZip: " << zip
        << "\n\nIs this information correct? (y/n): ";
    cin >> verification;
    if (verification == "y")
    {
      cout << "Adding provider...\n\n";
      correct = true;
    }
    else if (verification == "n")
    {
      cout << "Information rejected...\n";
      return -1;
    }
    else
    {
      cout << "Invalid input...\n";
    }
  } while(cin.fail());

  

  }

  Provider provider(name, id, city, state, zip);
  //save the member into csv file
  //ofstream outFile;
  //outFile.open("database/providers.csv", ios::app);
  //outFile << name << ',' << id<< ',' << city<<','<<state<<','<<zip<<endl;
  // If member with that id is not in the map already...
  providers.insert(make_pair(id, provider));
  // else fail



   return 0;
}

//edit_provider(): search provider in map, and use provider's set function to edit information.
int InteractiveModule::edit_provider(uint provider_id) {
  cout << "Searching for provider with provider id " << provider_id << endl;
    unordered_map<uint, Provider>::iterator i = providers.find(provider_id);
    if (i == providers.end())
    {
        cout << "Provider with provider id " << provider_id << " not found"<<endl;
    }
    else
    {
        cout<<"Find the provider, the information is: "<<endl;
        cout<<"Provider id: "<<i->second.get_id()<<endl;
        cout<<"Name :"<<i->second.get_name()<<endl;
        cout<<"City: "<<i->second.get_city()<<endl;
        cout<<"State: "<<i->second.get_state()<<endl;
        cout<<"Zip: "<<i->second.get_zip()<<endl;
        int choice=0;
        while(choice!=6)
        {
            cout<<"Which part of information you want to edit? Input 6 to exit and save."<<endl;
            cout<<"1.Provider id"<<endl;
            cout<<"2.Name"<<endl;
            cout<<"3.City"<<endl;
            cout<<"4.State"<<endl;
            cout<<"5.Zip"<<endl;
            cout<<"6.Exit"<<endl;
            cin>>choice;
            switch(choice)
            {
                case 1: {

                    uint new_id = 0;
                    cout << "Please input new provider id: " << endl;
                    cin >> new_id;
                    unordered_map<uint, Provider>::iterator new_provider = providers.find(new_id);
                    if (new_provider == providers.end())
                    {
                      providers.insert(make_pair(new_id, Provider(i->second.get_name(), new_id, i->second.get_city(), i->second.get_state(), i->second.get_zip())));
                      providers.erase(i);
                      provider_id = new_id;
                      i = providers.find(new_id);
                    }
                    else
                    {
                      cout << "A provider already exists with that id\n\n";
                    }
                    break;
                }
                case 2: {
                    string new_name = " ";
                    cout << "Please input new name: " << endl;
                    cin >> new_name;
                    i->second.set_name(new_name);
                    break;
                }
                case 3: {
                    string new_city = " ";
                    cout << "Please input new city: " << endl;
                    cin >> new_city;
                    i->second.set_city(new_city);
                    break;
                }
                case 4:{
                    string new_state=" ";
                    cout<<"Please input new state: "<<endl;
                    cin>>new_state;
                    i->second.set_state(new_state);
                    break;
                }
                case 5: {
                    uint new_zip = 0;
                    cout << "Please input new zip id: " << endl;
                    cin >> new_zip;
                    i->second.set_id(new_zip);
                    break;
                }
                case 6:
                    break;
                default:
                    cin.clear();
                    cin.ignore();
                    cout << "You did not select a valid response"<<endl;
            }
        }
    }
   return 0;
}

//remove_provider(unit provider_id): use map's erase function, to remove provider in map.
int InteractiveModule::remove_provider(uint provider_id) {
   cout << "Searching for provider with provider id " << provider_id <<endl;
    unordered_map<uint, Provider>::iterator i = providers.find(provider_id);
    if (i == providers.end())
    {
        cout << "Provider with provider id " << provider_id << " not found\n\n";
    }
    else
    {
        cout<<"Find the provider, the information is: "<<endl;
        cout<<"Provider id: "<<i->second.get_id()<<endl;
        cout<<"Name :"<<i->second.get_name()<<endl;
        cout<<"City: "<<i->second.get_city()<<endl;
        cout<<"State: "<<i->second.get_state()<<endl;
        cout<<"Zip: "<<i->second.get_zip()<<endl;
        int choice=0;
        while(choice!=2) {
            cout << "Input 1 to remove this provider, input 2 to exit." << endl;
            cout << "1.Yes" << endl;
            cout << "2.Exit" << endl;
            cin >> choice;
            switch(choice)
            {
                case 1:
                    providers.erase(i);
                    cout<<"The member has been removed."<<endl;
                    break;
                case 2:
                    break;
                default:
                    cin.clear();
                    cin.ignore();
                    cout << "You did not select a valid response"<<endl;
            }
        }
    }
   return 0;
}

//display_provider(unit provider_id): search provider_id in map,and use provider's display_info() to display info.
int InteractiveModule::display_provider(uint provider_id) {
  cout << "Searching for provider with provider id " << provider_id <<"\n\n";
  // Get provider by provider_id from the database
  // Call the persons display data function
  unordered_map<uint, Provider>::iterator i = providers.find(provider_id);
  if (i == providers.end())
  {
    cout << "Member with provider id " << provider_id << " not found\n\n";
  }
  else
  {
    cout << "Provider found:\n"
        << "Provider id: " << i->second.get_id()
        << "\nName: " << i->second.get_name()
        << "\nCity: " << i->second.get_city()
        << "\nState: " << i->second.get_state()
        << "\nZip: " << i->second.get_zip() << endl;
  }

   return 0;
}

//write_out(): write the data in map to csv file. 
int InteractiveModule::write_out() {
  ofstream outFile;
  outFile.open("database/members.csv");
  unordered_map<uint, Member>::iterator mi = members.begin();
  
  while (mi != members.end())
  {

    outFile << mi->second.get_name() << "\n" << mi->second.get_id() << "\n" << mi->second.get_city() <<"\n"<<mi->second.get_state() <<"\n"<<mi->second.get_zip() << "\n" << mi->second.get_suspended() << endl;
    mi++;
  }

  outFile.close();
  outFile.open("database/providers.csv");
  unordered_map<uint, Provider>::iterator pi = providers.begin();
  
  while (pi != providers.end())
  {

    outFile << pi->second.get_name() << "\n" << pi->second.get_id() << "\n" << pi->second.get_city() <<"\n"<<pi->second.get_state() <<"\n"<<pi->second.get_zip() << endl;
    pi++;
  }

  outFile.close();
  
   return 0;
}

//InteractiveModule(): read the data in csv into map.
InteractiveModule::InteractiveModule()
{
  char *name, *city, *state;
  bool suspended;
  uint zip, id;

  // Initialize members map by reading from the members.csv file
  fstream inFile;
  inFile.open("database/members.csv");
    name = new char[1000];
    city = new char[1000];
    state = new char[1000];
  //while (!inFile.eof())
  while (inFile.getline(name,999))
  {
    inFile >> id;
    inFile.ignore();
    inFile.getline(city, 999);
    inFile.getline(state,999);
    inFile >> zip;
    inFile.ignore();
    inFile >> suspended;
    inFile.ignore();

    cout << "DEBUG: " << name << id << city << state << zip;
    if (suspended)
    {
      cout << "SUSPENDED";
    }
    members.insert(make_pair(id,Member(name, id, city, state, zip, suspended)));
    cout << "\n";
  }
  inFile.close();
  delete [] name;
  delete [] city;
  delete [] state;

  // Initialize providers map by reading from the providers.csv file
  inFile.open("database/providers.csv");
    name = new char[1000];
    city = new char[1000];
    state = new char[1000];
  //while (!inFile.eof())
  while (inFile.getline(name,999))
  {
    inFile >> id;
    inFile.ignore();
    inFile.getline(city, 999);
    inFile.getline(state,999);
    inFile >> zip;
    inFile.ignore();

    cout << "DEBUG: " << name << id << city << state << zip;
    providers.insert(make_pair(id,Provider(name, id, city, state, zip)));
    cout << "\n";
  }
  inFile.close();
  delete [] name;
  delete [] city;
  delete [] state;


}


InteractiveModule::~InteractiveModule()
{
  write_out();

}
