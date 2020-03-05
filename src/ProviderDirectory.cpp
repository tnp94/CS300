#include "../include/ProviderDirectory.h"
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include "../include/Person.h"
#include "../include/Member.h"
#include "../include/Provider.h"

using namespace std;

int ProviderDirectory::generate_directory(){
  cout<<"List of services:\n";
  map<string, Service>::iterator i = services.begin();
  while(i != services.end()){
  //cout<<"Provider ID: "<<i->get_provider_id()<<"\n";
  cout << i->second.get_service_name() << ": " << i->second.get_service_code() << "\n";
  //cout<<"Date Added: "<<i->get_service_code()<<"\n\n";
  ++i;
  }
  return 0;
};
