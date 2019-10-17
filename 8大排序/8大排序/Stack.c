#include"Stack.h"
#include<malloc.h>
#include<assert.h>
void StackInit(Stack* st)
{
	assert(st);
	st->_a = NULL;
	st->_capacity = st->_top = 0;
}
void StackDestory(Stack* st)
{
	assert(st);
	free(st->_a);
	st->_capacity = st->_top = 0;
}
void StackPush(Stack* st,DataType x)
{
	assert(st);
	//ÈëÕ»£ºË³Ðò±íµÄÎ²²å
	//¼ì²éÈÝÁ¿
	if (st->_top == st->_capacity)
	{
		DataType* p=st->_a;
		size_t newcapacity = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		p = (DataType*)realloc(st->_a, newcapacity * sizeof(DataType));
		if (p != NULL)
			st->_a = p;
		st->_capacity = newcapacity;
	}
	//²åÈë
	st->_a[st->_top++] = x;
}
void StackPop(Stack* st)
{
	assert(st);
	//³öÕ»£ºË³Ðò±íÎ²É¾
	if (st->_top > 0)
	{
		--st->_top;
	}
}
DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top - 1];
}
size_t StackSize(Stack* st)
{
	assert(st);
	return st->_top;
}
int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}
void StackPrint(Stack* st)
{
	assert(st);
	while (StackEmpty(st) == 0)
	{
		printf("%d ", StackTop(st));
		StackPop(st);
	}
	printf("\n");
}
