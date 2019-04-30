#include "ht.h"
#include <stdio.h>

int main()
{
	table test = ht_init();
	ht_push(&test, "dude", "Dimon");
	ht_push(&test, "dudess", "Hanna");
	ht_push(&test, "man", "SnoopDogg");
	ht_push(&test, "woman", "Scarlett");

	char *got1 = ht_get(&test, "dude");
	char *got2 = ht_get(&test, "dudess");
	char *got3 = ht_get(&test, "man");
	char *got4 = ht_get(&test, "woman");
	printf("%s\n", got1);
	printf("%s\n", got2);
	printf("%s\n", got3);
	printf("%s\n", got4);
	return 0;
}
	//char *k = test.items[10]->key;
	//char *v = (*(test.items + 10))->val;
