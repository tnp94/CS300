#include "../include/ProviderDirectory.h"
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include "../include/Person.h"
#include "../include/Member.h"
#include "../include/Provider.h"

using namespace std;

int ProviderDirectory::generate_directory(){
      char * service_name; // CSV should be in this order
      uint service_code;

  // Initialize services map by reading from the services.csv file
  fstream inFile;
  inFile.open("database/providerdirectory.csv");
    service_name = new char[1000];
  while (inFile.getline(service_name,999))
  {
    inFile >> service_code;
    inFile.ignore();

    services.insert(make_pair(service_name, Service(service_name, service_code)));
    cout << "\n";
  }
  inFile.close();
  delete [] service_name;

  cout<<"List of services:\n";
  map<string, Service>::iterator i = services.begin();
  while(i != services.end()){
  //cout<<"Provider ID: "<<i->get_provider_id()<<"\n";
  cout << setfill(' ') << setw(15) << left << i->first << ": " << setw(6) << setfill('0') << right << i->second.get_service_code() << "\n";
  //cout<<"Date Added: "<<i->get_service_code()<<"\n\n";
  ++i;
  }
  return 0;
};
