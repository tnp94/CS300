#ifndef PROVIDER_MODULE
#define PROVIDER_MODULE

#include "Service.h"
#include "ProviderDirectory.h"
#include "Member.h"
#include "Provider.h"
#include <unordered_map>

class ProviderModule{
  public:
      int init(string providerid);

      ProviderModule();
      ~ProviderModule();

  private:
      int write_out()
      int validate_member(std::string memberid);
      int provide_service(Service& service);
      int get_provider_directory();

      ProviderDirectory directory;
      std::string provider_id;
      std::unordered_map<std::string, Member> members;
      std::unordered_map<std::string, Provider> providers;
};

#endif
