#ifndef __ILRD_OL127_128_VECTOR_H__
#define __ILRD_OL127_128_VECTOR_H__

#include <stddef.h> /* size_t */
#include "utils.h"




typedef struct vector vector_ty;

vector_ty *VectorCreate(size_t element_amount, size_t element_size);

void VectorDestroy(vector_ty *vector);

size_t VectorSize(const vector_ty *vector);

size_t VectorCapacity(const vector_ty *vector);

status_ty VectorResize(vector_ty *vector, size_t new_element_amount); 

status_ty VectorPushBack(vector_ty *vector, const void *data);

void VectorPopBack(vector_ty *vector);

void *VectorGetElement(const vector_ty *vector, size_t index);

status_ty VectorIsEmpty(const vector_ty *vector);

/* Advanced */
void VectorSetElement(vector_ty *vector, size_t index, void *data);

#endif /* __ILRD_OL127_128_VECTOR_H__ */
