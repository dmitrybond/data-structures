//#include <stdio.h>
#include "linked_list.h"

int main(){
    list test;
    ll_init(&test);

    ll_print(&test);

    for (int i = 0; i < 5; ++i){
        ll_append(&test, i*i);
        ll_print(&test);
        printf("Size is %d\n", test.sz);
    }

     ll_pop(&test);
     ll_pop(&test);
     ll_pop(&test);
     ll_print(&test);
     printf("Size is %d\n", test.sz);
     ll_set(&test, 0, 11);
     ll_set(&test, 1, 22);
     ll_set(&test, 2, 33);
     ll_set(&test, 3, 44);
     ll_set(&test, 4, 55);
     ll_dispose(&test);
     ll_print(&test);
     ll_set(&test, 5, 66);

     for (int i = 0; i < 5; ++i){
         ll_rm(&test, 0);
         ll_print(&test);
     }

    ll_insert(&test, 3, 333);
    ll_print(&test);
    ll_insert(&test, 1, 111);
    ll_print(&test);
    ll_insert(&test, 7, 777);
    ll_print(&test);
    ll_insert(&test, 0, 1000);
    ll_print(&test);

    printf("********\n");
    for (int i = 0; i < test.sz; ++i)
        printf("test[%d] = %d\n", i, ll_get(&test, i));

    printf("List size is %d\n", ll_size(&test));
     node *tmp = test.parent;
     while(tmp != NULL)
         tmp = tmp -> child;

    for (int i = 0; i < 9; ++i){
        ll_pop(&test);
        ll_print(&test);
    }
    
    
     printf("Value is %d; size is %d\n", test.parent -> value, test.sz);
     printf("Value is %d; size is %d\n", test.parent -> child -> value, test.sz);
     printf("Value is %d; size is %d\n", test.parent -> child -> child -> value, test.sz);
     printf("Value is %d; size is %d\n", test.parent -> child -> child -> child -> value, test.sz);
     printf("Peeking: last value is %d\n", ll_peek(&test)); 

}
