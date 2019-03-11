#include "ll_generic.h"

static list* get_last(list*);

list ll_init(void *val)
{
	list new_list;
	new_list.child = NULL;
	memcpy(&(new_list.value), &val, sizeof(void *));
	return new_list;
}

static list* get_last(list *l)
{
	list *tmp = l;
	while(tmp->child != NULL)
		tmp = tmp->child;
	return tmp;
}

void ll_push(list *l, void *val)
{
	list *tmp = get_last(l);
	tmp->child = malloc(sizeof(list));
	if (!(tmp->child)) exit(EXIT_FAILURE);
	memcpy(&(tmp->child->value), &val, sizeof(void *));
	tmp->child->child = NULL;
}

void ll_pop(list *l)
{
	if(!(l->child)){
		fprintf(stderr, "ll_pop: popping off an empty list\n");
		exit(EXIT_FAILURE);
	}
	list *tmp = l;
	list *tmp2;
	while(tmp->child != NULL){
		tmp2 = tmp;
		tmp = tmp->child;
	}
	free(tmp2->child);
	tmp2->child = NULL;
}	

int ll_is_member(list *l, void *val, size_t elemSize)
{
	list *tmp = l;
	int index = 0;
        do{
            if (memcmp(tmp->value, val, elemSize) == 0)
                    return index;
            ++index;
            } while((tmp = tmp->child) != NULL);
        return NOT_FOUND;
}

void ll_insert(list *l, void *val, int index)
{
	if (index == 0){
		void *tmpval = l->value;
		list *tmpaddr = l->child;
		memcpy(&(l->value), &val, sizeof(void *));
		l->child = malloc(sizeof(list));
		memcpy(&(l->child->value), &tmpval, sizeof(void *));
		l->child->child = tmpaddr;
		return;
	}
	list *tmp = l;
	list *tmp2;
	int current = 0;
	while(tmp->child != NULL && index > current){
		tmp2 = tmp;
		tmp = tmp->child;
		++current;
	}
	tmp2->child = malloc(sizeof(list));
	if (!(tmp2->child)) exit(EXIT_FAILURE);
	tmp2->child->child = tmp;
	memcpy(&(tmp2->child->value), &val, sizeof(void *));
}

void ll_print_ints(list *l)
{
	list *tmp = l;
	while(tmp->child != NULL){
		printf("%d\n", *(int*)tmp->value);
		tmp = tmp->child;
	}
	printf("%d\n", *(int*)tmp->value);
}
