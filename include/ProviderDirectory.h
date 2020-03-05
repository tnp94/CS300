#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <map>
#include <string>
#include "Service.h"

class ProviderDirectory {
   public:
      int generate_directory();
   private:
      std::map<std::string, Service> services;
};

#endif
