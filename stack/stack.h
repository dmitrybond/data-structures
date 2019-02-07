#include <stdio.h>
#include <stdlib.h>
#define BASE 4
#define GROWTH 2

typedef struct{
    int curr_sz;
    int alloc_sz;
    int *location;
} stack;

void init(stack*, int val);
void pop(stack*);
void dispose(stack*);
int peek(stack*);
static void grow(stack*);
