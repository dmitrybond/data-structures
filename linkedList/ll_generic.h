#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    struct node *child;
    void* value;
} node;

typedef struct{
    node *parent;
    int sz;
} list;

void ll_init(list*);
void ll_append(list*, void *val);
void ll_push_start(list*, void *val);
void ll_pop(list*);
void ll_set(list*, int index, void *val);
void ll_dispose(list*);
void ll_rm(list*, int index);
void ll_insert(list*, int index, void *val);
void ll_print(list*);
void* ll_get(list*, int index);
void* ll_peek(list*);
void* ll_size(list*);
