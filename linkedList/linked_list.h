#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    struct node *child;
    int value;
} node;

typedef struct{
    node *parent;
    int sz;
} list;

void ll_init(list*);
void ll_append(list*, int val);
void ll_push_start(list*, int val);
void ll_pop(list*);
void ll_set(list*, int index, int val);
void ll_dispose(list*);
void ll_rm(list*, int index);
void ll_insert(list*, int index, int val);
void ll_print(list*);
int ll_get(list*, int index);
int ll_peek(list*);
int ll_size(list*);
