#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    struct node *child;
    void *value;
} list;

list ll_init(void*);
void ll_push(list*, void*);
void ll_pop(list*);
int ll_is_member(list*, void*, size_t);
void ll_insert(list*, void*, int);
void ll_print_ints(list*);
