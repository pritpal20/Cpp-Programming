#include "Hashtable.h"

template <typename T >
Hashtable<T>::Hashtable(int _num)
{
    //ctor

    num  = _num;
    Hash = new item<T>[num];
    for(int i = 0 ; i < num ; i++)
    {
        Hash[i].table->key = "empty";
        Hash[i].table->value = "empty";
        Hash[i].table->next = 0;
    }
}

template <typename T >
Hashtable<T>::~Hashtable()
{
     //dtor
}

template <typename T >
Hashtable<T>::Hashtable(const Hashtable& other)
{
    //copy ctor
}

template <typename T >
Hashtable<T>& Hashtable<T>::operator=(const Hashtable& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

template<typename T = string>
Hashtable::Hashing(const T _key)
{
    int sum = 0;
    for(int i = 0 ; i < _key.length(); i++)
    {
        sum+=key[i];
    }
    return sum % num ;
}
