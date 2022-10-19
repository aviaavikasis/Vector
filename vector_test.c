#include "vector.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void VectorCreateTest();
void VectorSizeTest();
void VectorCapacityTest();
void VectorResizeTest();
void VectorPushBackTest();
void VectorPopBackTest();
void VectorGetElementTest();
void VectorIsEmptyTest();


int main()
{

	VectorCreateTest();
	VectorSizeTest();
	VectorCapacityTest();
	VectorResizeTest();
	VectorPushBackTest();
	VectorPopBackTest();
	VectorGetElementTest();
	VectorIsEmptyTest();
	
	printf("\n\n------------SUCCESS!!!-------------\n\n");
	
	return 0;
}


void VectorCreateTest()
{
	size_t element_amount = 10;
	size_t element_size = 4;
	vector_ty *vector = VectorCreate(element_amount , element_size);
	assert(VectorIsEmpty(vector) == 0);
	VectorDestroy(vector);
}


void VectorSizeTest()
{
	size_t element_amount = 10;
	size_t element_size = 8;
	unsigned long a = 15448465456;
	unsigned long b = 34546546545;
	unsigned long c = 58412155454;
	unsigned long d = 12121342424;
	vector_ty *vector = VectorCreate(element_amount , element_size);
	
	VectorPushBack(vector , (const void*)&a);
	VectorPushBack(vector , (const void*)&b);
	VectorPushBack(vector , (const void*)&c);
	VectorPushBack(vector , (const void*)&d);
	assert(VectorSize(vector) == 4);
	VectorDestroy(vector);	
}


void VectorCapacityTest()
{
	size_t element_amount = 8;
	size_t element_size = 5;
	vector_ty *vector = VectorCreate(element_amount , element_size);
	assert(VectorCapacity(vector) == 40);
	VectorDestroy(vector);
}


void VectorResizeTest()
{
	size_t element_amount = 3;
	size_t element_size = 4;
	int a = 2;
	int b = 3;
	int c = 4;
	int d = 6;
	int e = 8;
	vector_ty *vector = VectorCreate(element_amount , element_size);
	
	VectorPushBack(vector , (const void*)&a);
	VectorPushBack(vector , (const void*)&b);
	VectorPushBack(vector , (const void*)&c);
	VectorPushBack(vector , (const void*)&d);
	VectorPushBack(vector , (const void*)&e);
	assert(VectorCapacity(vector) == 24);
	VectorDestroy(vector);	

}



void VectorPushBackTest()
{
	size_t element_amount = 3;
	size_t element_size = 4;
	int a = 2;
	int b = 3;
	int c = 4;
	int d = 6;
	int e = 8;
	vector_ty *vector = VectorCreate(element_amount , element_size);
	
	VectorPushBack(vector , (const void*)&a);
	VectorPushBack(vector , (const void*)&b);
	VectorPushBack(vector , (const void*)&c);
	VectorPushBack(vector , (const void*)&d);
	assert( *((int*)VectorGetElement(vector , 3)) == 6);
	VectorPushBack(vector , (const void*)&e);
	assert( *((int*)VectorGetElement(vector , 4)) == 8);
	VectorDestroy(vector);

}


void VectorPopBackTest()
{
	size_t element_amount = 10;
	size_t element_size = 4;
	int a = 2;
	int b = 3;
	int c = 4;
	vector_ty *vector = VectorCreate(element_amount , element_size);

	VectorPushBack(vector , (void*)&a);
	VectorPushBack(vector , (void*)&b);
	VectorPushBack(vector , (void*)&c);	
	VectorPopBack(vector);
	assert( *((int*)VectorGetElement(vector , 1)) == 3);
	VectorPopBack(vector);
	assert( *((int*)VectorGetElement(vector , 0)) == 2);
	VectorDestroy(vector);
}


void VectorGetElementTest()
{
	size_t element_amount = 10;
	size_t element_size = 2;
	short a = 1;
	short b = 3;
	short c = 5;
	short d = 7;
	vector_ty *vector = VectorCreate(element_amount , element_size);

	VectorPushBack(vector , (const void*)&a);
	VectorPushBack(vector , (const void*)&b);
	VectorPushBack(vector , (const void*)&c);
	VectorPushBack(vector , (const void*)&d);
	assert( *((short*)VectorGetElement(vector , 3)) == 7);
	VectorPopBack(vector);
	assert( *((short*)VectorGetElement(vector , 2)) == 5);
	VectorDestroy(vector);	
}


void VectorIsEmptyTest()
{
	size_t element_amount = 10;
	size_t element_size = 1;
	char b = 23;
	char c = 45;
	vector_ty *vector = VectorCreate(element_amount , element_size);
	
	VectorPushBack(vector , (const void*)&b);
	VectorPushBack(vector , (const void*)&c);
	VectorPopBack(vector);
	VectorPopBack(vector);
	assert(VectorIsEmpty(vector) == 0);
	VectorDestroy(vector);
}


















