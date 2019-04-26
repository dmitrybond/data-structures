#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ht.h"
#include "prime.h"

static unsigned int hash(char *, int, int);

table ht_init(void)
{
	table init;
	init.items = calloc(BASE_SIZE, sizeof(item*));
	init.size = BASE_SIZE;
	init.count = 0;
	return init;
}

static unsigned int hash(char *key, int prime, int size)
{
	unsigned int hash = 0;
	int len = strlen(key);
	for (int i = 0; i < len; i++)
		hash += (unsigned int)pow(prime, (len - 1) - i) * key[i];
	hash %= size;
	return hash;
}

void ht_push(table *tab, char *key, char *val)
{
	int tmpprime = BASE_PRIME;
	unsigned int index = hash(key, tmpprime, tab->size);
	while (tab->items[index] != NULL){ // fingers crossed we'll get out of it
		tmpprime = nextprime(tmpprime);
		index = hash(key, tmpprime, tab->size);
	}
	tab->items[index] = malloc(sizeof(item));
	tab->items[index]->key = key;
	tab->items[index]->val = val;
	tab->count++;
}

void ht_pop(table *tab, char *key)
{
	int tmpprime = BASE_PRIME;
	unsigned int index = hash(key, tmpprime, tab->size);
	for (int i = 0; i < tab->size; i++)
		if (tab->items[i] != NULL)
			if (strcmp(key, tab->items[i]->key) == 0)
	while(memcmp(key, tab->items[index]->key, strlen(key)) != 0){ // inf loop if wrong index
		tmpprime = nextprime(tmpprime);
		index = hash(key, tmpprime, tab->size);
	}
	free(tab->items[index]->key); // need to free key and value
	free(tab->items[index]->val); // but not the tab->items[index]
	tab->items[index] = NULL; // it should only be marked as free to use, i.e. NULL
	tab->count--;
}

char *ht_get(table *tab, char *key)
{
	for (int i = 0; i < tab->size; i++)
		if (tab->items[i] != NULL)
			if (strcmp(key, tab->items[i]->key) == 0)
				return tab->items[i]->val;
	return NULL;
}
