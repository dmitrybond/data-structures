#include <stdlib.h>
#include <string.h>
#include "assert.h"

#include "stack.h"

/* Remark: the destructor stack_dispose is naive in the sense that it will
 * NOT free memory occupied by the stack's elements, IF THESE ELEMENTS
 * LIVE ON THE HEAP. It is therefore assumed that all elements pushed
 * onto the stack are STATIC (as far as destruction goes, you can
 * obviously push anything, but it'll leak, unless you deallocate
 * yourself)
 *
 * A more technical implementation accounts for this subtlety.
 * I'm lazy to code this, but in words it goes something like this:
 * Let the stack_dispose take in one more argument - a
 * freeing function pointer. It is on behalf of the user to provide
 * a freeing function to correctly destroy his/her heap objects. If
 * the stack contains static elements, a user passes NULL as a freeing
 * function to inform that all stack data is static and hence doesn't
 * need any destruction beyond freeing stack.elems pointer.
 */

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
	assert(s->length > 0);
	/* release half of the memory if s->length before popping is one
	 * more than half of s->alloclength, except when s->length is less
	 * than BASE_SIZE, since that's the minimum stack size
	 */
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
	/* not sure if there's any benefit in zeroing out the stack,
	 * but what the hell
	 */
	s->elems = NULL;
	s->alloc_length = 0;
	s->length = 0;
}
