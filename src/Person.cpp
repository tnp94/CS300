#include "../include/Person.h"

std::string Person::get_name(){
    return this->name;
}

std::string Person::get_city(){
    return this->city;
}

std::string Person::get_state(){
     return this->state;
 }

uint Person::get_zip(){
    return this->zip;
}

uint Person::get_id(){
    return this->id;
}

void Person::set_name(std::string name){
    this->name=name;
}

void Person::set_id(uint id){
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

Person::Person(const std::string name, const uint id, const std::string city, const std::string state, const uint zip)
{
    this->name=name;
    this->id=id;
    this->city=city;
    this->state=state;
    this->zip=zip;
}

Person::~Person()
{

}
