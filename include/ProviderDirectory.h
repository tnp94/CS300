#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <map>
#include <string>
#include "Service.h"
#include "Database.h"

class ProviderDirectory: public Database {
   public:
      int generate_directory();
      std::string get_name(uint code);
      uint get_code(std::string name);

      ProviderDirectory();
      ~ProviderDirectory();
};

#endif
