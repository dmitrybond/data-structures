#include "ll_generic.h"

int main()
{
	int a0 = 0;
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	
	list test = ll_init(&a0);

	ll_push(&test, &a1);
	ll_push(&test, &a2);
	ll_push(&test, &a3);

	int a_insert = 68;
	ll_insert(&test, &a_insert, 1);
	//ll_insert(&test, &a_insert, 0);
	ll_insert(&test, &a_insert, 4);
	ll_insert(&test, &a_insert, 3);
	ll_insert(&test, &a_insert, 2);
	ll_insert(&test, &a_insert, 0);

	ll_print_ints(&test); // 68 0 68 68 1 68 2 68 3 

	void* zeroth = ll_get(&test, 0);
	void* first = ll_get(&test, 1);
	void* second = ll_get(&test, 2);
	void* third = ll_get(&test, 3);
	void* eighth = ll_get(&test, 8);
	ll_push(&test, &a0);
	void* ninth = ll_get(&test, 9);
	printf("Getting 0-th element: %d\n", *(int*)zeroth);
	printf("Getting 1-th element: %d\n", *(int*)first);
	printf("Getting 2-th element: %d\n", *(int*)second);
	printf("Getting 3-th element: %d\n", *(int*)third);
	printf("Getting 8-th element: %d\n", *(int*)eighth);
	printf("Getting 9-th element: %d\n", *(int*)ninth);

	return 0;
}
        //int answer = 5;
        //printf("answer = %d\n", answer); 
        //answer = ll_is_member(&test, &a0, sizeof(int));
        //printf("answer = %d\n", answer); 
        //answer = ll_is_member(&test, &a1, sizeof(int));
        //printf("answer = %d\n", answer); 
        //answer = ll_is_member(&test, &a2, sizeof(int));
        //printf("answer = %d\n", answer); 
        //answer = ll_is_member(&test, &a3, sizeof(int));
        //printf("answer = %d\n", answer); 
        //int fake = 77;
        //answer = ll_is_member(&test, &fake, sizeof(int));
        //printf("answer = %d\n", answer); 
	//ll_pop(&test);
	//ll_pop(&test);
	//ll_pop(&test);
	//ll_pop(&test);

