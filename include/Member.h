#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <string>

class Member: public Person {

   public:
      Member(
            const std::string name,
            const uint member_id,
            const std::string city,
            const std::string state,
            const uint zip,
            const bool suspended
            );
      //~Member();
      bool get_suspended();
      void set_suspended(bool suspended);
      void display_info();
   
   private:
      bool suspended;
};

#endif
