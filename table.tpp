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
}

template <class TYPE>
bool Table<TYPE>::add(TYPE & src)
{
    int ID = src.get_key();
    if (ID == -1)
        return false;

    int key = hash(ID);

    cout << "Hash Key: " << key << endl;

    return true;
}

template <class TYPE>
int Table<TYPE>::hash(int src) const
{
    int number = src;

    return number % TABLE_SIZE;
}

template <class TYPE>
bool Table<TYPE>::remove(TYPE & src)
{}

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
