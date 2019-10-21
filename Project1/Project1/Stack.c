#include"Stack.h"
//初始化栈
void StackInit(Stack* st)
{
	assert(st);
	st->_a = NULL;
	st->_capacity = 0;
	st->_top = 0;
}
//销毁栈
void StackDestory(Stack* st)
{
	assert(st);
	free(st->_a);
	st->_a = NULL;
	st->_capacity = 0;
	st->_top = 0;
}
//入栈
void StackPush(Stack* st, DataType x)
{
	assert(st);
	//检查容量
	if (st->_capacity == st->_top)
	{
		//如果第一次插入则为其分配10个空间
		//否则分配原空间的二倍
		DataType* p = st->_a;
		size_t newcapacity = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		p = (DataType*)realloc(st->_a, sizeof(DataType) * newcapacity);
		if (p != NULL)
			st->_a = p;
		st->_capacity = newcapacity;
	}
	//插入
	st->_a[st->_top++] = x;
}
//出栈
void StackPop(Stack* st)
{
	assert(st);
	if (st->_top > 0)
		st->_top--;
}
//获取栈顶元素
DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top-1];
}
//求栈中元素个数
size_t StackSize(Stack* st)
{
	assert(st);
	if (st->_top > 0)
		return st->_top;
	else
		return 0;
}
//判断栈是否为空
int StackEmpty(Stack* st)
{
	assert(st);
	if (st->_top == 0)
		return 1;
	else
		return 0;
}
//打印栈中元素
//void StackPrint(Stack* st)
//{
//	assert(st);
//	while (StackEmpty(st) == 0)
//	{
//		printf("%d ", StackTop(st));
//		StackPop(st);
//	}
//	printf("\n");
//}
//void TestStack()
//{
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, 5);
//	StackPush(&st, 4);
//	StackPush(&st, 3);
//	StackPush(&st, 2);
//	StackPush(&st, 1);
//	int size = StackSize(&st);
//	printf("size=%d\n", size);
//	//StackPrint(&st);
//	int top = StackTop(&st);
//	printf("top=%d\n", st._top);
//	StackPop(&st);
//	top = StackTop(&st);
//	printf("top=%d\n", st._top);
//	StackPop(&st);
//	top = StackTop(&st);
//	printf("top=%d\n", st._top);
//	StackPop(&st);
//	top = StackTop(&st);
//	printf("top=%d\n", st._top);
//	StackPop(&st);
//	top = StackTop(&st);
//	printf("top=%d\n", st._top);
//	StackPop(&st);
//
//}
//int main()
//{
//	TestStack();
//	return 0;
//}