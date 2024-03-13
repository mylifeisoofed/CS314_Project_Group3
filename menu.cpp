#include "table.h"
#include <regex>
#include <ctime>
#include <sstream>
#include <vector>

#define DIRECTORY "provider_directory.txt"

struct Service {
    string code;
    string description;
    double cost;
};

void provider_terminal(Table<Member> &members, Table<Provider> &providers);
void manager_terminal();
vector<string> split(const string& s, char delimiter);
Service find_service(const string &target);

void provider_terminal(Table<Member> &members, Table<Provider> &providers) {
  Member member;
  string provider_id;
  string member_id;
  string member_name;
  Service service;
  string service_date;
  string service_code;
  string comments;
  char choice;

  cout << ">>> Provider Terminal <<<\n\n";

  cout << "Enter your provider ID: ";
  cin >> provider_id;
  cout << endl;

  // Collect and validate member credentials
  while (true) {
    cout << "Enter member ID: ";
    cin >> member_id;
    cout << endl;

    cout << "Enter member Name: ";
    cin >> member_name;
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
      cout << service.code << ": " << service.description 
           << endl << "Is this the correct service? (Y/N): ";
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
      cin >> comments;
      cout << endl;
    } else if (choice == 'N' || choice == 'n') {
      break;
    } else {
      cout << "Invalid choice. Please try again.\n";
    }
  }

  // Get and format current date and time
  time_t current_time = time(nullptr);
  tm *local_time = localtime(&current_time);
  char formatted_time[20];
  strftime(formatted_time, sizeof(formatted_time), "%m-%d-%Y %H:%M:%S", local_time);

  // Add service details to report
  

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

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream token_stream(s);
    while (getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Service find_service(const string& target) {
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