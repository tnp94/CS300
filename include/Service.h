#ifndef SERVICE_H
#define SERVICE_H

#include <ctime>
#include <string>

class Service {
   public:
      uint get_member_id() const;
      uint get_provider_id() const;
      std::string get_service_name() const;
      uint get_service_code() const;
      time_t get_date_added() const;
      time_t get_service_date() const;
      std::string get_comments() const;
      void set_member_id(uint member_id);
      void set_provider_id(uint provider_id);
      void set_service_name(std::string service_name);
      void set_service_code(uint service_code);
      void set_date_added(time_t date_added);
      void set_service_date(time_t service_date);
      void set_comments(std::string comments);
      void display_info();
      int build();
      Service(
            const uint member_id,
            const uint provider_id,
            const std::string service_name,
            const time_t date_added,
            const time_t service_date,
            const uint service_code,
            const std::string comments
            );
      Service(
            const std::string service_name,
            const uint service_code
            );
      Service();
      ~Service();

   private:
      uint member_id;
      uint provider_id;
      std::string service_name;
      time_t date_added;
      time_t service_date;
      uint service_code;
      std::string comments;
};

#endif
