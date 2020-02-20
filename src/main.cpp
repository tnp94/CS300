#include "../include/ProviderModule.h"
#include "../include/ManagerModule.h"
#include "../include/InteractiveModule.h"
#include <iostream>

using namespace std;

int main() {
   int choice;
   cout << "Welcome to the ChocAn application!\n\n";

   while (choice != 4)
   {
      cout << "What terminal would you like to log into?\n"
         << "1. Provider Module\n"
         << "2. Manager Module\n"
         << "3. Database Interactive Module\n"
         << "4. Exit";
      
      cin >> choice;

      switch (choice)
      {
         case 1: // Provider Module
            cout << "You selected provider module.\n"
            << "Opening provider module\n";
            break;
         case 2: // Manager Module
            cout << "You selected manager module.\n"
            << "Opening manager module\n";
            break;
         case 3: // Interactive Module
            cout << "You selected database interactive module.\n"
            << "Opening database interactive module\n";
            break;
         case 4: // Exit
            break;
         default:
            cout << "You did not select a valid response\n\n";
      }
   }

   return 0;
}
