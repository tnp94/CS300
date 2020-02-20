#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
   public:
      std::string get_name();
      std::string get_city();
      std::string get_state();
      uint get_zip();
      uint get_id();

      Person(
         const std::string name,
         const uint id,
         const std::string city,
         const std::string state,
         const uint zip
      );

      ~Person();
   private:
      std::string name;
      std::string city;
      std::string state;
      uint id;
      uint zip;
};

#endif
