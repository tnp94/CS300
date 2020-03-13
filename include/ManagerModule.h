#ifndef MANAGER_MODULE
#define MANAGER_MODULE

#include "Person.h"
#include "Provider.h"
#include "Member.h"
#include "Service.h"
#include <map>
#include <unordered_map>
#include <string>
#include "Database.h"

class ManagerModule {

   public:
      int init();

      ManagerModule();
      ~ManagerModule();

   private:
      int summary_report();
      int provider_report(std::string provider_id);
      int member_report(std::string provider_id);
};

#endif
