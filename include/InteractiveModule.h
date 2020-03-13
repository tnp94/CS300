#ifndef INTERACTIVEMODULE_H
#define INTERACTIVEMODULE_H

#include <unordered_map>
#include "Member.h"
#include "Provider.h"

class InteractiveModule {

   public:
      int init();

      InteractiveModule();
      ~InteractiveModule();

   private:
      int add_person();
      int edit_person(string id, std::unordered_map<string, Person> map);
      int remove_person(string id, std::unordered_map<string, Person> map);
      int display_person(string id, std::unordered_map<string, Person> map);
      int add_person(std::unordered_map<string, Person> map);
      int write_out();

      std::unordered_map<std::string, Member> members;
      std::unordered_map<std::string, Provider> providers;
};

#endif
