#include <stdlib.h>
#include "stack_int.h"
#include "assert.h"

static void stack_grow(stack *s)
{
	s->alloc_length *= GROWTH_RATE;
	s->elems = realloc(s->elems, s->alloc_length * sizeof(int)); 
	assert(s->elems);
}

void stack_init(stack *s)
{
	s->elems = malloc(BASE_SIZE * sizeof(int));
	assert(s->elems);
	s->alloc_length = BASE_SIZE;
	s->length = 0;
}

void stack_push(stack *s, int value)
{
	assert(s->alloc_length % BASE_SIZE == 0 && s->elems && s->length >= 0);
	if (s->length == s->alloc_length){
		stack_grow(s);
	}
	s->elems[s->length++] = value;
}

void stack_pop(stack *s)
{
	assert(s->length>0);
	if (s->length == 1){
		s->elems = realloc(s->elems, BASE_SIZE * sizeof(int));
		assert(s->elems);
		s->length--;
		s->alloc_length = BASE_SIZE;
		return;
	}
	if(s->alloc_length % (s->length - 1) == 0 && s->length > BASE_SIZE){
		s->alloc_length /= GROWTH_RATE;
		s->elems = realloc(s->elems, s->alloc_length * sizeof(int));
		assert(s->elems);
	}
	s->length--;
}

void stack_dispose(stack *s)
{
	/* destructor needs to be ALWAYS called before leaving the scope to
	 * avoid memory leaks. Note, even though popping off all elements
	 * from the stack returns most of the memory, an empty stack will
	 * still own memory for BASE_SIZE elements. Hence, stack_dispose
	 * needs to be called even on a seemingly empty stack.
	 */
	free(s->elems);
	s->elems = NULL;
	s->alloc_length = 0;
	s->length = 0;
}
