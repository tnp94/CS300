#include "../include/Database.h"

using namespace std;


Databse() {}
~Database() {}

void read_person(std::istream &file, person_data& result) {
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

void members(std::unordered_map<std::string, Member>& map) {
   person_data base;
   bool suspended;

   fstream inFile;
   inFile.open("database/members.csv");
   cin.ignore(INT_MAX, '\n');
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

void providers(std::unordered_map<std::string, Provider>& map) {
   person_data base;

   fstream inFile;
   inFile.open("database/providers.csv");
   cin.ignore(INT_MAX, '\n');
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

void services(std::map<time_t, Service>& map) {
   char member[10];
   char provider[10];
   time_t date_added;
   time_t date_service;
   uint service_code;
   char comments[1000];
   map<string, uint> service_names, service_codes;
   service_info(service_names, service_codes);

   fstream inFile;
   inFile.open("database/providers.csv");
   cin.ignore(INT_MAX, '\n');
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
      inFile.get(comments, 10, '|');
      inFile.ignore(1, '\n');
      inFile.peek();

      Service to_add(string(member), string(provider), service_codes.find(service_code) -> second, date_added, date_service, service_code, string(comments));
      map.insert(make_pair(date_service, to_add));
   }

   inFile.close();
}

void service_info(map<string, uint>& name_map, map<uint, string>& code_map) {
   char name[1000];
   uint code;

   fstream inFile;
   inFile.open("database/providerdirectory.csv");
   cin.ignore(INT_MAX, '\n');
   inFile.peek();

   while(!inFile.eof()) {
      inFile.get(name, 1000, '|');
      inFile >> code;
      inFile.ignore(1, '\n';
      inFile.peek();

      name_map.insert(make_pair<string, uint>(name, code));
      code_map.insert(make_pair<uint, string>(code, name));
   }

   inFile.close();
}

//TODO
void write_members(std::unordered_map<std::string, Member>& map) {
   ofstream outFile;
   outFile.open("database/members.csv");
   unordered_map<uint, Member>::iterator mi = members.begin();

   while (mi != members.end()) {
      outFile << mi -> to_csv() << endl;
      mi++;
   }

   outFile.close();
}

void write_providers(std::unordered_map<std::string, Provider>& map) {
   outFile.open("database/providers.csv");
   unordered_map<uint, Provider>::iterator pi = providers.begin();

   while (pi != providers.end()) {
      outFile pi -> to_csv() << endl;
      pi++;
   }

   outFile.close();
}

void write_services(std::map<time_t, Service>& map) {
}

