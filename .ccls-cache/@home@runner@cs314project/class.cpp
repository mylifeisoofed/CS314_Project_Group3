#include "class.h"

Person::Person() {}

Person::Person(const string &name, const string &number, const string &address,
               const string &state, const string &zipcode, const string &ID)
    : name(name), number(number), address(address), state(state),
      zipcode(zipcode), ID(ID) {}

Person::~Person() {}

void Person::display() const {
  cout << "Name: " << name << endl;
  cout << "Address: " << address << endl;
  cout << "State: " << state << endl;
  cout << "Zipcode: " << zipcode << endl;
  cout << "ID Number: " << ID << endl;
}

bool Person::compare_name(const string &name) { return this->name == name; }

int Person::get_key() const {
  try {
    if (ID.size() > 0)
      return stoi(ID);
    else
      return -1;
  } catch (...) {
    return -1;
  }
}

Member::Member() {
  status = false;
  comments = "";
}

Member::Member(const string &name, const string &number, const string &address,
               const string &state, const string &zipcode, const string &ID,
               bool status, const string &comments)
    : Person(name, number, address, state, zipcode, ID), status(status),
      comments(comments) {}

Member::~Member() {}

void Member::display() const {
  Person::display();
  cout << "Status: ";

  if (status)
    cout << "Valid" << endl;
  else
    cout << "Suspended" << endl;

  cout << "Comments: " << comments << endl;
  cout << "\n";
}
Provider ::Provider() { fee = 0; }
Provider ::~Provider() {}