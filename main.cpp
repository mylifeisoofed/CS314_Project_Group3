#include "person_class.h"

int main() {
  Table<Member> test;

  Member my_member("John Doe", "503123456", "123 NE Geek St", "Oregon", "12345",
                   "517040", true, "PSU Student");

  my_member.display();

  return 0;
}