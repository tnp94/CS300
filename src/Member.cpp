#include "../include/Member.h"
#include<iostream>
using namespace std;
void Member::set_suspended(bool suspended){
  this->suspended=suspended;
}

bool Member::get_suspended(){
  return this->suspended;
}

void Member::display_info(){
  cout<<"The member's information:"<<endl;
  cout<<"Name: "<<get_name()<<endl;
  cout<<"Member_id: "<<get_id()<<endl;
  cout<<"City: "<<get_city()<<endl;
  cout<<"State: "<<get_state()<<endl;
  cout<<"Zip: "<<get_zip()<<endl;
}

Member::Member(const std::string name, const uint member_id, const std::string city, const std::string state, const uint zip):Person(name, member_id, city, state, zip)
{
  //Person(const std::string name, const uint member_id, const std::string city, const std::string state, const uint zip)

}

/*Member::~Member()
{

}*/
