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
      string GetName();
      void SetName(std::string name);
      uint GetId();
      void SetId();
      string GetCity();
      void SetCity(std::string city);
      string GetState();
      void SetState(std::string state);
      uint GetZip();
      void SetZip(uint zip);
   
   private:
      bool suspended;
};

#endif
