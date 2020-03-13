#ifndef DATBASE_H
#define DATABASE_H

#include <unordered_map>
#include <iostream>
#include <ctime>
#include <string>

struct person_data {
   char name[1000];
   char id[10];
   char city[1000];
   char state[1000];
   uint zip;
}

// helper class to load data into working memory
class Database {
   public:
      Databse();
      ~Database();

      void members(std::unordered_map<std::string, Member>& map);
      void providers(std::unordered_map<std::string, Provider>& map);
      void services(std::map<time_t, Service>& map);
      void service_info(std::map<std::std::string, uint>& map);

      void write_members(std::unordered_map<std::string, Member>& map);
      void write_providers(std::unordered_map<std::string, Provider>& map);
      void write_services(std::map<time_t, Service>& map);

   private:
      void read_person(std::istream &file, person_data& result);
}
#endif
