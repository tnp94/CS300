#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <map>
#include <string>
#include "Service.h"

class ProviderDirectory {
   public:
      int generate_directory();

      ProviderDirectory();
      ~ProviderDirectory();

   private:
      std::map<std::string, uint> services;
};

#endif
