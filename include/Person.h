#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
   public:
      void set_name(std::string name);
      void set_id(std::string id);
      void set_city(std::string city);
      void set_state(std::string state);
      void set_zip(uint zip);
      void display_info();
      std::string to_csv();

      Person(
            std::string name,
            std::string id,
            std::string city,
            std::string state,
            uint zip
            );
      Person();
      virtual ~Person();

   private:
      std::string name;
      std::string city;
      std::string state;
      std::string id;
      uint zip;
};

#endif
