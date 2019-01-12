#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int payload;
    int* next;
} node;

typedef struct{
    int* first_pointer;
    int loglength;
} linkedlist;


void ll_new(linkedlist *ll);
void ll_dispose(linkedlist *ll);
void ll_add(linkedlist *ll, node *n, int value);
void ll_remove(linkedlist *ll);
void ll_traverse(linkedlist *ll);

void ll_new(linkedlist *ll, node *n){
    ll -> first_pointer = n -> next;

void ll_traverse(linkedlist *ll){
    while(n -> next != NULL)

void ll_add(node *p, int value, int* pointer){
    p -> payload = value;
    p -> next = pointer;
}

void remove_node(node *p, 

int main(){
    return 0;
}
