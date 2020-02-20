#ifndef PROVIDERDIRECTORY_H
#define PROVIDERDIRECTORY_H

#include <map>
#include "Service.h"

class ProviderDirectory {
   public:
      int generateDirectory();
   private:
      map<service, uint> services;
}

#endif