#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

using namespace std;

template <typename T >
struct node
{
    T key;
    T value;
    node* next;
};

template <typename T >
struct item
{
    int count;
    node<T>* table;
};

template <typename T>
class Hashtable
{
    public:
        Hashtable();
        Hashtable(int);
        int Hashing();
        virtual ~Hashtable();
        Hashtable(const Hashtable& other);
        Hashtable& operator=(const Hashtable& other);

    protected:

    private:

        item<T>* Hash;
        int num;
};

#endif // HASHTABLE_H
