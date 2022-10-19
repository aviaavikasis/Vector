/*****************************************************   
 * Author : Avia Avikasis                            *
 * Reviewer: Maor Fakliro                            *
 * 7/06/2022                                         *
 * Description : imlementation of vector data        *
 * structure.                                        *
 *                                                   *
 *****************************************************/

#include "vector.h"
#include <stdlib.h>  /* malloc,realloc */
#include <string.h>  /* memcpy */
#include <assert.h>  /* assert */

struct vector
{
 	char* begin;
    char* end;
    size_t element_size;
    size_t capacity;
};


vector_ty *VectorCreate(size_t element_amount, size_t element_size)
{
	vector_ty *vector = (vector_ty*)malloc(sizeof(vector_ty));
	assert(NULL != vector);
	vector -> capacity = element_amount * element_size;
	vector -> begin = (char*)malloc(vector -> capacity);
	assert(NULL != vector -> begin);
	vector -> end = vector -> begin;
	vector -> element_size = element_size;

	return vector;	
}


void VectorDestroy(vector_ty *vector)
{
	assert(NULL != vector);
	free(vector -> begin);
	free(vector);	
}


size_t VectorSize(const vector_ty *vector)
{
	assert(NULL != vector);
	return (vector -> end - vector -> begin) / vector -> element_size; 
}


size_t VectorCapacity(const vector_ty *vector)
{
	assert(NULL != vector);
	return vector -> capacity;	
}


status_ty VectorResize(vector_ty *vector, size_t new_element_amount)
{
	assert(NULL != vector);
	if (new_element_amount < VectorSize(vector))
	{
		return FAIL;
	}
	vector -> begin = realloc(vector -> begin , new_element_amount);
    vector -> capacity = new_element_amount * vector -> element_size;
	return (vector -> begin == NULL) ? FAIL : SUCCESS; 
}


status_ty VectorPushBack(vector_ty *vector, const void *data)
{
	assert(NULL != vector);
	assert(NULL != data);
	
	if ( (VectorSize(vector) + 1) * (vector -> element_size) >= vector -> capacity)
	{
		VectorResize(vector , VectorSize(vector) * 2);
	}
	memcpy(vector -> end , data , vector -> element_size);
	(vector -> end) += (vector -> element_size);
	 
	return SUCCESS;		
}


void VectorPopBack(vector_ty *vector)
{
	assert(NULL != vector);
	vector -> end -= vector -> element_size;	
}


void *VectorGetElement(const vector_ty *vector, size_t index)
{
	assert(NULL != vector);
	return	(void*)(vector -> begin + vector -> element_size * index);
}


status_ty VectorIsEmpty(const vector_ty *vector)
{
	assert(NULL != vector);
	return (vector -> begin == vector -> end) ? SUCCESS : FAIL;
}



















