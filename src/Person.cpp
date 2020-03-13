#include "../include/Person.h"

void Person::display_info(){
  cout << "Name: "         << name  << endl;
  cout << "Provider_id: "  << id    << endl;
  cout << "City: "         << city  << endl;
  cout << "State: "        << state << endl;
  cout << "Zip: "          << zip   << endl;
}

void Person::set_name(std::string name){
    this->name=name;
}

void Person::set_id(string id){
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

Person::Person( std::string name,  std::string id,  std::string city,  std::string state,  uint zip) {
    this->name=name;
    this->id=id;
    this->city=city;
    this->state=state;
    this->zip=zip;
}

Person::~Person() { }
