#include <unordered_map>
#include "Member.h"
#include "Provider.h"

class InteractiveModule {

   public:
      int init();
      int display_member(uint member_id);
      int add_member();
      int remove_member(uint member_id);
      int display_member(uint member_id);
      int add_provider(uint provider_id);
      int remove_provider(uint provider_id);
      int display_provider(uint provider_id);
      int write_out();

      InteractiveModule();
      ~InteractiveModule();

   private:
      unordered_map<uint, Member> members;
      unordered_map<uint, Provider> providers;

};
