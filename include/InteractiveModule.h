#ifndef INTERACTIVEMODULE_H
#define INTERACTIVEMODULE_H

#include <unordered_map>
#include "Member.h"
#include "Provider.h"
#include "Database.h"

enum PersonType {
   PROVIDER,
   MEMBER
};

class InteractiveModule {

   public:
      int init();
      int edit_person(std::string id, PersonType);
      int remove_person(std::string id, PersonType);
      int display_person(std::string id, PersonType);
      int add_person(Person*, PersonType);
      int write_out();
      bool id_is_valid(std::string id);

      InteractiveModule();
      ~InteractiveModule();
};

#endif
