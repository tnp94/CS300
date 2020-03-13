#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <map>
#include <string>
#include "Service.h"

class ProviderDirectory {
   public:
      int generate_directory();
      std::string get_name(uint code);
      uint get_code(std::string name);

      ProviderDirectory();
      ~ProviderDirectory();

   private:
      std::map<std::string, uint> service_names;
      std::map<uint, std::string> service_codes;
};

#endif
