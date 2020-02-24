#include "../include/Person.h"

Person::Person(const std::string name, const uint member_id, const std::string city, const std::string state, const uint zip)
{
    this->name=name;
    this->member_id=member_id;
    this->city=city;
    this->state=state;
    this->zip=zip;
}

Person::~Person()
{

}
