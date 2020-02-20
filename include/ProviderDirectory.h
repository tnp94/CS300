#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <map>
#include "Service.h"

class ProviderDirectory {
   public:
      int generate_directory();
   private:
      std::map<Service, uint> services;
};

#endif
