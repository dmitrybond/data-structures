#include <stdlib.h>
#include <string.h>
#include "assert.h"

#include "stack.h"

static void stack_grow(stack *s, size_t elem_size)
{
	s->alloc_length *= GROWTH_RATE;
	s->elems = realloc(s->elems, s->alloc_length * elem_size); 
	assert(s->elems);
}

void stack_init(stack *s, size_t elem_size)
{
	s->elems = malloc(BASE_SIZE * elem_size);
	s->alloc_length = BASE_SIZE;
	s->length = 0;
}

void stack_push(stack *s, void *value, size_t elem_size)
{
	assert(s->alloc_length % BASE_SIZE == 0 && s->elems && s->length >= 0);
	if (s->length == s->alloc_length){
		stack_grow(s, elem_size);
	}
	memcpy((char*)(s->elems) + elem_size * (s->length), &value, elem_size);
	s->length++;
}

void stack_pop(stack *s, size_t elem_size)
{
	assert(s->length>0);
	if (s->length == 1){
		s->elems = realloc(s->elems, BASE_SIZE * elem_size);
		assert(s->elems);
		s->length--;
		s->alloc_length = BASE_SIZE;
		return;
	}
	if(s->alloc_length % (s->length - 1) == 0 && s->length > BASE_SIZE){
		s->alloc_length /= GROWTH_RATE;
		s->elems = realloc(s->elems, s->alloc_length * elem_size);
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
