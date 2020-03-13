#include "../include/Database.h"
#include <climits>
#include <fstream>

using namespace std;

Database::Database() {}
Database::~Database() {}

void Database::read_person(std::istream &inFile, person_data& result) {
      inFile.get(result.name, 1000, '|');
      inFile.ignore(1, '|');
      inFile.get(result.id, 1000, '|');
      inFile.ignore(1, '|');
      inFile.get(result.city, 1000, '|');
      inFile.ignore(1, '|');
      inFile.get(result.state, 1000, '|');
      inFile.ignore(1, '|');
      inFile >> result.zip;
}

void Database::members(std::unordered_map<std::string, Member>& map) {
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

      Member to_add(string(base.name), string(base.id), string(base.city), string(base.state), base.zip, suspended);
      map.insert(make_pair(base.id, to_add));
   }

   inFile.close();
}

void Database::providers(std::unordered_map<std::string, Provider>& map) {
   person_data base;

   fstream inFile;
   inFile.open("database/providers.csv");
   inFile.ignore(INT_MAX, '\n');
   inFile.peek();

   while(!inFile.eof()) {
      read_person(inFile, base);
      inFile.ignore(1, '\n');
      inFile.peek();

      Provider to_add(string(base.name), string(base.id), string(base.city), string(base.state), base.zip);
      map.insert(make_pair(base.id, to_add));
   }

   inFile.close();
}

void Database::services(std::map<time_t, Service>& services) {
   char member[10];
   char provider[10];
   time_t date_added;
   time_t date_service;
   uint service_code;
   char comments[1000];
   map<string, uint> service_names;
   map<uint, string> service_codes;
   service_info(service_names, service_codes);

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
      inFile.get(comments, 1000, '\n');
      inFile.ignore(1, '\n');
      inFile.peek();

      Service to_add(string(member), string(provider), service_codes.find(service_code) -> second, date_added, date_service, service_code, string(comments));
      services.insert(make_pair(date_service, to_add));
   }

   inFile.close();
}

void Database::service_info(map<string, uint>& name_map, map<uint, string>& code_map) {
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

      name_map.insert(pair<string, uint>(string(name), code));
      code_map.insert(pair<uint, string>(code, string(name)));
   }

   inFile.close();
}

//TODO
void Database::write_members(std::unordered_map<std::string, Member>& members) {
   ofstream outFile;
   outFile.open("database/members.csv");
   unordered_map<string, Member>::iterator mi = members.begin();

   while (mi != members.end()) {
      outFile << mi -> second.to_csv();
      mi++;
      if (mi != members.end()) 
         outFile << endl;
   }

   outFile.close();
}

void Database::write_providers(std::unordered_map<std::string, Provider>& providers) {
   ofstream outFile;
   outFile.open("database/providers.csv");
   unordered_map<string, Provider>::iterator pi = providers.begin();

   while (pi != providers.end()) {
      outFile << pi -> second.to_csv();
      pi++;
      if (pi != providers.end()) 
         outFile << endl;
   }

   outFile.close();
}

void Database::write_services(std::map<time_t, Service>& services) {
   ofstream outFile;
   outFile.open("database/services.csv");
   map<time_t, Service>::iterator si = services.begin();

   while (si != services.end()) {
      outFile << si -> second.to_csv();
      si++;
      if (si != services.end()) 
         outFile << endl;
   }

   outFile.close();
}
