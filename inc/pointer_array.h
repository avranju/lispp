#ifndef POINTER_ARRAY_H

typedef struct _tagPointerArray
{
	void **elements;
	int length;

} PointerArray;

PointerArray *pa_alloc();						// allocate a pointer array object
void pa_free(PointerArray *na);					// free pointer array
void pa_push(PointerArray *na, void *element);	// push a pointer to the array

#endif // !POINTER_ARRAY_H