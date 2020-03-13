#include "../include/ProviderDirectory.h"
#include "../include/Database.h"
#include <iostream>
#include <iomanip>

using namespace std;

ProviderDirectory::ProviderDirectory() {
   Database reader;
   reader.service_info(service_names, service_codes);
}

ProviderDirectory::~ProviderDirectory() { }

int ProviderDirectory::generate_directory(){
  cout<<"List of services:\n";
  map<string, uint>::iterator i = service_names.begin();

  while(i != service_names.end()){
     cout << setfill(' ') << setw(15) << left << i->first << ": " << setw(6) << setfill('0') << right << i->second << "\n";
     ++i;
  }
  return 0;
};
