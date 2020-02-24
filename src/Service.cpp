#include "../include/Service.h"

uint Service::get_member_id() const {
   return this->member_id;
}

uint Service::get_provider_id() const {
   return this->provider_id;
}

uint Service::get_service_code() const {
   return this->service_code;
}

time_t Service::get_date_added() const {
   return this->date_added;
}

time_t Service::get_service_date() const {
   return this->service_date;
}

std::string Service::get_comments() const {
   return this->comments;
}

Service::Service(const uint member_id, const uint provider_id, const time_t date_added, const time_t service_date, const uint service_code, const std::string comment)
{
   this->member_id=member_id;
   this->provider_id=provider_id;
   this->date_added=date_added;
   this->service_date=service_date;
   this->service_code=service_code;
   this->comments=comments;
}

Service::~Service()
{

}

