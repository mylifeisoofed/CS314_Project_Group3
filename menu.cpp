#include "menu.h"

#define DIRECTORY "provider_directory.txt"
#define RECORDS "service_records.txt"
#define MEMBERS "list_of_members.txt"
#define PROVIDERS "list_of_providers.txt"

/* moved to menu.h
struct Service {
  string code;
  string description;
  double cost;
};

void provider_terminal(Table<Member> &members, Table<Provider> &providers);
void manager_terminal();
void check_in(Table<Member> &members, Table<Provider> &providers);
vector<string> split(const string &s, char delimiter);
Service find_service(const string &target);
void display_providers();
void display_members();
*/

void provider_terminal(Table<Member> &members, Table<Provider> &providers) {
  string provider_id;
  char choice = '0';

  cout << ">>> Provider Terminal <<<\n\n";

  cout << "Enter your provider ID: ";
  cin >> provider_id;
  cout << endl;

  while (true) {
    cout << "Select an option:\n"
         << "1. Check-in a member\n"
         << "2. Display all Providers\n"
         << "3. Display all Members\n"
         << "4. Exit\n";
    cin >> choice;
    switch (choice) {
    case '1':
      check_in(members, providers);
      break;
    case '2':
      providers.display();
      break;
    case '3':
      members.display();
      break;
    case '4':
      return;
    default:
      cout << "Invalid choice. Please try again.\n";
    };
  }
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

void check_in(Table<Member> &members, Table<Provider> &providers) {
  Member member;
  string member_id;
  string member_name;
  Service service;
  string service_date;
  string service_code;
  string provider_id;
  string comments;
  char choice;

  // Collect and validate member credentials
  while (true) {
    cout << "Enter member ID: ";
    cin >> member_id;
    cin.ignore(100, '\n');
    cout << endl;

    cout << "Enter member Name: ";
    getline(cin, member_name);
    cout << endl;

    if (members.find(member, member_id, member_name)) {
      cout << (member.get_status() ? "Validated" : "Suspended") << endl;
      break;
    } else {
      cout << "Invalid credentials. Please try again.\n";
    }
  }

  // Collect and validate billing date
  regex regex_date(
      "^(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])-(19[7-9]\\d|20\\d{2})$");
  while (true) {
    cout << "Enter the date of service (MM-DD-YYYY): ";
    cin >> service_date;
    cout << endl;

    if (regex_match(service_date, regex_date)) {
      break;
    } else {
      cout << "Invalid date. Please try again.\n";
    }
  }

  // Collect and validate service code
  while (true) {
    cout << "Enter the service code: ";
    cin >> service_code;
    cout << endl;

    service = find_service(service_code);
    if (!(service.code.empty())) { // if the code was found
      cout << service.code << ": " << service.description << endl
           << "Is this the correct service? (Y/N): ";
      cin >> choice;
      if (choice == 'Y' || choice == 'y') {
        break;
      } else {
        cout << "Please try again.\n";
      }
    } else {
      cout << "Invalid service code. Please try again.\n";
    }
  }

  // Collect comments about service (optional)
  while (true) {
    cout << "Would you like to add any comments? (Y/N): ";
    cin >> choice;
    cout << endl;

    if (choice == 'Y' || choice == 'y') {
      cout << "Enter comments (up to 100 characters): ";
      getline(cin, comments);
      cout << endl;
    } else if (choice == 'N' || choice == 'n') {
      break;
    } else {
      cout << "Invalid choice. Please try again.\n";
    }
  }

  // Open service record file to write
  ofstream file(RECORDS, ios::app);
  if (!file.is_open()) {
    cerr << "Error: Unable to open file." << endl;
    return;
  }

  // Get and format current date and time
  time_t current_time = time(nullptr);
  tm *local_time = localtime(&current_time);
  char formatted_time[20];
  strftime(formatted_time, sizeof(formatted_time), "%m-%d-%Y %H:%M:%S",
           local_time);

  // Write service details to report
  file << "Current Date and Time: " << formatted_time << endl;
  file << "Date Service Provided: " << service_date << endl;
  file << "Provider Number: " << provider_id << endl;
  file << "Member Number: " << member_id << endl;
  file << "Service Code: " << service_code << endl;
  if (!comments.empty()) {
    file << "Comments: " << comments << endl;
  }
  file << endl;

  return;
}

vector<string> split(const string &s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream token_stream(s);
  while (getline(token_stream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

Service find_service(const string &target) {
  ifstream file(DIRECTORY);
  string line;
  Service found;

  while (getline(file, line)) {
    vector<string> parts = split(line, '|');
    if (parts.size() == 3) {
      if (parts[0] == target) {
        found.code = parts[0];
        found.description = parts[1];
        found.cost = stod(parts[2]);
        file.close();
        return found;
      }
    }
  }

  file.close();
  return Service();
}

void display_providers() {
  ifstream file(PROVIDERS);
  string line;

  while (getline(file, line)) {
    vector<string> parts = split(line, ':');
    if (parts.size() != 8) {
      cout << "An error occurred\n";
      return;
    }
    cout << "Name: " << parts[0] << "Phone: " << parts[1]
         << "Address: " << parts[2] << "State: " << parts[3]
         << "Zipcode: " << parts[4] << "ID: " << parts[5] << "Fee: " << parts[6]
         << "Service Code: " << parts[7] << "\n\n";
  }
  return;
}

void display_members() {
  ifstream file(MEMBERS);
  string line;

  while (getline(file, line)) {
    vector<string> parts = split(line, ':');
    if (parts.size() != 8) {
      cout << "An error occurred\n";
      return;
    }
    cout << "Name: " << parts[0] << "Phone: " << parts[1]
         << "Address: " << parts[2] << "State: " << parts[3]
         << "Zipcode: " << parts[4] << "ID: " << parts[5]
         << "Status: " << (parts[6] == "1" ? "Valid" : "Suspended")
         << "Commments: " << parts[7] << "\n\n";
  }
  return;
}