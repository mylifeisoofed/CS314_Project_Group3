#include "table.h"

void provider_terminal();
void manager_terminal();

int main() {
  Table<Member> MembersList;
  char choice[10];

  Member my_member("John Doe", "503123456", "123 NE Geek St", "Oregon", "12345",
                   "517040", true, "PSU Student");

  Member my_member2("John Dane", "503123456", "123 NE Geek St", "Oregon",
                    "12345", "51432", true, "PSU Student");

  MembersList.add(my_member);
  MembersList.add(my_member2);
  MembersList.remove("51432", "John Dane");
  MembersList.find("51432", "John Dane");
  MembersList.find("517040", "John Doe");
  // test.remove("517040", "John Doe");
  // test.display();

  // Display appropriate terminal
  do {
    cout << "Are you a Provider or a Manager? ";
    cin >> choice;
    cout << endl;
    if (strcasecmp(choice, "provider") == 0 || strcasecmp(choice, "p") == 0) {
      provider_terminal();
    } else if (strcasecmp(choice, "manager") == 0 ||
               strcasecmp(choice, "m") == 0) {
      manager_terminal();
    } else {
      cout << "Invalid choice. Please try again.\n";
    }
  } while (strcasecmp(choice, "provider") != 0 &&
           strcasecmp(choice, "p") != 0 && strcasecmp(choice, "manager") != 0 &&
           strcasecmp(choice, "m") != 0);

  return 0;
}