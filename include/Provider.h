#ifndef PROVIDER_H
#define PROVIDER_H

#include "Person.h"
#include <String>

class Provider : public Person {
   public:
   Provider(
      const std::String name,
      const uint id,
      const std::String city,
      const std::String state,
      const uint zip
   );

   ~Provider();
   private:
};
#endif