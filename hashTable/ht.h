#define BASE_SIZE 32
#define BASE_PRIME 157

typedef struct{
	char *key;
	char *val;
} item;

typedef struct{
	int size;
	int count;
	item **items;
} table;

table ht_init(void);
void ht_push(table*, char*, char*);
void ht_pop(table*, char*);
char *ht_get(table*, char*);
