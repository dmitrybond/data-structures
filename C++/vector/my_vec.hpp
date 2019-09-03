#include <iostream>
#include <stdexcept>

using namespace std;


#define BASE_SIZE 8
#define GROWTH_RATE 2

size_t next_pow2(size_t num)  // fails at 0
{
    --num;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    return num + 1;
}


template<typename T>
class myvector{

	public:	// construction
		myvector();
		myvector(size_t sz);
		myvector(size_t sz, const T initial);

	public:	// copy, assignment, destruction
		myvector(const myvector& other);
		myvector& operator=(const myvector& other);
		~myvector();

	public:	// iter protocol
		class iterator;
		iterator begin();
		iterator end();

        public:  // info
		size_t size() const;
        size_t capacity() const;

	public: // client
		void push_back(T& elem);
		void pop_back();
		void push_front(T& elem);
        T& operator[](size_t);

	public:	// dbg
		void dbg_prnt() const;

	private:
		T* m_elems;
		size_t m_capacity;
		size_t m_curr_size;
		void grow();

};  // myvector


/*************************/
/* start of construction */
/*************************/

template<typename T>
myvector<T>::myvector(): m_elems{nullptr}, m_capacity{BASE_SIZE},
	m_curr_size{0}
{
	m_elems = new T[m_capacity];
}

template<typename T>
myvector<T>::myvector(size_t sz): m_elems{nullptr}, m_capacity{BASE_SIZE},
	m_curr_size{sz}
{
	m_capacity = next_pow2(sz);
	m_elems = new T[m_capacity]{};
}

template<typename T>
myvector<T>::myvector(size_t sz, const T initial):
m_elems{nullptr}, m_capacity{BASE_SIZE}, m_curr_size{sz}
{
	m_capacity = next_pow2(sz);
	m_elems = new T[m_capacity];
	for (int i = 0; i < sz; i++)
		m_elems[i] = initial;
}

/***********************/
/* end of construction */
/***********************/


/*******************************/
/* start of copy, assgn, destr */
/*******************************/

template<typename T>
myvector<T>::myvector(const myvector& other): // deep copy
m_elems{nullptr}, m_capacity{other.m_capacity}, m_curr_size{other.m_curr_size}
{
	m_elems = new T[m_capacity];
	for (int i = 0; i < m_curr_size; i++)
		m_elems[i] = other.m_elems[i];
}

template<typename T>
myvector<T>& myvector<T>::operator=(const myvector& other) // deep copy
// TODO: check for self assgnmnt
{
	delete[] m_elems;
	m_capacity = other.m_capacity;
	m_elems = new T[m_capacity];
	m_curr_size = other.m_curr_size;
	for (int i = 0; i < m_curr_size; i++)
		m_elems[i] = other.m_elems[i];
	return *this;
}

template<typename T>
myvector<T>::~myvector()
{
	delete[] m_elems;
}

/*****************************/
/* end of copy, assgn, destr */
/*****************************/


/*****************/
/* start of iter */
/*****************/

template<typename T>
class myvector<T>::iterator{

    private:
        size_t m_index;
        myvector& m_vec;

    public:
        iterator(size_t pos, myvector& vec);
        void operator++();  // ++i
        void operator++(int);  // i++
        T& operator*() const;
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
};

template<typename T>
typename myvector<T>::iterator myvector<T>::begin()
{
    return myvector<T>::iterator{0, *this};
}

template<typename T>
typename myvector<T>::iterator myvector<T>::end()
{
    return myvector<T>::iterator{size(), *this};
}

template<typename T>
void myvector<T>::iterator::operator++()  // ++i
{
    m_index++;
}

template<typename T>
void myvector<T>::iterator::operator++(int)  //i++
{
    m_index++;
}

template<typename T>
T& myvector<T>::iterator::operator*() const
{
    return m_vec.m_elems[m_index];
}

template<typename T>
bool myvector<T>::iterator::operator==(const myvector<T>::iterator& other) const
{
    return m_index == other.m_index;
}

template<typename T>
bool myvector<T>::iterator::operator!=(const myvector<T>::iterator& other) const
{
    return !(operator==(other));
}

template<typename T>
myvector<T>::iterator::iterator(size_t pos, myvector& vec): m_index{pos}, m_vec{vec} {};

/***************/
/* end of iter */
/***************/


/*****************/
/* start of info */
/*****************/

template<typename T>
size_t myvector<T>::size() const
{
    return m_curr_size;
}

template<typename T>
size_t myvector<T>::capacity() const
{
    return m_capacity;
}

/***************/
/* end of info */
/***************/


/*******************/
/* start of client */
/*******************/

template<typename T>
void myvector<T>::push_back(T& elem)
{
    if(m_curr_size == m_capacity)
        grow();
    m_elems[m_curr_size++] = elem;
}

template<typename T>
void myvector<T>::push_front(T& elem)
{
    if(m_curr_size == m_capacity)
        grow();
    T* buf = new T[m_capacity];
    for(int i = 0; i < m_curr_size; i++)
        buf[i+1] = m_elems[i];
    buf[0] = elem;
    delete[] m_elems;
    m_elems = buf;
    m_curr_size++;
}

template<typename T>
void myvector<T>::pop_back()
{
    m_curr_size--;
}

template<typename T>
T& myvector<T>::operator[](size_t index)
{
    if(index >= m_curr_size)
        throw out_of_range("index out of bounds");
    return m_elems[index];
}

/*******************/
/* end of client */
/*******************/


/* Since C++ doesn't seem to have C's realloc analog,
 * we realloc manually, i.e. copy data to a new buffer
 * and free the old memory. 
 */
template<typename T>
void myvector<T>::grow()
{
    m_capacity*=GROWTH_RATE;
    T* buf = new T[m_capacity];
    for(int i = 0; i < m_curr_size; i++)
        buf[i] = m_elems[i];
    delete[] m_elems;
    m_elems = buf;
}

template<typename T>
void myvector<T>::dbg_prnt() const
{
	if (m_curr_size == 0){
		cout << "DBG: []";
		cout << ": m_curr_size = " << m_curr_size << ", m_capacity = " << m_capacity
				<< endl;
		return;
	}
	cout << "DBG: [";
	for (int i = 0; i < m_curr_size - 1; i++) // m_curr_size - 1
		cout << m_elems[i] << ", ";
	cout << m_elems[m_curr_size - 1] << "]";
	cout << ": m_curr_size = " << m_curr_size << ", m_capacity = " << m_capacity << endl;
}
