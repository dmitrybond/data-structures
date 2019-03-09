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
        int answer = 5;
        printf("answer = %d\n", answer); 
        answer = ll_is_member(&test, &a0, sizeof(int));
        printf("answer = %d\n", answer); 
        answer = ll_is_member(&test, &a1, sizeof(int));
        printf("answer = %d\n", answer); 
        answer = ll_is_member(&test, &a2, sizeof(int));
        printf("answer = %d\n", answer); 
        answer = ll_is_member(&test, &a3, sizeof(int));
        printf("answer = %d\n", answer); 
        int fake = 77;
        answer = ll_is_member(&test, &fake, sizeof(int));
        printf("answer = %d\n", answer); 
	//ll_pop(&test);
	//ll_pop(&test);
	//ll_pop(&test);
	//ll_pop(&test);

	ll_print_ints(&test);

	return 0;
}
