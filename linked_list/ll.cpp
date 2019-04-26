#include <iostream>
#include <cstdlib>
#include <string>

/*TODO add int length() */

template <typename T>
class LinkedList
{
	private:
		T value;
		LinkedList<T>* next;

	public:
		LinkedList();
		~LinkedList();
		void push(T);
		void pop();
		bool is_empty();
		size_t length();
		T operator[](int);
		template <typename S>
		friend std::ostream& operator<<(std::ostream&, LinkedList<S>);
		/* friend is used to declare a non-member function with a
		 * permission to access this class' private attribues.
		 * Note, I need to use the template with a different
		 * identifier (not T; S in this case) otherwise it
		 * 'shadows' the identifier (T in this case) of the
		 * class
		 */
};

template <typename T>
LinkedList<T>::LinkedList()
{
	/* the parent node does not store a value, so empty list's
	 * 'value' field is garbage; obj[0] is therefore the first
	 * child's value, not parent's value. Such implementation
	 * ensures consistency in allocation/deallocation. Also,
	 * this->next == NULL guarantees that the list is empty,
	 * which wouldn't be the case if the first element was
	 * stored in the parent node.
	 */
	this->next = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
}

template <typename T>
void LinkedList<T>::push(T value)
{
	LinkedList<T>* curr = this;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new LinkedList;
	curr->next->value = value;
	curr->next->next = NULL;
}

template <typename T>
void LinkedList<T>::pop()
{
	if(this->next == NULL)
		throw std::range_error("popping off an empty list");
	LinkedList<T>* curr = this;
	while(curr->next->next != NULL)
		curr = curr->next;
	delete curr->next;
	curr->next = NULL;
}

template <typename T>
bool LinkedList<T>::is_empty()
{
	if(this->next == NULL)
		return true;
	return false;
}

template <typename T>
size_t LinkedList<T>::length()
{
	if(this->next == NULL)
		return 0;
	LinkedList<T>* curr = this;
	size_t curr_index = 0;
	while (curr->next != NULL){
		curr_index++;
		curr = curr->next;
	}
	return curr_index;
}

template <typename T>
T LinkedList<T>::operator[](int index)
{
	if(this->next == NULL)
		throw std::range_error("cannot access an empty list");
	LinkedList<T>* curr = this;
	int curr_index = 0;
	while (curr->next != NULL){
		if (index == curr_index++)
			return curr->next->value;
		curr = curr->next;
	}
	throw std::range_error("index out of bounds");
}

template <typename T>
std::ostream& operator<<(std::ostream& os, LinkedList<T> ll)
{
	LinkedList<T>* curr = &ll;
	os << "[ ";
	while (curr->next != NULL){
		os << curr->next->value << ", ";
		curr = curr->next;
	}
	os << "]";
	return os;
}

/* ======================================================================== */
/* ==================================TESTS================================= */

void test_integers()
{
	std::cout << "INTEGER TEST" << std::endl;
	LinkedList<int> test1;
	std::cout << "Initializing and populating "
		<< "a list of integers" << std::endl;
	for (int i = 0; i < 5; i++)
		test1.push(i*i);
	std::cout << test1 << "; Length = " << test1.length() << std::endl;
	std::cout << "Popping off all elements from the list "
		<< "plus one more to trigger an exception" << std::endl;
	try{
		for (int i = 0; i < 6; i++){
			test1.pop();
			std::cout << test1 << "; Length = " << test1.length() << std::endl;
		}
	}
	catch(std::range_error & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "Adding '42' to my list" << std::endl;
		test1.push(42);
		std::cout << test1 << "; Length = " << test1.length() << std::endl;
	}
	std::cout << "testing is_empty: " << test1.is_empty() << std::endl;
	std::cout << "popping once: " << std::endl;
	test1.pop();
	std::cout << test1 << "; Length = " << test1.length() << std::endl;
	std::cout << "testing is_empty again: " << test1.is_empty() << std::endl;
}

void test_strings()
{
	std::cout << "STRINGS TEST" << std::endl;
	LinkedList<std::string> test2;
	std::cout << "Initializing and populating "
		<< "a list of strings" << std::endl;
	std::string base = "dude";
	for (int i = 0; i < 5; i++){
		base += " whatup";
		test2.push(base);
	}
	std::cout << test2 << "; Length = " << test2.length() << std::endl;
	std::cout << "Popping off all elements from the list "
		<< "plus one more to trigger an exception" << std::endl;
	try{
		for (int i = 0; i < 6; i++){
			test2.pop();
			std::cout << test2 << "; Length = " << test2.length() << std::endl;
		}
	}
	catch(std::range_error & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "Adding 'Howyadoing, mate?' to my list" << std::endl;
		test2.push("Howyadoing, mate?");
		std::cout << test2 << "; Length = " << test2.length() << std::endl;
	}
	std::cout << "testing is_empty: " << test2.is_empty() << std::endl;
	std::cout << "popping once: " << std::endl;
	test2.pop();
	std::cout << test2 << "; Length = " << test2.length() << std::endl;
	std::cout << "testing is_empty again: " << test2.is_empty() << std::endl;
}

void test()
{
	test_integers();
	std::cout << std::endl;
	test_strings();
}

int main()
{
	test();
}
