#include <stdio.h>
#include <stdlib.h>
#define BASE 4
#define GROWTH 2

typedef struct{
    int curr_sz;
    int alloc_sz;
    int *location;
} stack;

void init(stack*);
void push(stack*, void* addr, int elem_sz);
void pop(stack*);
void dispose(stack*);
void peek(stack*);
static void expand(stack*);
