#include "../include/ManagerModule.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

//init() : let user choose which function to use.
int ManagerModule::init() {
  cout << "\n\n\nWelcome to the manager's terminal\n\n";
  int choice = 0, id_number;
  int return_code;
  weekly_report();


  while (choice != 4)
  {
    cout << "What is your purpose?\n\n"
        << "1. Generate Summary Report\n"
        << "2. Generate Provider Report\n"
        << "3. Generate Member report\n"
        << "4. Exit\n";
    cin >> choice;
    switch(choice)
    {
      case 1:
        cout<<"Generate Summary Report\n";
        return_code = summary_report();
        if (!return_code)
        {
          cout << "Summary report failed!\n\n";
        }
        
        break;
      case 2:
        cout << "\nGenerate Provider Report\n\n"
            << "What is the provider number of the provider you want a report for?\n";
            cin >> id_number;
            return_code = provider_report(id_number);
        break;
      case 3:
        cout<<"Generate Member report\n";
        break;
      case 4:
        break;
      default:
        cout << "You did not select a valid response\n\n";
    }
  }

   return 0;
}

//weekly_report(): check the time, if it is Friday, display this week's service.
int ManagerModule::weekly_report() {
  const char *weekday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t curr_time;
    struct tm * curr_timep;
    time(&curr_time);
    bool submitted = false;
    cout<<"The system's time is:"<<endl;
    printf("%s", ctime(&curr_time));
    curr_timep=localtime(&curr_time);
    if (weekday[curr_timep->tm_wday] != "Fri")      //Reset submitted
        submitted = false;
    cout<<"Today is: "<< weekday[curr_timep->tm_wday] << endl;
    if (!submitted) {
        if (strcmp(weekday[curr_timep->tm_wday], "Fri") == 0) {
            //TODO: Check if weekly report has been run today already by attempting to open the projected file name
            // If it opens (inFile.isopen()) then we have already run it today and don't need to run it again.
            cout << "Today is Friday, so the system will display this week's service." << endl;
            time_t tem_time;
            struct tm* tem_timep;
            map<time_t, Service>::iterator iterator;
            iterator = services.begin();
            cout << "All service in this week will be listed: " << endl;
            while (iterator != services.end()) {
                tem_time = iterator->second.get_service_date();
                tem_timep = localtime(&tem_time);
                if (curr_timep->tm_mday > 7) {//this week all in a month
                    if ((curr_timep->tm_year == tem_timep->tm_year) && (curr_timep->tm_mon == tem_timep->tm_mon) &&
                        (curr_timep->tm_mday - tem_timep->tm_mday <= 7)) {
                        cout << "The service's information: " << endl;
                        iterator->second.display_info();
                    }
                }
                else {// this week devided into two months
                    int cur_days = curr_timep->tm_mday;
                    int last_days = 8 - cur_days;
                    int last_mon_days = 0;
                    int year = 1900 + curr_timep->tm_year;
                    switch (curr_timep->tm_mon + 1) {
                    case 1:
                        last_mon_days = 31;
                        break;
                    case 2:
                        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                            last_mon_days = 29;
                        }
                        else
                            last_days = 28;
                        break;
                    case 3:
                        last_mon_days = 31;
                        break;
                    case 4:
                        last_mon_days = 30;
                        break;
                    case 5:
                        last_mon_days = 31;
                    case 6:
                        last_mon_days = 30;
                        break;
                    case 7:
                        last_mon_days = 31;
                        break;
                    case 8:
                        last_mon_days = 31;
                        break;
                    case 9:
                        last_mon_days = 30;
                        break;
                    case 10:
                        last_mon_days = 31;
                        break;
                    case 11:
                        last_mon_days = 30;
                        break;
                    case 12:
                        last_mon_days = 31;
                        break;
                    }
                    if (tem_timep->tm_mon == curr_timep->tm_mon && tem_timep->tm_mday <= cur_days) {
                        cout << "The service's information: " << endl;
                        iterator->second.display_info();
                    }
                    else if (tem_timep->tm_mon == curr_timep->tm_mon - 1 && tem_timep->tm_mday <= last_mon_days - last_days)
                    {
                        cout << "The service's information: " << endl;
                        iterator->second.display_info();
                    }
                }
                iterator++;
            }
            submitted = true;
        }
        else {
            cout << "Today is not Friday, so the system does not need to run a weekly report." << endl;
        }
    }
    else
        cout << "Weekly report has been submitted, please do not repeat it. " << endl;
   return 0;
}

//summary_report(): display all the service in map.
int ManagerModule::summary_report() {
  map<time_t ,Service>::iterator iterator;
    iterator = services.begin();
    cout<<"All service will be listed: "<<endl;
    while(iterator != services.end()){
        cout<<"The service date: "<<endl;
        cout<<iterator->first<<endl;
        cout<<"The service's information: "<<endl;
        iterator->second.display_info();

        iterator++;
   }
   return 0;
}


std::string ManagerModule::person_report(Person& person) {

   std::string a_string;
   return a_string;
}

//provider_report(uint provider_id) : display the service the provider provides.
int ManagerModule::provider_report(uint provider_id) {
  int returnCode = -1;
  unordered_map<uint, Provider>::iterator i = providers.find(provider_id);
  if (i != providers.end())
  {
    //pass report to person_report
    returnCode = 0;
  }
  // Check provider map for provider with provider_id
  // If not found, return -1
  // Else, pass provider to person_report and print return with the rest of the report
  //cout << "Debug: This is provider_report.\n";

   return returnCode;
}


//member_report(uint member_id) : display the service the member owns.
int ManagerModule::member_report(uint member_id) {
  int returnCode = -1;
  unordered_map<uint, Member>::iterator i = members.find(member_id);
  if (i != members.end())
  {
    //pass report to person_report
    
    returnCode = 0;
  }
  // Check member map for member with member_id
  // If not found, return -1
  // Else, pass member to person_report and print return with the rest of the report

   return returnCode;
}

//ManagerModule(): read the data from csv file into map.
ManagerModule::ManagerModule()
{
      char * service_name; // CSV should be in this order
      uint member_id;
      uint provider_id;
      time_t date_added;
      time_t service_date;
      uint service_code;
      char * comments;

  // Initialize services map by reading from the services.csv file
  fstream inFile;
  inFile.open("database/services.csv");
    service_name = new char[1000];
    comments = new char[1000];
  while (inFile.getline(service_name,999))
  {
    inFile >> member_id;
    inFile >> provider_id;
    inFile >> date_added;
    inFile >> service_date;
    inFile >> service_code;
    inFile.ignore();
    inFile.getline(comments, 999);

    //cout << "DEBUG: " << member_id << provider_id << service_name << date_added << service_date << service_code << comments;
    services.insert(make_pair(service_date, Service(member_id, provider_id, service_name, date_added, service_date, service_code,comments)));
    cout << "\n";
  }
  inFile.close();
  delete [] service_name;
  delete [] comments;
}


ManagerModule::~ManagerModule()
{

}
