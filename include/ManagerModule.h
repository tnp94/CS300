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

      ManagerModule();
      ~ManagerModule();

   private:
      int weekly_report();
      int summary_report();
      std::string person_report(Person& person);
      int provider_report(uint provider_id);
      int member_report(uint provider_id);

      std::map<time_t, Service> services;
      std::unordered_map<std::string, Provider> providers;
      std::unordered_map<std::string, Member> members;
};

#endif
