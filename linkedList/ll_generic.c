#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    struct node *child;
    void *value;
} list;

static list *get_last(list*);

list ll_init(void* val)
{
	list new_list;
	new_list.child = NULL;
	memcpy(&(new_list.value), &val, sizeof(void *));
	return new_list;
}

void ll_push(list *l, void *val)
{
	list *tmp = get_last(l);
	tmp -> child = malloc(sizeof(list)); // check NULL FIXME
	if (!(tmp -> child)) exit(1);
	memcpy(&(tmp -> child -> value), &val, sizeof(void *));
	tmp -> child -> child = NULL;
}

void ll_pop(list *l)
{
	if(!(l -> child)){
		fprintf(stderr, "ll_pop: popping off an empty list\n");
		exit(EXIT_FAILURE);
	}
	list *tmp = l;
	list *tmp2;
	while(tmp -> child != NULL){
		tmp2 = tmp;
		tmp = tmp -> child;
	}
	free(tmp2 -> child);
	tmp2 -> child = NULL;
}	

static list* get_last(list *l)
{
	list *tmp = l;
	while(tmp -> child != NULL)
		tmp = tmp -> child;
	return tmp;
}

void ll_print_ints(list *l)
{
	list *tmp = l;
	while(tmp -> child != NULL){
		printf("%d\n", *(int*)tmp -> value);
		tmp = tmp -> child;
	}
	printf("%d\n", *(int*)tmp -> value);
}

int main()
{
	int a0 = 0;
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	
	list test = ll_init(&a0);
	
	ll_push(&test, &a1);
	ll_push(&test, &a2);
	ll_push(&test, &a3);
	ll_pop(&test);
	ll_pop(&test);
	ll_pop(&test);
	ll_pop(&test);

	ll_print_ints(&test);

	return 0;
}
