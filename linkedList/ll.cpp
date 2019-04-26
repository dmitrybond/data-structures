#include <iostream>
#include <cstdlib>
#include <string>

template <typename T>
class LinkedList
{
	private:
		T value;
		LinkedList* next;

	public:
		LinkedList();
		~LinkedList();
		void push(T);
		void pop();
		T operator[](int);
		void print();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	/* the base does not store a value, i.e. an empty list's 'next'
	 * field is NULL and the 'value' field is never set, i.e. it's
	 * garbage
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
void LinkedList<T>::print()
{
	LinkedList<T>* curr = this;
	std::cout << "[ ";
	while (curr->next != NULL){
		std::cout << curr->next->value << ", ";
		curr = curr->next;
	}
	std::cout << "]" << std::endl;
}

void test_integers()
{
	std::cout << "INTEGER TEST" << std::endl;
	LinkedList<int> test1;
	std::cout << "Initializing and populating "
		<< "a list of integers" << std::endl;
	for (int i = 0; i < 5; i++)
		test1.push(i*i);
	test1.print();
	std::cout << "Popping off all elements from the list "
		<< "plus one more to trigger an exception" << std::endl;
	try{
	for (int i = 0; i < 6; i++){
		test1.pop();
		test1.print();
	}
	}
	catch(std::range_error & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "Adding '42' to my list" << std::endl;
		test1.push(42);
	}
	test1.print();
	std::cout << std::endl;
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
	test2.print();
	std::cout << "Popping off all elements from the list "
		<< "plus one more to trigger an exception" << std::endl;
	try{
	for (int i = 0; i < 6; i++){
		test2.pop();
		test2.print();
		}
	}
	catch(std::range_error & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "Adding 'Howyadoing, mate?' to my list" << std::endl;
		test2.push("Howyadoing, mate?");
		test2.print();
	}
}

void test()
{
	test_integers();
	test_strings();
}

int main()
{
	test();
}
