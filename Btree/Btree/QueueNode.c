#include"QueueNode.h"
#include<assert.h>
#include<malloc.h>
void QueueInit(Queue* p)
{
	assert(p);
	p->_front = p->_rear = NULL;
}
void QueueDestory(Queue* p)
{
	assert(p);
	QueueNode* cur = p->_front;
	while (cur)
	{
		p->_front = cur->_next;
		free(cur);
		cur = p->_front;
	}
	p->_rear = NULL;
}
//入队：队尾插入元素
void QueuePush(Queue* p, DataType x)
{
	assert(p);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;
	//判断是否为第一个插入的元素
	if (p->_front == NULL)
	{
		p->_front = p->_rear = newNode;
	}
	else
	{
		p->_rear->_next = newNode;
		p->_rear = p->_rear->_next;
	}
}
//出队：队头删除元素
void QueuePop(Queue* p)
{
	assert(p);
	if (p->_front)
	{
		QueueNode* next = p->_front->_next;
		//删除，出队
		free(p->_front);
		p->_front = next;
		//如果删除的为最后一个元素
		if (p->_front == NULL)
		{
			p->_rear = NULL;
		}
	}
	
}
//获取队头元素
DataType QueueFront(Queue* p)
{
	assert(p);
	if(p->_front)
		return p->_front->_data;
	return -1;
}
//获取队尾元素
DataType QueueBack(Queue* p)
{
	assert(p);
	return p->_rear->_data;
}
int QueueEmpty(Queue* p)
{
	assert(p);
	if (p->_front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int QueueSize(Queue* p)
{
	assert(p);
	QueueNode* cur = p->_front;
	int n = 0;
	while (cur)
	{
		++n;
		cur = cur->_next;
	}
	return n;
}
void Queueprint(Queue* p)
{
	assert(p);
	QueueNode* cur = p->_front;
	while (cur)
	{
		printf("%p ", cur->_data);
		cur = cur->_next;
	}
	//while (QueueEmpty(p) == 0)
	//{
	//	printf("%d ", QueueFront(p));
	//	QueuePop(p);
	//}
	printf("\n");
}
//void TestQueue()
//{
//	Queue p;
//	QueueInit(&p);
//	QueuePush(&p, 1);
//	QueuePush(&p, 2);
//	QueuePush(&p, 3);
//	QueuePush(&p, 4);
//	QueuePop(&p);
//	QueuePop(&p);
//	Queueprint(&p);
//}
//int main()
//{
//	//TestQueue();
//	return 0;
//}