#include "../include/Provider.h"
#include<iostream>
using namespace std;


void Provider::display_info(){
   cout<<"The provider's information:"<<endl;
   Person::display_info();
}

Provider::Provider() { }

Provider::Provider(
      std::string name,
      std::string id,
      std::string street,
      std::string city,
      std::string state,
      uint zip
      ) : Person(name, id, street, city, state, zip) { }

Provider::~Provider() { }
