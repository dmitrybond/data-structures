#include <iostream>
#include "my_vec.hpp"
using namespace std;

void test1()  // constr, destr, copy, assgn, iter
{
	myvector<int> test1;
	myvector<int> test2;
	myvector<int> test3;
	myvector<int> test4{9, -6};
	test1.dbg_prnt();
	test2.dbg_prnt();
	test3.dbg_prnt();
	test4.dbg_prnt();

	// same as test1.operator=(test2.operator=(test3.operator=(test4)));
	test1 = test2 = test3 = test4;

	test1.dbg_prnt();
	test2.dbg_prnt();
	test3.dbg_prnt();
	test4.dbg_prnt();

        cout << "Using iter protocol:" << endl;

        for(myvector<int>::iterator it = test1.begin(); it != test1.end(); it++)
            cout << *it << endl;

        cout << "Using C++11 range for:" << endl;
        for(auto elem : test1)
            cout << elem << endl;
}

void test2()  // client
{
    myvector<int> test1{6, 42};
    test1.dbg_prnt();

    int val = 15;

    cout << "Adding two more numbers" << endl;
    test1.push_back(val);
    test1.push_back(val);
    test1.dbg_prnt();

    cout << "Adding one more number to test growth" << endl;
    test1.push_back(val);
    test1.dbg_prnt();

    cout << "Adding more numbers" << endl;
    for(int i = 0; i < 8; i++)
        test1.push_back(i);
    test1.dbg_prnt();

    cout << "Popping off twice" << endl;
    for(int i = 0; i < 2; i++)
        test1.pop_back();
    test1.dbg_prnt();

    cout << "Pushing front" << endl;
    test1.push_front(val);
    test1.dbg_prnt();
}

void test3()  // operator[]
{
    myvector<int> test{41, 4};
    for(int i = 0; i < test.size(); i++)
        test[i] = i;
    test.dbg_prnt();
    test[100000];
}

int main()
{
    test1();
    test2();
    test3();
}
