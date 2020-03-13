#include "../include/ProviderModule.h"
#include "../include/Database.h"
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
#include <fstream>
#include "../include/Member.h"

using namespace std;

int ProviderModule::init(string id) {
   if (data.providers.find(id) == data.providers.end())
      return -1;

   cout << "\n\n\nWelcome to the Provider terminal\n\n";
   int choice = 0;
   string sel="0";

   while (choice != 4)
   {
      cout << "\n\n\nWhat is your purpose?\n\n"
         << "1. Validate Member\n"
         << "2. Provide Service\n"
         << "3. Provider directory\n"
         << "4. Exit\n";
      cin >> choice;
      cout << "\n\n";
      switch(choice)
      {
         case 1: {
                    int isSuspended;
                    cout << "What is the member ID you wish to validate?\n";
                    if (cin.fail()) {
                       fflush(stdin);
                       cin.clear();
                       cout << "Invalid input...\n\n";
                    } else {
                       cin >> sel;
                    }
                    isSuspended = validate_member(sel);
                    if (isSuspended == 1) {
                       cout << "Member ID " << sel << " status: SUSPENDED\n";
                    } else if (isSuspended == 0) {
                       cout << "Member ID " << sel << " status: VALID\n";
                    } else if (isSuspended < 0) {
                       cout << "Member ID " << sel << " not found\n";
                    }
                    break;
                 }

         case 2: {
                    Service new_service;
                    if (new_service.build(id))
                       provide_service(new_service);   
                    break;
                 }
         case 3: {
                    get_provider_directory();
                    break;
                 }
         case 4: {
                    data.write_services();
                    return 0;
                 }

         default: {
                     cin.clear();
                     fflush(stdin);
                     cout << "You did not select a valid response\n\n";
                  }
      }
   }

   return 0;
}

int ProviderModule::validate_member(string id) {
   int returnCode = -1;
   unordered_map<string, Member>::iterator i = data.members.find(id);
   if (i != data.members.end())
   {
      returnCode = i->second.get_suspended();
   }

   return returnCode;
}

int ProviderModule::provide_service(Service& service) {
   data.services.insert(make_pair(service.get_service_date(), service));
   return 0;
}

int ProviderModule::get_provider_directory() {
   directory.generate_directory();
   return 0;
}

ProviderModule::ProviderModule() { }

ProviderModule::~ProviderModule() { }
