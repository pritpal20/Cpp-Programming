#include <iostream>
#include "../GlobalDef.h"

namespace my_shared_ptr
{

 
	// Class representing a reference counter class
	class Counter
	{
	public:
	    // Constructor
	    Counter(): m_counter(0)
	    {

	    };
	 
	    Counter(const Counter&) = delete;
	    Counter& operator=(const Counter&) = delete;
	 
	    // Destructor
	    ~Counter() {}
	 
	    void reset()
	    {
	      m_counter = 0;
	    }
	 
	    unsigned int get()
	    {
	      return m_counter;
	    }
	 
	    // Overload post/pre increment
	    void operator++()
	    {
	      m_counter++;
	    }
	 
	    void operator++(int)
	    {
	      m_counter++;
	    }
	 
	    // Overload post/pre decrement
	    void operator--()
	    {
	      m_counter--;
	    }
	    void operator--(int)
	    {
	      m_counter--;
	    }
	 
	    // Overloading << operator
	    friend std::ostream& operator<<(std::ostream& os,
	                               const Counter& counter)
	    {
	        os << "Counter Value : " << counter.m_counter
	           << endl;
	        return os;
	    }
	 
	private:
	    unsigned int m_counter{};
	};


	template<class T>
	class Shared_ptr
	{

	private:
		T* _ptr;
		Counter *m_counter;

	public:
		explicit Shared_ptr( T* ptr = NULL ) 
		{
			_ptr = ptr;
			m_counter = new Counter();

			if (_ptr == NULL)
			{
				*m_counter++;
			}
		}

		 // Copy constructor
	    Shared_ptr(Shared_ptr<T>& sp)
	    {
	        _ptr = sp._ptr;
	        m_counter = sp.m_counter;
	        (*m_counter)++;
	    }

	    // Reference count
	    unsigned int use_count()
	    {
	      return m_counter->get();
	    }

		~Shared_ptr()
		{
			*m_counter--;
			if(m_counter->get() == 0 )
			{
				delete _ptr;
				delete m_counter;
			}
		}

		T* get()
	    {
	      return _ptr;
	    }

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	};

}