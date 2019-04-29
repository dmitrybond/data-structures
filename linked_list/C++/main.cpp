#include <iostream>

#include "ll.hpp"

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
		for (int i = 0; i < 4; i++){
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
	std::cout << std::endl;
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

