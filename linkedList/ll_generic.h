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
static list* get_last(list*);
