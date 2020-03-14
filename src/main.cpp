#include "../include/ProviderModule.h"
#include "../include/ManagerModule.h"
#include "../include/InteractiveModule.h"
#include "../include/test.h"
#include <iostream>
#include <climits>

using namespace std;
#ifdef TEST
int main() {
   cout << "Running tests.....\n\n";

   int failed = 13;

   failed += valid_login_provider();
   failed += invalid_login_provider();
   failed += valid_verify_member();
   failed += invalid_verify_member();
   failed += search_valid_provider();
   failed += search_invalid_provider();
   failed += remove_valid_provider();
   failed += remove_valid_member();
   failed += remove_invalid_provider();
   failed += remove_invalid_member();
   failed += add_valid_provider();
   failed += add_valid_member();
   failed += provide_service();

   if(failed)
      cout << "\n\nALL TESTS PASS\n\n";
   else
      cout << failed << " tests failed.";

   return 0;
}
#else
int main() {
   int choice = 0;
   string id = "0";
   ProviderModule provider_module;
   ManagerModule manager_module;
   InteractiveModule interactive_module;

   cout << "Welcome to the ChocAn application!\n\n";

   while (choice != 4) {
      cout << "\n\nWhat terminal would you like to log into?\n"
         << "1. Provider Module\n"
         << "2. Manager Module\n"
         << "3. Database Interactive Module\n"
         << "4. Exit\n";

      cin >> choice;
      cin.ignore(INT_MAX, '\n');

      switch (choice) {
         case 1: // Provider Module
            cout << "You selected provider module.\n";
            cout << "Please input your provider number: ";
            cin >> id;
            cin.ignore(INT_MAX, '\n');
            if (!cin.fail()) {
               cout << "Opening provider module\n";
               if (provider_module.init(id) == -1) {
                  cout << "Provider with id " << id << " not found\n";
               }
            } else {
               cout << "Invalid input\n\n";
               cin.clear();
               cin.ignore(INT_MAX, '\n');
            }
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
            cout << "\n\n\nThanks for playing!\n\n";
            return 0;

         default:
            choice = 0;
            if (cin.fail()) {
              cin.clear();
              cin.ignore(INT_MAX, '\n');
            }
            cout << "You did not select a valid response\n\n";
      }
   }
   return 0;
}
#endif
