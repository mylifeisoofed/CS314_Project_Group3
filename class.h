#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// This class header file contains the inheritance hiearchy.

const int MAX = 100;       // for temporary array of chars.
const int TABLE_SIZE = 61; // prime number for hash table

// PROVIDER AND MEMBER CLASS FOR HASH TABLE

class Person // base class
{
public:
  Person();
  Person( // for the initialization list
      const string &name, const string &number, const string &address,
      const string &state, const string &zipcode, const string &ID);
  ~Person();
  // Person(const Person &src); // copy constructor
  // Person &
  // operator=(const Person &src); // assignment operator (likely not needed if
  // the
  //  class has no dynamic memory)

  void display() const;
  int get_key() const;
  bool compare_name(const string &name);

protected:
  string name;
  string number;
  string address;
  string state;
  string zipcode;
  string ID;
};

// Member subclass
class Member : public Person {
public:
  Member();
  Member(const string &name, const string &number, const string &address,
         const string &state, const string &zipcode, const string &ID,
         bool status, const string &comments);
  ~Member();

  void display() const;

private:
  bool status;     // true = active, false = suspended
  string comments; // doctor notes basically
};

// Provider subclass
class Provider : public Person {
public:
  Provider();
  Provider(string service_code, float fee);
  ~Provider();

  void display() const;

private:
  string service_code;
  float fee;
};
