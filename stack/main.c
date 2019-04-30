#include <stdio.h>
#include "stack.h"

static void stack_print(stack *s, size_t elem_size)
{
	printf("[ ");
	for (int i = 0; i < s->length; i++){
		printf("%d, ", **(int**)s->elems + i);
	}
	printf("]; len = %d, alloc_len = %d\n", s->length, s->alloc_length);
}

int main(int argc, char **argv)
{
	stack s;
	stack_init(&s, sizeof(int*));
	int tmp = {5,6,7};
	for (int i = 0; i < 3; i++){
		stack_push(&s, &tmp[i], sizeof(int*));
		stack_print(&s, sizeof(int*));
	}
	for (int i = 0; i < 3; i++){
		stack_pop(&s, sizeof(int*));
		stack_print(&s, sizeof(int*));
	}
	stack_dispose(&s);
	stack_print(&s, sizeof(int*));
}
