#include "../include/Service.h"
#include <iostream>
#include <climits>
#include <cstring>
#include "../include/Database.h"

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
   uint serv_code = -1;
   char ans = 'N';
   string serv_name = " ";
   string comm = " ";
   string mem_id = " ";
   time_t added = 0;
   time_t serv_d = 0;
   struct tm ser;
   fee = -1.0;

   do {
   cout<<"What is the member ID?\n";
   cin>> mem_id;
   cin.ignore(INT_MAX,'\n');
   if (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Invalid input...\n\n";
   }
   } while(1);

   bool good_code = false;
   do {
      cout<<"What is the service code?\n";
      cin>> serv_code;
      cin.ignore(INT_MAX,'\n');
      if (cin.fail()) {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         cout << "Invalid input...\n\n";
      }
      auto serv_i = data.service_codes.find(serv_code);

      if(serv_i == data.service_codes.end())
         cout << "thats not a valid code\n";
      else {
         good_code = true;
         serv_name = serv_i -> second;
      }
   } while(!good_code);

   cout<<"What are the comments?\n";
   cin >> comm;
   cin.ignore(INT_MAX,'\n');
   if (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Invalid input...\n\n";
   }

   added= time(0);

   cout<<"What was the year the service was provided?\n";
   cin>> ser.tm_year;
   cin.ignore(INT_MAX,'\n');
   if (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Invalid input...\n\n";
   }

   ser.tm_year-=1900;

   cout<<"What was the month the service was provided?\n";
   cin>> ser.tm_mon;
   cin.ignore(INT_MAX,'\n');
   if (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Invalid input...\n\n";
   }
   ser.tm_mon-=1;

   cout<<"What was the day the service was provided?\n";
   cin>> ser.tm_mday;
   cin.ignore(INT_MAX,'\n');
   if (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Invalid input...\n\n";
   }

   ser.tm_hour=0;
   ser.tm_min=0;
   ser.tm_sec=0;
   ser.tm_wday=0;
   ser.tm_yday=0;
   ser.tm_isdst=0;
   serv_d=mktime(&ser);

   do {
      cout << "What is the fee for this service?\n";
      cin >> fee;
      cin.ignore(INT_MAX,'\n');
      cin.clear();
   } while(fee < 0 || fee > 999.99);

   cout<<"Member ID: "<<mem_id<<"\n"
      <<"Service Name: "<<serv_name<<"\n"
      <<"Service Code: \n"
      <<"Comments: "<<comm<<"\n"
      <<"Service Added: "<<ctime(&added)<<"\n"
      <<"Service Provided: "<<ctime(&serv_d)<<"\n"
      <<"Fee: " << fee << "\n";
   cout<<"Is this correct? (Y/N)";

   cin >> ans;
   cin.ignore(INT_MAX,'\n');

   if (cin.fail()) {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      cout << "Invalid input...\n\n";
   } else if(ans == 'N')
      return -1;

   Service(mem_id, prov_id, serv_name, added, serv_d, serv_code, comm, fee);
   return 0;
}

string Service::to_csv() {
   return member_id + "|" + provider_id + "|" + to_string(date_added) + "|" + to_string(service_date) + "|" + to_string(service_code) + "|" + comments;
}

string Service::member_report() {
   return string(ctime(&service_date))
      + data.providers.find(provider_id) -> second.get_name()
      + "\t\t" + data.service_codes.find(service_code) -> second;
}

string Service::provider_report() {
   string report = "Date of service: ";
   report += ctime(&service_date);
   report += "\nDate received: ";
   report += ctime(&date_added);
   report += "\nMember name: " + data.members.find(member_id) -> second.get_name();
   report += "\nMember ID: " + member_id;
   report += "\nService code: " + to_string(service_code);
   report += "\nFee: " + to_string(fee);

   return report;
}

float Service::get_fee() {
   return fee;
}

string Service::get_member() {
   return member_id;
}

string Service::get_provider() {
   return provider_id;
}

Service::Service(string member_id, string provider_id, std::string service_name, time_t date_added, time_t service_date, uint service_code, std::string comments, float fee) {
   this->member_id    = member_id;
   this->provider_id  = provider_id;
   this->date_added   = date_added;
   this->service_date = service_date;
   this->service_code = service_code;
   this->comments     = comments;
   this->fee          = fee;
}

time_t Service::get_service_date() {
   return service_date;
}

Service::Service() { }


Service::~Service() { }
