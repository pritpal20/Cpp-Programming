#ifndef MYSTRING
#define MYSTRING
/*
	This code demonstrate the use of copy constructor 
*/
#include <cstring>

int global_var = 100;


class MyString
{
public:
	MyString();
	MyString(const char*);
	MyString(const 	MyString& obj);
	~MyString();
	char* get();

	friend std::ostream& operator <<(std::ostream& stream,const MyString& string);

	char& operator[] (unsigned int index);

private :
	char *m_Buffer ; 
	unsigned int m_size ;
	
};

MyString::MyString()
{
	std::cout << "My string object constructed \n";
	m_Buffer = NULL;
	m_size = 0;
}

MyString::MyString(const char* str_in)
{
	std::cout << "My string object constructed \n";
	m_size = strlen(str_in);
	m_Buffer = new char[m_size + 1];
	memcpy(m_Buffer,str_in,m_size);
}

MyString::~MyString()
{
	std::cout << "My string object destroyed \n";

	delete [] m_Buffer;
}

char* MyString::get()
{
	return this->m_Buffer;
}

MyString::MyString(const MyString& obj)
{
	std::cout << "Copy constructor called \n";
	this->m_size = obj.m_size;
	this->m_Buffer = new char[this->m_size + 1];
	memcpy(this->m_Buffer,obj.m_Buffer,obj.m_size);
}

std::ostream& operator <<(std::ostream& stream,const MyString& string)
{
	stream << string.m_Buffer  ; 
}

char& MyString::operator[] (unsigned int index)
{
	return m_Buffer[index];
}
#endif