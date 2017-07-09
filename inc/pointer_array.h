#pragma once

typedef struct _tagPointerArray
{
	void **elements;
	int length;

} PointerArray;

PointerArray *pa_alloc();						// allocate a pointer array object
void pa_free(PointerArray *na);					// free pointer array
void pa_push(PointerArray *na, void *element);	// push a pointer to the array

