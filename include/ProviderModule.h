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
