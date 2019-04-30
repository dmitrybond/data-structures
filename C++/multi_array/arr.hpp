#include <iostream>
#include <cstdlib>


template <typename T>
class array1d
{
	private:
		unsigned int size;
		T* base_address;

	public:
		array1d(void);
		array1d(unsigned int);	// initializes with zeros
		~array1d(void);
		unsigned int shape(void);
		T& operator[](unsigned int);
		//array1d<T>& operator=(array1d<T>&);
		bool operator==(array1d<T>&);
		bool operator!=(array1d<T>&);
};

template <typename T>
array1d<T>::array1d(void)
{
	base_address = NULL;
	size = 0;
}

template <typename T>
array1d<T>::array1d(unsigned int sz)
{
	base_address = new T[sz]();
	size = sz;
}

template <typename T>
array1d<T>::~array1d()
{
	delete[] base_address;
	size = 0;
}

template <typename T>
unsigned int array1d<T>::shape(void)
{
	return size;
}

template <typename T>
T& array1d<T>::operator[] (unsigned int index)
{
	/* it's important to return a reference to array1d<T>, not T itself if
	 * we want not only get, but also set. obj[3] is a literal, which
	 * is an rvalue. Assignment, on the other hand, needs an lvalue, i.e.
	 * a variable to assign to. If we don't return a reference,
	 * obj[3] 			// OK
	 * obj[3] = 5 		// error: assigning to lvalue.
	 * When a reference is returned, obj[3] evaluates to a reference, which
	 * can be assigned to, not a literal value of type T
	 */
	if (index >= size || index < 0)
		throw std::range_error("Index out of range\n");
	return base_address[index];
}
