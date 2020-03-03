#ifndef PROVIDER_MODULE
#define PROVIDER_MODULE

#include "Service.h"
#include "ProviderDirectory.h"
#include "Member.h"
#include "Provider.h"
#include <unordered_map>

class ProviderModule{
  public:
      int init(uint providerid);
      int validate_member(uint memberid);
      int provide_service(Service& service);
      int get_provider_directory();
      ProviderModule();
      ~ProviderModule();
  private:
      ProviderDirectory directory;
      uint provider_id;
      std::unordered_map<uint, Member> members;
      std::unordered_map<uint, Provider> providers;

};

#endif
