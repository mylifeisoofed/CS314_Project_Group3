template <class TYPE>
Node<TYPE>::Node(): next(nullptr)
{}

template <class TYPE>
Node<TYPE>::~Node()
{
    next = nullptr;
}

template <class TYPE>
Node<TYPE>::Node(const Node<TYPE> & src)
{
    person = src.person;
}

template <class TYPE>
Node<TYPE> & Node<TYPE>::operator=(const Node<TYPE> & src)
{
    person = src.person;
    return *this;
}

template <class TYPE>
Node<TYPE> *& Node<TYPE>::get_next()
{
    return next;
}

template <class TYPE>
void Node<TYPE>::set_next(Node<TYPE> * src)
{
    next = src;
}


template <class TYPE>
int Node<TYPE>::display() const
{
    // call the class's display function.
}