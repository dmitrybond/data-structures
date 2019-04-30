#define BASE_SIZE 4
#define GROWTH_RATE 2

typedef struct{
	int *elems;
	int length;
	int alloc_length;
} stack;

void stack_init(stack*);
void stack_dispose(stack*);
void stack_push(stack*, int);
void stack_pop(stack*);
