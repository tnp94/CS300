#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <string>

class Member: public Person {

   public:
      bool get_suspended();
      void set_suspended(bool suspended);
      void display_info();
      std::string to_csv();

      Member(
            std::string name,
            std::string member_id,
            std::string street,
            std::string city,
            std::string state,
            uint zip,
            bool suspended
            );
      Member();
      ~Member();

   private:
      bool suspended;
};

#endif
