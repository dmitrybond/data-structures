#include <stdio.h>
#include "stack.h"

static void print_int(stack *s, int index)
{
	printf("%d, ", **((int**)s->elems + index));
}

static void print_str(stack *s, int index)
{
	printf("%s, ", **((char***)s->elems + index));
}

static void stack_print(stack *s, void (*prnt)(stack*, int))
{
	printf("[ ");
	for (int i = 0; i < s->length; i++){
		(*prnt)(s, i);
	}
	printf("]; len = %d, alloc_len = %d\n", s->length, s->alloc_length);
}

int main(int argc, char **argv)
{
	/* Test ints */
	stack s1;
	stack_init(&s1, sizeof(int*));
	printf("Initializing stack of ints:\n");
	stack_print(&s1, &print_int);
	int tmp[10];
	for (int i = 0; i < 10; i++)
		tmp[i] = i*i;

	printf("Pushing elements on the stack:\n");
	for (int i = 0; i < 10; i++){
		stack_push(&s1, &(tmp[i]), sizeof(int*));
		stack_print(&s1, &print_int);
	}
	printf("Popping elements off the stack:\n");
	for (int i = 0; i < 3; i++){
		stack_pop(&s1, sizeof(int*));
		stack_print(&s1, &print_int);
	}
	printf("Destroying the stack\n");
	stack_dispose(&s1);
	stack_print(&s1, &print_int);

	/* Test strings */
	stack s2;
	stack_init(&s2, sizeof(char**));
	printf("Initializing stack of strings:\n");
	stack_print(&s2, &print_str);
	char* tmp2[] = {"dude", "Goddam!", "what's", "up", "mate", "how", "ya",
	"doing'", "mate", "?"};
	printf("Pushing elements on the stack:\n");
	for (int i = 0; i < 10; i++){
		stack_push(&s2, &(tmp2[i]), sizeof(char**));
		stack_print(&s2, &print_str);
	}
	printf("Popping elements off the stack:\n");
	for (int i = 0; i < 3; i++){
		stack_pop(&s2, sizeof(char**));
		stack_print(&s2, &print_str);
	}
	printf("Destroying the stack\n");
	stack_dispose(&s2);
	stack_print(&s2, &print_str);
}
