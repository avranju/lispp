#include "stddefs.h"
#include "pointer_array.h"

PointerArray *pa_alloc()
{
	PointerArray *pa = (PointerArray *)malloc(sizeof(PointerArray));
	pa->elements = NULL;
	pa->length = 0;

	return pa;
}

void pa_free(PointerArray *pa)
{
	if(pa)
	{
		if(pa->elements)
			free(pa->elements);
		free(pa);
	}
}

void pa_push(PointerArray *pa, void *element)
{
	if(!pa || !element)
		return;

	pa->elements = realloc(pa->elements, ++(pa->length) * sizeof(void *));
	pa->elements[pa->length - 1] = element;
}
