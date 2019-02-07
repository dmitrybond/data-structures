#include "stack.h"

void init(stack *s){
    s -> alloc_sz = BASE;
    s -> curr_sz = 0;
    s -> location = malloc(BASE*sizeof(int));
    if (!(s -> location)) exit(1);
}

void push(stack *s, int val){
    if (s -> curr_sz == s -> alloc_sz) grow(stack *s);
    *(s -> location + s -> curr_sz) = val;
    ++(s -> curr_sz);
}    

void pop(stack *s){
    --(s -> curr_sz);
}

void dispose(stack *s){
    free(s -> location);
    s -> alloc_sz = 0;
    s -> curr_sz = 0;
}

int peek(stack *s){
    return *(s -> location + s -> curr_sz);
}

static void grow(stack *s){
        s -> location = realloc(s -> location, GROWTH*BASE*sizeof(int));
        s -> alloc_sz *= GROWTH;
}


int main(){
    stack test;
    init(&test);
    for (int i = 0; i < 61; ++i)
        push(&test, i*i);
    printf("Current sz is %d; Alloc sz is %d\n", test.curr_sz, test.alloc_sz);
    for (int i = 0; i < 61; ++i){
        pop(&test);
        printf("Last value is %d\n", peek(&test));
    }
}
