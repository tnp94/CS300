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
            const uint zip
            );
      //~Member();
      void SetName(std::string name);
      void SetId();
      void SetCity(std::string city);
      void SetState(std::string state);
      void SetZip(uint zip);
   
   private:
      bool suspended;
};

#endif
