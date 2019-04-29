#include <stdio.h>
#include "arr.hpp"

int main(void)
{
	array1d<int> test(10);
	test[3] = 42;
	std::cout << test[3] << std::endl;
	// array1d<int> test2 = test;
}
