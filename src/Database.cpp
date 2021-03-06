#include "../include/Database.h"
#include <climits>
#include <fstream>

using namespace std;

#ifdef TEST
int search_valid_provider() {
   cout << "searching for procider test - valid\n";
      if(data.providers.find(string("123456789")) != data.providers.end()) {
         cout << "success\n"; 
         return 0;
      } 

   cout << "failed\n";
   return -1;
}
int search_invalid_provider() {
   cout << "searching for procider test - valid\n";
   if(data.providers.find(string("123888789")) != data.providers.end()) {
      cout << "failed\n";
      return -1;
   } 
   cout << "success\n"; 
   return 0;
}
int remove_valid_provider() {
   cout << "removing provider test - valid\n";
   data.providers.erase(string("123456789"));
   if(data.providers.find(string("123456789")) != data.providers.end()) {
      cout << "failed\n";
      return -1;
   } 
   cout << "success\n"; 
   return 0;
}
int remove_valid_member() {
   cout << "removing member test - valid\n";
   data.members.erase(string("123456789"));
   if(data.members.find(string("123456789")) != data.members.end()) {
      cout << "failed\n";
      return -1;
   } 
   cout << "success\n"; 
   return 0;
}
int remove_invalid_provider() {
   cout << "removing provider test - invalid\n";
   data.providers.erase(string("1234789"));
   if(data.providers.find(string("1234789")) != data.providers.end()) {
      cout << "failed\n";
      return -1;
   } 
   cout << "success\n"; 
   return 0;
}
int remove_invalid_member() {
   cout << "removing member test - invalid\n";
   data.members.erase(string("1234789"));
   if(data.members.find(string("1234789")) != data.members.end()) {
      cout << "failed\n";
      return -1;
   } 
   cout << "success\n"; 
   return 0;
}
int add_valid_provider() {
   cout << "adding provider test\n";
   Provider test;
   test.set_id(string("111"));
   data.providers.insert(pair<string, Provider>(string("111"), test));

   if(data.providers.find(string("111")) == data.providers.end()) {
      cout << "failed\n";
      return -1;
   } 
   cout << "success\n"; 
   return 0;
}
int add_valid_member() {
   cout << "adding member test\n";
   Member test;
   test.set_id(string("111"));
   data.members.insert(pair<string, Member>(string("111"), test));

   if(data.members.find(string("111")) == data.members.end()) {
      cout << "failed\n";
      return -1;
   } 
   cout << "success\n"; 
   return 0;
}
#endif

Database data;

Database::Database() {
   read_service_info();
   read_members();
   read_providers();
   read_services();
}

Database::~Database() {}

void Database::read_person(std::istream &inFile, person_data& result) {
   inFile.get(result.name, 1000, '|');
   inFile.ignore(1, '|');
   inFile.get(result.id, 1000, '|');
   inFile.ignore(1, '|');
   inFile.get(result.street, 1000, '|');
   inFile.ignore(1, '|');
   inFile.get(result.city, 1000, '|');
   inFile.ignore(1, '|');
   inFile.get(result.state, 1000, '|');
   inFile.ignore(1, '|');
   inFile >> result.zip;
}

void Database::read_members() {
   person_data base;
   bool suspended;

   ifstream inFile;
   inFile.open("database/members.csv");
   inFile.ignore(INT_MAX, '\n');
   inFile.peek();

   while(!inFile.eof()) {
      read_person(inFile, base);
      inFile.ignore(1, '|');
      inFile >> suspended;
      inFile.ignore(1, '\n');
      inFile.peek();

      Member to_add(string(base.name), string(base.id), string(base.street), string(base.city), string(base.state), base.zip, suspended);
      members.insert(make_pair(base.id, to_add));
   }

   inFile.close();
}

void Database::read_providers() {
   person_data base;

   fstream inFile;
   inFile.open("database/providers.csv");
   inFile.ignore(INT_MAX, '\n');
   inFile.peek();

   while(!inFile.eof()) {
      read_person(inFile, base);
      inFile.ignore(1, '\n');
      inFile.peek();

      Provider to_add(string(base.name), string(base.id), string(base.street), string(base.city), string(base.state), base.zip);
      providers.insert(make_pair(base.id, to_add));
   }

   inFile.close();
}

void Database::read_services() {
   char member[10];
   char provider[10];
   time_t date_added;
   time_t date_service;
   uint service_code;
   char comments[1000];
   float fee;

   fstream inFile;
   inFile.open("database/services.csv");
   inFile.ignore(INT_MAX, '\n');
   inFile.peek();

   while(!inFile.eof()) {
      inFile.get(member, 10, '|');
      inFile.ignore(1, '|');
      inFile.get(provider, 10, '|');
      inFile.ignore(1, '|');
      inFile >> date_added;
      inFile.ignore(1, '|');
      inFile >> date_service;
      inFile.ignore(1, '|');
      inFile >> service_code;
      inFile.ignore(1, '|');
      inFile >> fee;
      inFile.ignore(1, '|');
      inFile.get(comments, 1000, '\n');
      inFile.ignore(1, '\n');
      inFile.peek();

      Service to_add(string(member), string(provider), service_codes.find(service_code) -> second, date_added, date_service, service_code, string(comments), fee);
      services.insert(make_pair(date_service, to_add));
   }

   inFile.close();
}

void Database::read_service_info() {
   char name[1000];
   uint code;

   fstream inFile;
   inFile.open("database/providerdirectory.csv");
   inFile.ignore(INT_MAX, '\n');
   inFile.peek();

   while(!inFile.eof()) {
      inFile.get(name, 1000, '|');
      inFile.ignore(1, '\n');
      inFile >> code;
      inFile.ignore(1, '\n');
      inFile.peek();

      service_names.insert(pair<string, uint>(string(name), code));
      service_codes.insert(pair<uint, string>(code, string(name)));
   }

   inFile.close();
}

void Database::write_members() {
   ofstream outFile;
   outFile.open("database/members.csv");
   outFile << "name|id|city|state|zip|suspended\n";
   unordered_map<string, Member>::iterator mi = members.begin();

   while (mi != members.end()) {
      outFile << mi -> second.to_csv();
      mi++;
      if (mi != members.end()) 
         outFile << endl;
   }

   outFile.close();
}

void Database::write_providers() {
   ofstream outFile;
   outFile.open("database/providers.csv");
   outFile << "name|id|city|state|zip\n";
   unordered_map<string, Provider>::iterator pi = providers.begin();

   while (pi != providers.end()) {
      outFile << pi -> second.to_csv();
      pi++;
      if (pi != providers.end()) 
         outFile << endl;
   }

   outFile.close();
}

void Database::write_services() {
   ofstream outFile;
   outFile.open("database/services.csv");
   outFile << "member|provider|date added|date of service|service code|fee|comments\n";
   map<time_t, Service>::iterator si = services.begin();

   while (si != services.end()) {
      outFile << si -> second.to_csv();
      si++;
      if (si != services.end()) 
         outFile << endl;
   }

   outFile.close();
}
