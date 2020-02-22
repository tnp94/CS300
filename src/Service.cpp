#include "../include/Service.h"

uint Service::get_member_id() const {
   
   return 0;
}

uint Service::get_provider_id() const {

   return 0;
}

uint Service::get_service_code() const {

   return 0;
}

time_t Service::get_date_added() const {

   return 0;
}

time_t Service::get_service_date() const {

   return 0;
}

std::string Service::get_comments() const {

   std::string a_string;
   return a_string;
}

Service::Service(const uint member_id, const uint provider_id, const time_t date_added, const time_t service_date, const uint service_code, const std::string comment)
{

}

Service::~Service()
{

}

