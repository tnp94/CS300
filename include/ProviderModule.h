#ifndef PROVIDER_MODULE
#define PROVIDER_MODULE

#include "Service.h"
#include "ProviderDirectory.h"
#include "Member.h"
#include "Provider.h"
#include <unordered_map>
#include "Database.h"

class ProviderModule {
   public:
      int init(std::string providerid);
      int write_out();
      int validate_member(std::string memberid);
      int provide_service(Service& service);
      int get_provider_directory();

      ProviderModule();
      ~ProviderModule();

   private:
      ProviderDirectory directory;
      std::string provider_id;
};

#endif
