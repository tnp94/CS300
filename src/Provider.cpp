#include "../include/Provider.h"
#include<iostream>
using namespace std;

void Provider::display_info(){
  cout<<"The provider's information:"<<endl;
  cout<<"Name: "<<get_name()<<endl;
  cout<<"Provider_id: "<<get_id()<<endl;
  cout<<"City: "<<get_city()<<endl;
  cout<<"State: "<<get_state()<<endl;
  cout<<"Zip: "<<get_zip()<<endl;
}


Provider::Provider(const std::string name, const uint id, const std::string city, const std::string state, const uint zip) : Person(name, id, city, state, zip)
{
  this->name=name;
  this->id=id;
  this->city=city;
  this->state=state;
  this->zip=zip;
}

Provider::~Provider()
{

}
