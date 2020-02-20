#ifndef PROVIDER_H
#define PROVIDER_H

#include "Person.h"
#include <string>

class Provider : public Person {
   public:
   Provider(
      const std::string name,
      const uint id,
      const std::string city,
      const std::string state,
      const uint zip
   );

    whats wrong();
   ~Provider();
   private:

};
#endif
