#include<stdio.h>
typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	size_t _top;//Õ»¶¥
	size_t _capacity;//ÈÝÁ¿
}Stack;
void StackInit(Stack* st);
void StackDestory(Stack* st);
void StackPush(Stack* st,DataType x);
void StackPop(Stack* st);
DataType StackTop(Stack* st);
size_t StackSize(Stack* st);
int StackEmpty(Stack* st);
void StackPrint(Stack* st);
void TestStack();
