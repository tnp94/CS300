#include "Person.h"
#include <string>

class Member: public Person{

   public:
      Member(
            const std::string name,
            const uint member_id,
            const std::string city,
            const std::string state,
            const uint zip
            );
      ~member();

   private:
      bool suspended;
}
