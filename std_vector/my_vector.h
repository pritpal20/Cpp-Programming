#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template <typename T,size_t N = 2>
class Vector
{
	T* arr = nullptr;

	size_t m_size = 0;
	size_t m_capacity = 0;

public : 

	Vector()
	{
		size_t newCapacity = N;
		realloc(newCapacity);
	}

	void realloc(size_t newCapacity)
	{
		//downsizing the vector.
		if(newCapacity < m_size)
		{
			m_size = newCapacity;
		}

		T* newBlock = new T[newCapacity];

		for(size_t i = 0; i < m_size ;i++)
			newBlock[i] = std::move(arr[i]);

		delete[] arr;
		arr = nullptr;
		arr = newBlock;
		m_capacity = newCapacity;

	}

	void push_back(const T& data)
	{
		if(m_size >= m_capacity)
			realloc(m_capacity + m_capacity/2);
		arr[m_size++] = data;
	}

	template<typename... Args>
	T& emplace_back(Args&&... args)
	{
		if(m_size >= m_capacity)
			realloc(m_capacity + m_capacity/2);

		arr[m_size] = T(std::forward<Args>(args)...);

		return arr[m_size++];

	}

	void push_back(T&& data)
	{
		if(m_size >= m_capacity)
			realloc(m_capacity + m_capacity/2);
		

		arr[m_size++] = std::move(data);
	}

	void pop_back()
	{

		if(m_size > 0)
		{
			m_size--;
			arr[m_size].~T();
		}

	}

	void Clear()
	{
		for (int i = 0; i < m_size; ++i)
		{
			arr[i].~T();
		}

		m_size = 0;
	}

	size_t size() const 
	{

		return m_size;
	}

	const T& operator[](size_t index ) const 
	{
		if(index >= m_size)
		{
			//assert 
		}

		return arr[index];
	}

	T& operator[](size_t i ) 
	{
		return arr[i];
	}


};



#endif // MY_VECTOR_H
