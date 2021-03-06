#ifndef DATABASE_H
#define DATABASE_H

#include "Service.h"
#include "Provider.h"
#include "Member.h"
#include <unordered_map>
#include <map>
#include <iostream>
#include <ctime>
#include <string>

struct person_data {
   char name[25];
   char street[36];
   char id[10];
   char city[15];
   char state[3];
   uint zip;
};

class Service;

// helper class to load data into working memory
extern struct Database {
   public:
      Database();
      ~Database();

      void read_members();
      void read_providers();
      void read_services();
      void read_service_info();

      void write_members();
      void write_providers();
      void write_services();

      void read_person(std::istream &file, person_data& result);

      std::map<time_t, Service> services;
      std::map<uint, std::string> service_codes;
      std::map<std::string, uint> service_names;
      std::unordered_map<std::string, Provider> providers;
      std::unordered_map<std::string, Member> members;
} data;
#endif
