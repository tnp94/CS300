#include "../include/Service.h"
#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

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

std::string Service::get_service_name() const {
   return this->service_name;
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

void Service::display_info(){
   cout<<"The member id is: "<<this->get_member_id()<<endl;
   cout<<"The provider id is: "<<this->get_provider_id()<<endl;
   cout<<"The date when this service added: "<<this->get_date_added()<<endl;
   cout<<"The date when this service is done: "<<this->get_service_date()<<endl;
   cout<<"The service code: "<<this->get_service_code()<<endl;
   cout<<"The user's comments: "<<this->get_comments()<<endl;
}
int Service::build(uint prov_id){

    uint mem_id, serv_code;
    char *ans, *serv_name, *comm;
    time_t added,serv_d;
    struct tm ser;

    ans=new char[5];
    serv_name=new char[86];
    comm=new char[601];

    cout<<"What is the member ID?\n";
    cin>> mem_id;
    cin.ignore(INT_MAX,'\n');

    cout<<"What is the service name?\n";
    cin.get(serv_name,85,'\n');
    cin.ignore(INT_MAX,'\n');
    
    cout<<"What is the service code?\n";
    cin>> serv_code;
    cin.ignore(INT_MAX,'\n');

    cout<<"What are the comments?\n";
    cin.get(comm,600,'\n');
    cin.ignore(INT_MAX,'\n');

    added= time(0);

    cout<<"What was the year the service was provided?\n";
    cin>> ser.tm_year;
    cin.ignore(INT_MAX,'\n');
    ser.tm_year-=1900;

    cout<<"What was the month the service was provided?\n";
    cin>> ser.tm_mon;
    cin.ignore(INT_MAX,'\n');
    ser.tm_mon-=1;
    
    cout<<"What was the day the service was provided?\n";
    cin>> ser.tm_mday;
    cin.ignore(INT_MAX,'\n');
   
    ser.tm_hour=0;
    ser.tm_min=0;
    ser.tm_sec=0;
    ser.tm_wday=0;
    ser.tm_yday=0;
    ser.tm_isdst=0;
    serv_d=mktime(&ser);
    
    cout<<"Member ID: "<<mem_id<<"\n"
        <<"Service Name: "<<serv_name<<"\n"
        <<"Service Code: "<<serv_code<<"\n"
        <<"Comments: "<<comm<<"\n"
        <<"Service Added: "<<ctime(&added)<<"\n"
        <<"Service Provided: "<<ctime(&serv_d)<<"\n";
    cout<<"Is this correct? (Y/N)";
    cin.get(ans,5,'\n');
    cin.ignore(INT_MAX,'\n');
    if(strcpy(ans,"N"))
        return -1;

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

