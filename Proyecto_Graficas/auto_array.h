#pragma once
//Just like auto_ptr, but for arrays
template<class T>
class auto_array
{
private:
	T* array;
	mutable bool isReleased;
public:
	explicit auto_array(T* array_ = NULL) :
		array(array_), isReleased(false)
	{
	}

	auto_array(const auto_array<T> &aarray)
	{
		array = aarray.array;
		isReleased = aarray.isReleased;
		aarray.isReleased = true;
	}

	~auto_array()
	{
		if (!isReleased && array != NULL)
		{
			delete[] array;
		}
	}

	T* get() const
	{
		return array;
	}

	T &operator*() const
	{
		return *array;
	}

	void operator=(const auto_array<T> &aarray)
	{
		if (!isReleased && array != NULL)
		{
			delete[] array;
		}
		array = aarray.array;
		isReleased = aarray.isReleased;
		aarray.isReleased = true;
	}

	T* operator->() const
	{
		return array;
	}

	T* release()
	{
		isReleased = true;
		return array;
	}

	void reset(T* array_ = NULL)
	{
		if (!isReleased && array != NULL)
		{
			delete[] array;
		}
		array = array_;
	}

	T* operator+(int i)
	{
		return array + i;
	}

	T &operator[](int i)
	{
		return array[i];
	}
};

