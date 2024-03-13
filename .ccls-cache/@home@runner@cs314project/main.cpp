#include "menu.h"
#include "table.h"

int main() {
  Table<Member> MembersList;
  Table<Provider> ProvidersList;
  char choice[10];

  /* testing the classes and hash table
  Member my_member("John Doe", "503123456", "123 NE Geek St", "Oregon", "12345",
                   "517040", true, "PSU Student");

  Member my_member2("John Dane", "503123456", "123 NE Geek St", "Oregon",
                    "12345", "51432", true, "OSU Student");

  Provider my_provider("John Doe", "503123456", "123 NE Geek St", "Oregon",
                       "12345", "517040", 3.00, "142345");

  MembersList.add(my_member);
  MembersList.add(my_member2);
  MembersList.save(MEMBER_FILE);
  // MembersList.remove("51432", "John Dane");
  // MembersList.find("51432", "John Dane");
  // MembersList.find("517040", "John Doe");

  ProvidersList.add(my_provider);
  ProvidersList.save(PROVIDER_FILE);
  // test.remove("517040", "John Doe");
  // test.display();

  Table<Member> membertest;
  membertest.load_member(MEMBER_FILE);
  // membertest.display();

  Table<Provider> providertest;
  providertest.load_provider(PROVIDER_FILE);
  providertest.display();
  */
  // Display appropriate terminal
  while (true) {
    cout << "Are you a Provider or a Manager?: ";
    cin >> choice;
    cout << endl;
    if (strcasecmp(choice, "provider") == 0 || strcasecmp(choice, "p") == 0) {
      provider_terminal(MembersList, ProvidersList);
      break;
    } else if (strcasecmp(choice, "manager") == 0 ||
               strcasecmp(choice, "m") == 0) {
      manager_terminal();
      break;
    } else {
      cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}