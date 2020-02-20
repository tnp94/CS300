<<<<<<< HEAD
#include "Service.h"

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
}
=======
#ifndef PROVIDER_MODULE
#define PROVIDER_MODULE

#include "Service.h"
#include "ProviderDirectory.h"

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
};

#endif
>>>>>>> 653d4fedbe6861cab4c7a488d94e73491de48d52
