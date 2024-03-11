template <class TYPE>
Table<TYPE>::Table(): table(nullptr), table_size(TABLE_SIZE)
{
    table = new Node<TYPE>*[table_size];
    for (int i = 0; i < table_size; ++i)
    {
        table[i] = nullptr;
    }
}

template <class TYPE>
Table<TYPE>::~Table<TYPE>()
{
    for (int i = 0; i < table_size; ++i)
    {
        if (table[i])
            dealloc(table[i]);
    }

    delete [] table;
}

template <class TYPE>
Table<TYPE>::Table(const Table<TYPE> & src)
{}

template <class TYPE>
Table<TYPE> & Table<TYPE>::operator=(const Table<TYPE> & src)
{}

template <class TYPE>
int Table<TYPE>::display() const
{
    for(int i = 0; i < TABLE_SIZE; ++i){
      display(table[i]);
    }

    return 1;
}

template <class TYPE>
int Table<TYPE>::display(Node<TYPE> * head) const
{
    Node<TYPE> * current = head;

    while(current != nullptr)
    {
        current->display();
        current = current->get_next();
    }

    return 1;
}

template <class TYPE>
bool Table<TYPE>::add(TYPE & src)
{
    int ID = src.get_key();
    if (ID == -1)
        return false;

    int key = hash(ID);

    // base case if the list was already empty at this index
    if (table[key] == nullptr){ 
      table[key] = new Node<TYPE>(src);
      return true;
    }

    // case where it's already holding something.
    else{
      Node<TYPE>* temp = table[key];
      table[key] = new Node<TYPE>(src);
      table[key]->set_next(temp);
      return true;
    }

    // otherwise, something weird has happened.
    return false;
}

template <class TYPE>
int Table<TYPE>::hash(int src) const
{
    int number = src;

    return number % TABLE_SIZE;
}

template <class TYPE>
bool Table<TYPE>::remove(const string& id, const string& name)
{
  int key = 0;
  try{
    key = stoi(id);
  }
  catch(...){
    return false;
  }

  key = hash(key);
  
  return remove(table[key], name);
}

template <class TYPE>
bool Table<TYPE>::remove(Node<TYPE> *& head, const string& name)
{
  if (!head) // at the end
    return false;

  if (head->compare_name(name)) // found the person to delete
  {
    Node<TYPE> * temp = head->get_next();
    delete head;
    head = temp;
    return true;
  }

  return remove(head->get_next(), name);
}

template <class TYPE>
int Table<TYPE>::dealloc(Node<TYPE> *& head)
{
    int i = 0;

    if (!head) // if we are at the end of the list
        return i;
    
    i = 1 + dealloc(head->get_next()); // traverse to the end of the list

    // as we unwind the stack, deallocate.
    if (head)
        delete head;
    return i;
}

template <class TYPE>
bool Table<TYPE>::find(const string& id, const string& name)
{
  int key = 0;
  try{
    key = stoi(id);
  }
  catch(...){
    return false;
  }

  key = hash(key);

  return find(table[key], name);
}

template <class TYPE>
bool Table<TYPE>::find(Node<TYPE>* head, const string& name)
{
  if (!head) // at the end
    return false; // person not found.

  if (head->compare_name(name)) // found the person
  {
    head->display(); // display their info
    return true;
  }

  return find(head->get_next(), name);
}
