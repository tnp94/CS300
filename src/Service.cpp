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

int Service::build(string prov_id) {
    uint serv_code;
    char ans = 'N';
    string serv_name, comm, mem_id;
    time_t added,serv_d;
    struct tm ser;

    cout<<"What is the member ID?\n";
    cin>> mem_id;
    cin.ignore(INT_MAX,'\n');

    cout<<"What is the service name?\n";
    cin >> serv_name;
    cin.ignore(INT_MAX,'\n');
    
    cout<<"What is the service code?\n";
    cin>> serv_code;
    cin.ignore(INT_MAX,'\n');

    cout<<"What are the comments?\n";
    cin >> comm;
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
    cin >> ans;
    cin.ignore(INT_MAX,'\n');

    if(ans == 'N')
        return -1;

    Service(mem_id, prov_id, serv_name, added, serv_d, serv_code, comm);

return 0;
}

string Service::to_csv() {
   return string(" ");
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
