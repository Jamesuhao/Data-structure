#include"Stack.h"
//��ʼ��ջ
void StackInit(Stack* st)
{
	assert(st);
	st->_a = NULL;
	st->_capacity = 0;
	st->_top = 0;
}
//����ջ
void StackDestory(Stack* st)
{
	assert(st);
	free(st->_a);
	st->_a = NULL;
	st->_capacity = 0;
	st->_top = 0;
}
//��ջ
void StackPush(Stack* st, DataType x)
{
	assert(st);
	//�������
	if (st->_capacity == st->_top)
	{
		//�����һ�β�����Ϊ�����10���ռ�
		//�������ԭ�ռ�Ķ���
		DataType* p = st->_a;
		size_t newcapacity = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		p = (DataType*)realloc(st->_a, sizeof(DataType) * newcapacity);
		if (p != NULL)
			st->_a = p;
		st->_capacity = newcapacity;
	}
	//����
	st->_a[st->_top++] = x;
}
//��ջ
void StackPop(Stack* st)
{
	assert(st);
	if (st->_top > 0)
		st->_top--;
}
//��ȡջ��Ԫ��
DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top-1];
}
//��ջ��Ԫ�ظ���
size_t StackSize(Stack* st)
{
	assert(st);
	if (st->_top > 0)
		return st->_top;
	else
		return 0;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* st)
{
	assert(st);
	if (st->_top == 0)
		return 1;
	else
		return 0;
}
//��ӡջ��Ԫ��
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