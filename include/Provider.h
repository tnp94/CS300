#ifndef PROVIDER_H
#define PROVIDER_H

#include "Person.h"
#include <string>

class Provider : public Person {
   public:
      void display_info();

      Provider(
            std::string name,
            std::string id,
            std::string city,
            std::string state,
            uint zip
            );
      Provider();
      ~Provider();
};
#endif
