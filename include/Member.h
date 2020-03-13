#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <string>

class Member: public Person {

   public:
      bool get_suspended();
      void set_suspended(bool suspended);
      void display_info();
   
      Member(
             std::string name,
             uint member_id,
             std::string city,
             std::string state,
             uint zip,
             bool suspended
            );
      ~Member();

   private:
      bool suspended;
};

#endif
