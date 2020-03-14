#include "../include/ManagerModule.h"
#include "../include/Database.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <iomanip>

using namespace std;

//init() : let user choose which function to use.
int ManagerModule::init() {
   setprecision(2);
   cout << "\n\n\nWelcome to the manager's terminal\n\n";
   int choice = 0;
   string id_number;

   while (choice != 4) {
      cout << "\n\n\nWhat is your purpose?\n\n"
         << "1. Generate Summary Report\n"
         << "2. Generate Provider Report\n"
         << "3. Generate Member report\n"
         << "4. Exit\n";
      cin >> choice;
      cin.ignore(INT_MAX, '\n');

      switch(choice) {
         case 1:
            cout<<"\nGenerate Summary Report\n";
            if(summary_report())
               cout << "Summary report failed!\n\n";
            break;

         case 2:
            cout << "\nGenerate Provider Report\n\n"
               << "What is the provider number of the provider you want a report for?\n";
            cin >> id_number;
            cin.ignore(INT_MAX, '\n');

            if(cin.fail()) {
               cin.clear();
               cin.ignore(INT_MAX, '\n');
            } else if(provider_report(id_number))
               cout << "Provider report failed!\n\n";
            break;

         case 3:
            cout<<"\nGenerate Member report\n\n"
               << "What is the member number of the member you want a report for?\n";
            cin >> id_number;
            cin.ignore(INT_MAX, '\n');

            if(cin.fail()) {
               cin.clear();
               cin.ignore(INT_MAX, '\n');
            } else if(member_report(id_number))
               cout << "Member report failed!\n\n";
            break;

         case 4:
            return 0;

         default:
            cout << "You did not select a valid response\n\n";
            if(cin.fail()) {
               cin.clear();
               cin.ignore(INT_MAX, '\n');
            }
      }
   }
   return 0;
}

//summary_report(): display all the service in map.
int ManagerModule::summary_report() {
   time_t last_week = time(NULL) - 604800;
   int num_providers = 0;

   struct Total {
      int service_count;
      float total_billing;
   };

   unordered_map<string, Total> provider_totals;

   auto si = data.services.lower_bound(last_week);
   while(si != data.services.end()) {
      string provider = data.providers.find(si -> second.get_provider()) -> second.get_name();
      float fee = si -> second.get_fee();
      cout << fee << endl;
      auto provider_total = provider_totals.find(provider);

      if(provider_total == provider_totals.end()) {
         Total new_total;
         new_total.service_count = 1;
         new_total.total_billing = fee;
         provider_totals.insert(pair<string, Total>(provider, new_total));
         ++num_providers;
      } else {
         provider_total -> second.service_count += 1;
         provider_total -> second.total_billing += fee;
      }
      ++si;
   }

   auto totals = provider_totals.begin();
   while(totals != provider_totals.end()) {
      cout << "\n\n\nProvider: " << totals -> first
         << "\n Total fees: " << totals -> second.total_billing
         << "\n Services provided: " << totals -> second.service_count;
      ++totals;
   }

   return 0;
}


//provider_report(uint provider_id) : display the service the provider provides.
int ManagerModule::provider_report(string provider_id) {
   time_t last_week = time(NULL) - 604800;
   auto i = data.providers.find(provider_id);
   if(i == data.providers.end()) {
      cout << "Provider not found\n";
      return -1;
   }

   float total_billing = 0;
   int num_consults = 0;

   cout << i -> second.report() << "\n\n" << "services: \n\n";
   
   auto si = data.services.lower_bound(last_week);
   while(si != data.services.end()) {
      if(si -> second.get_member() == provider_id) {
         cout << si -> second.provider_report() << "\n\n";
         total_billing += si -> second.get_fee();
         ++num_consults;
      }
      ++si;
   }
   
   cout << "\n\n Total fees: " << total_billing;
   cout << "\n\n Number of consultations: " << num_consults;
   return 0;
}


//member_report(uint member_id) : display the service the member owns.
int ManagerModule::member_report(string member_id) {
   time_t last_week = time(NULL) - 604800;
   auto i = data.members.find(member_id);
   if(i == data.members.end()) {
      cout << "Member not found\n";
      return -1;
   }

   cout << i -> second.report() << "\n\n" << "services: \n\n";
   
   auto si = data.services.lower_bound(last_week);
   while(si != data.services.end()) {
      if(si -> second.get_member() == member_id)
         cout << si -> second.member_report() << "\n\n";
      ++si;
   }
   
   return 0;
}

ManagerModule::ManagerModule() { }

ManagerModule::~ManagerModule() { }
