#include <stdio.h>
#include "stack_int.h"

static void stack_print(stack *s)
{
	printf("[ ");
	for (int i = 0; i < s->length; i++){
		printf("%d, ", s->elems[i]);
	}
	printf("]; len = %d, alloc_len = %d\n", s->length, s->alloc_length);
}

int main(int argc, char **argv)
{
	stack s;
	stack_init(&s);
	for (int i = 0; i < 17; i++){
		stack_push(&s, i*i);
		stack_print(&s);
	}
	for (int i = 0; i < 17; i++){
		stack_pop(&s);
		stack_print(&s);
	}
	stack_dispose(&s);
	stack_print(&s);
}
