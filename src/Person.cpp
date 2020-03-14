#include "../include/Person.h"
#include <iostream>

using namespace std;
void Person::display_info(){
   cout << "Name: "     << name   << endl;
   cout << "ID: "       << id     << endl;
   cout << "Street: "   << street << endl;
   cout << "City: "     << city   << endl;
   cout << "State: "    << state  << endl;
   cout << "Zip: "      << zip    << endl;
}

void Person::set_name(std::string name){
   this->name=name;
}

string Person::get_name() {
   return name;
}

void Person::set_id(std::string id){
   this->id=id;
}

void Person::set_city(std::string city){
   this->city=city;
}

void Person::set_state(std::string state){
   this->state=state;
}

void Person::set_zip(uint zip){
   this->zip=zip;
}

string Person::to_csv() {
   return name + "|" + id + "|" + street + "|" + city + "|" + state + "|" + to_string(zip);
}

string Person::report() {
   return "Name: " + name + "\nID: " + id + "\nStreet: " + street + "\nCity: " + city + "\nState: " + state + "\nZip " + to_string(zip);
}

Person::Person() { }
Person::Person(std::string name, std::string id, std::string street, std::string city, std::string state, uint zip) {
   this -> name   = name;
   this -> id     = id;
   this -> street = street;
   this -> city   = city;
   this -> state  = state;
   this -> zip    = zip;
}

Person::~Person() { }
