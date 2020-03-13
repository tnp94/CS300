#include "../include/Member.h"
#include<iostream>
using namespace std;
void Member::set_suspended(bool suspended){
  this->suspended=suspended;
}

bool Member::get_suspended(){
  return suspended;
}

void Member::display_info(){
  cout << "The member's information:" << endl;
  Person::display_info();
  cout << "suspeded: " << suspended;
}

string Member::to_csv() {
   return string(" ");
}

Member::Member(
       std::string name,
       std::string member_id,
       std::string city,
       std::string state,
       uint zip,
       bool suspended
      ):Person(name, member_id, city, state, zip) {
  this->suspended = suspended;
}

Member::Member() { }
Member::~Member() { }
