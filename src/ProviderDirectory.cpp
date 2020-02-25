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
  cout<<"List of Providers:\n";
  unordered_map<uint, Service>::iterator i = service.begin(provider_id);
  while(i!=service.end()){
  cout<<"Provider ID: "<<i->get_provider_id()<<"\n";
  cout<<"Service: "<<i->get_service_name()<<"\n";
  cout<<"Date Added: "<<i->get_service_code()<<"\n\n";
  ++i;
  }
  return 0;
};
