#include "../include/Service.h"
#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

void Service::display_info() {
   cout << "The member id is: "
      << member_id << "\n"
      << "The provider id is: "
      << provider_id << "\n"
      << "The date when this service added: "
      << ctime(&date_added)
      << "The date when this service is done: "
      << ctime(&service_date)
      << "The service code: "
      << service_code << "\n"
      << "The user's comments: "
      << comments << "\n";
}

int Service::build(uint prov_id) {
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
    Service(mem_id,prov_id,serv_name,added, serv_d, serv_code, comm);

return 0;
}

Service::Service( string member_id,  string provider_id,  std::string service_name,  time_t date_added,  time_t service_date,  uint service_code,  std::string comments) {
   this->member_id    = member_id;
   this->provider_id  = provider_id;
   this->date_added   = date_added;
   this->service_date = service_date;
   this->service_code = service_code;
   this->comments     = comments;
}

Service::Service() { }

Service::~Service() { }
