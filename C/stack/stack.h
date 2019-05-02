#define BASE_SIZE 4
#define GROWTH_RATE 2

/* Genertic stack implementation */

typedef struct{
	void *elems;
	int length;
	int alloc_length;
} stack;

void stack_init(stack*, size_t);
void stack_dispose(stack*);
void stack_push(stack*, void*, size_t);
void stack_pop(stack*, size_t);
