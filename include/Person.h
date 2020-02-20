#ifndef PERSON_H
#define PERSON_H

#include <String>

class Person {
   public:
      std::String get_name();
      std::String get_city();
      std::String get_state();
      uint get_zip();
      uint get_id();

      Person(
         const std::String name,
         const uint id,
         const std::String city,
         const std::String state,
         const uint zip
      );

      ~Person();
   private:
      std::String name;
      std::String city;
      std::String state;
      uint id;
      uint zip;
};

#endif