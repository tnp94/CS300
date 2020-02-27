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

void Service::set_member_id(uint member_id){
   this->member_id=member_id;
}

void Service::set_provider_id(uint provider_id){
   this->provider_id=provider_id;
}

void Service::set_date_added(time_t date_added){
   this->date_added=date_added;
}

void Service::set_service_date(time_t service_date){
   this->service_date=service_date;
}

void Service::set_service_code(uint service_code){
   this->service_code=service_code;
}

void Service::set_comments(std::string comments){
   this->comments=comments;
}

int Service::build(){

return 0;
}

Service::Service(const uint member_id, const uint provider_id, const std::string service_name, const time_t date_added, const time_t service_date, const uint service_code, const std::string comments)
{
   this->member_id=member_id;
   this->provider_id=provider_id;
   this->date_added=date_added;
   this->service_date=service_date;
   this->service_code=service_code;
   this->comments=comments;
}

Service::Service()
{


}
Service::~Service()
{

}

