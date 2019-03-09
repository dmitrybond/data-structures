#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    struct node *child;
    void *value;
} list;

list ll_init(void*);
static list* get_last(list*);
void ll_push(list*, void*);
void ll_pop(list*);
int ll_is_member(list*, void*, size_t);
void ll_print_ints(list*);
