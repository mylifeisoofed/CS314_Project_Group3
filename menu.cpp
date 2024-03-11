#include "class.h"

void provider_terminal() {
  string provider_id;
  string member_id;

  cout << ">>> Provider Terminal <<<\n\n";

  cout << "Enter your provider ID: ";
  cin >> provider_id;
  cout << "\n";

  // TODO: Determine validity of prov. ID

  cout << "Enter member ID: ";
  cin >> member_id;
  cout << "\n";

  // TODO: Determine validity of member ID

  return;
}

void manager_terminal() {
  short report_code = 0;
  cout << ">>> Manager Terminal <<<\n\n";

  while (report_code != 1 && report_code != 2 && report_code != 3) {
    cout << "Which report would you like to run? Enter a report code:\n"
         << "\t1: Member report\n\t2: Provider report\n\t3: Summary report\n";
    cin >> report_code;
    cout << endl;
    if (report_code != 1 && report_code != 2 && report_code != 3) {
      cout << "Invalid report code. Please try again.\n\n";
    }
  }

  switch (report_code) {
  case 1:
    // TODO: Run member report
    break;
  case 2:
    // TODO: Run provider report
    break;
  case 3:
    // TODO: Run summary report
    break;
  }

  return;
}