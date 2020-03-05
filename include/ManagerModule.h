#ifndef MANAGER_MODULE
#define MANAGER_MODULE

#include "Person.h"
#include "Provider.h"
#include "Member.h"
#include "Service.h"
#include <map>
#include <unordered_map>
#include <string>


class ManagerModule {
   public:
      int init();
      int weekly_report();
      int summary_report();
      std::string person_report(Person& person);
      int provider_report(uint provider_id);
      int member_report(uint provider_id);

      ManagerModule();
      ~ManagerModule();

   private:

      std::map<time_t, Service> services;
      std::unordered_map<uint, Provider> providers;
      std::unordered_map<uint, Member> members;
};

#endif
