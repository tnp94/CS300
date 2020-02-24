#include "../include/Member.h"

void Member::set_suspended(bool suspended){
  this->suspended=suspended;
}

bool Member::get_suspended(){
  return this->suspended;
}

Member::Member(const std::string name, const uint member_id, const std::string city, const std::string state, const uint zip):Person(name, member_id, city, state, zip)
{
  //Person(const std::string name, const uint member_id, const std::string city, const std::string state, const uint zip)

}

/*Member::~Member()
{

}*/
