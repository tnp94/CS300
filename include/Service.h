#ifndef SERVICE_H
#define SERVICE_H

#include <ctime>
#include <string>

class Service {
   public:
      void display_info();
      int build(std::string prov_id);
      std::string to_csv();

      Service(
             std::string member_id,
             std::string provider_id,
             std::string service_name,
             time_t date_added,
             time_t service_date,
             uint service_code,
             std::string comments
            );
      Service();
      ~Service();

   private:
      std::string member_id;
      std::string provider_id;
      std::string service_name;
      time_t date_added;
      time_t service_date;
      uint service_code;
      std::string comments;
};

#endif
