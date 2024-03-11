#include "class.h"

// This header file contains the hash table data structure

template <class TYPE> // the node class.
class Node {
public:
  Node<TYPE>();
  ~Node<TYPE>();
  Node<TYPE>(const TYPE &src);
  Node<TYPE> &operator=(const Node<TYPE> &src);

  // functions for LLL collision operations
  Node<TYPE> *&get_next();
  void set_next(Node<TYPE> *src);

  bool display() const;
  bool compare_name(const string &name);

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

  int display() const;     // function to display all people in the table
  bool add(TYPE &src);     // Function to add people to the table
  int hash(int src) const; // takes in a string to hash (aka, the ID number).
  bool remove(const string &id,
              const string &name); // removing a member or provider
  bool find(const string &id,
            const string &name); // function to find a specific member.

private:
  // wrapper functions for recursions
  bool remove(Node<TYPE> *&head, const string &id);
  int display(Node<TYPE> *head) const;
  int dealloc(Node<TYPE> *&head); // for deallocating hash table
  bool find(Node<TYPE> *head, const string &id);

  Node<TYPE> **table;
  int table_size;
};

#include "node.tpp"
#include "table.tpp"