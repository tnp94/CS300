#include "../include/ProviderDirectory.h"
#include <iostream>
#include <iomanip>

using namespace std;

ProviderDirectory::ProviderDirectory() {
   Database reader;
   reader.service_info(services);
}

int ProviderDirectory::generate_directory(){
  cout<<"List of services:\n";
  map<string, uint>::iterator i = services.begin();

  while(i != services.end()){
     cout << setfill(' ') << setw(15) << left << i->first << ": " << setw(6) << setfill('0') << right << i->second << "\n";
     ++i;
  }
  return 0;
};
