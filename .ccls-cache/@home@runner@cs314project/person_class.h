#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

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
  Person(const Person &src); // copy constructor
  Person &
  operator=(const Person &src); // assignment operator (likely not needed if the
                                // class has no dynamic memory)

  void display() const;
  int get_key() const;

protected:
  string name;
  string number;
  string address;
  string state;
  string zipcode;
  string ID;
};

class Member : public Person {
public:
  Member();
  Member(const string &name, const string &number, const string &address,
         const string &state, const string &zipcode, const string &ID,
         bool status, const string &comments);
  ~Member();
  Member(const Member &src);
  Member &operator=(const Member &src);

  void display() const;

private:
  bool status;     // true = active, false = suspended
  string comments; // doctor notes basically
};

class Provider : public Person {
public:
  Provider();
  Provider(string service_code, float fee);
  ~Provider();
  Provider(const Provider &src);
  Provider &operator=(const Provider &src);

  void display() const;

private:
  string service_code;
  float fee;
};

// HASH TABLE

template <class TYPE> // the node class.
class Node {
public:
  Node<TYPE>();
  ~Node<TYPE>();
  Node<TYPE>(const Node<TYPE> &src);
  Node<TYPE> &operator=(const Node<TYPE> &src);

  // functions for LLL collision operations
  Node<TYPE> *&get_next();
  void set_next(Node<TYPE> *src);

  int display() const;

private:
  TYPE person;
  Node<TYPE> *next;
};

template <class TYPE> // hash table ADT class
class Table {
public:
  Table<TYPE>();
  ~Table<TYPE>();
  Table<TYPE>(const Table<TYPE> &src);
  Table<TYPE> &operator=(const Table<TYPE> &src);

  int display() const;
  bool add(TYPE &src);
  int hash(int src) const; // takes in a string to hash (aka, the ID number).
  bool remove(TYPE &src);  // removing a member or provider
  int dealloc(Node<TYPE> *&head); // for deallocating hash table

private:
  Node<TYPE> **table;
  int table_size;
};

#include "node.tpp"
#include "table.tpp"