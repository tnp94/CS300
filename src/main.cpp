#include "../include/ProviderModule.h"
#include "../include/ManagerModule.h"
#include "../include/InteractiveModule.h"
#include <iostream>

using namespace std;

int main() {
   int choice;
   int id = 0;
   ProviderModule provider_module;
   ManagerModule manager_module;
   InteractiveModule interactive_module;

   cout << "Welcome to the ChocAn application!\n\n";

   while (choice != 4)
   {
      cout << "\n\nWhat terminal would you like to log into?\n"
         << "1. Provider Module\n"
         << "2. Manager Module\n"
         << "3. Database Interactive Module\n"
         << "4. Exit\n";
      
      cin >> choice;

      switch (choice)
      {
         case 1: // Provider Module
            cout << "You selected provider module.\n";
            cout << "Please input your provider number: ";
            cin >> id;
            cout << "Opening provider module\n";
            provider_module.init(id);
            break;
         case 2: // Manager Module
            cout << "You selected manager module.\n"
            << "Opening manager module\n";
            manager_module.init();
            break;
         case 3: // Interactive Module
            cout << "You selected database interactive module.\n"
            << "Opening database interactive module\n";
            interactive_module.init();
            break;
         case 4: // Exit
            break;
         default:
            cout << "You did not select a valid response\n\n";
      }
   }
   cout << "\n\n\nThanks for playing!\n\n";

   return 0;
}
