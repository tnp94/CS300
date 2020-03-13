#ifndef SERVICE_H
#define SERVICE_H

#include <ctime>
#include <string>
#include <map>
#include <unordered_map>
#include "Database.h"

class Service {
   public:
      void display_info();
      int build(std::string prov_id);
      std::string to_csv();
      time_t get_service_date();
      std::string member_report();
      std::string provider_report();
      std::string get_member();
      std::string get_provider();
      float get_fee();

      Service(
            std::string member_id,
            std::string provider_id,
            std::string service_name,
            time_t date_added,
            time_t service_date,
            uint service_code,
            std::string comments,
            float fee
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
      float fee;
};

#endif
