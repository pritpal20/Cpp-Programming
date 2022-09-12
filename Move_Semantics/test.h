#ifndef TEST_H
#define TEST_H
#include <cstring>
enum ret_val{SUCCESS = 0,FAIL = 1,fail = 1,FAILURE = 1};


class String
{
public : 

	String()
	{
		std::cout << "Default created \n";
		m_buffer = nullptr;
		m_size = 0;
	}
	String(const char* buffer)
	{
		std::cout << "Created !!!\n";

		m_size = strlen(buffer);
		m_buffer = new char[m_size];
		memset(m_buffer,'\0',m_size);
		memcpy(m_buffer,buffer,m_size);
	}

	String(const String& other)
	{
		std::cout << "Copied !!!\n";

		m_size = other.m_size;
		m_buffer = new char[m_size];
		memset(m_buffer,'\0',m_size);
		memcpy(m_buffer,other.m_buffer,m_size);
	}

	String(String&& other) noexcept
	{
		std::cout << "Moved !!!\n";

		m_size = other.m_size;
		m_buffer = other.m_buffer;
		other.m_buffer = nullptr;
		other.m_size = 0;
	}

	String& operator=(const String& other)
	{
		std::cout << "  assignment called \n";
		if(this != &other)
		{
			memset(this->m_buffer,'\0',this->m_size);
			delete[] this->m_buffer;
			this->m_size = other.m_size;
			this->m_buffer = new char[m_size];
			memcpy(this->m_buffer,other.m_buffer,this->m_size);
		}
		return *this;
	}

	String& operator=(String&& other)
	{
		std::cout << "move assignment called \n";
		if(this != &other)
		{
			memset(this->m_buffer,'\0',this->m_size);
			delete[] this->m_buffer;
			this->m_size = other.m_size;
			this->m_buffer =other.m_buffer;

			other.m_buffer = nullptr;
			other.m_size = 0;
		}
		return *this;
	}

	~String()
	{
		std::cout << "Deleted !!! \n" ;
		delete m_buffer;
	}

	void print()
	{
		for(int i = 0;i < m_size;i++)
			printf("%c",m_buffer[i]);

		printf("\n");
	}

private :
	char* m_buffer;
	uint32_t m_size;

};

class Entity
{
	String _name;

public :

	Entity(const String& name) : _name(name)
	{

	}

	Entity(String&& name) : _name(std::move(name))
	{

	}

	void PrintName()
	{
		_name.print();
	}

};


#endif // TEST_H
