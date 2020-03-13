#include "../include/Provider.h"
#include<iostream>
using namespace std;


void Provider::display_info(){
  cout<<"The provider's information:"<<endl;
  Person::display_info();
}

Provider::Provider(
       std::string name,
       uint id,
       std::string city,
       std::string state,
       uint zip
      ) : Person(name, id, city, state, zip) { }

Provider::~Provider() { }
