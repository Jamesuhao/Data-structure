#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
//队列初始化
//void QueueInit(Queue* p)
//{
//	assert(p);
//	p->_front = NULL;
//	p->_rear = NULL;
//}
////销毁队列
//void QueueDestory(Queue* p)
//{
//	assert(p);
//	QueueNode* cur = p->_front;
//	while (cur)
//	{
//		p->_front = cur->_next;
//		free(cur);
//		cur = p->_front;
//	}
//}
//void QueuePush(Queue* p, DataType x)
//{
//	assert(p);
//	QueueNode* newNode = NULL;
//	QueueNode* Node = (QueueNode*)malloc(sizeof(QueueNode));
//	if (Node != NULL)
//	{
//		newNode = Node;
//		newNode->_data = x;
//		newNode->_next = NULL;
//		if (p->_front == NULL)
//		{
//			p->_front = newNode;
//			p->_rear = newNode;
//		}
//		else
//		{
//			p->_rear->_next = newNode;
//			p->_rear = newNode;
//		}
//	}
//}
//void QueuePop(Queue* p)
//{
//	assert(p);
//	QueueNode* next = p->_front->_next;
//	free(p->_front);
//	p->_front = next;
//	if (p->_front == NULL)
//		p->_rear = NULL;
//}
//DataType QueueFront(Queue* p)
//{
//	assert(p);
//	if(p->_front)
//		return p->_front->_data;
//	return -1;
//}
//DataType QueueBack(Queue* p)
//{
//	assert(p);
//	return p->_rear->_data;
//}
//int QueueEmpty(Queue* p)
//{
//	assert(p);
//	return p->_front == NULL ? 1 : 0;
//}
//int QueueSize(Queue* p)
//{
//	assert(p);
//	QueueNode* cur = p->_front;
//	int count = 0;
//	while (cur)
//	{
//		++count;
//		cur = cur->_next;
//	}
//	return count;
//}
//void Queueprint(Queue* p)
//{
//	assert(p);
//	QueueNode* cur = p->_front;
//	while (cur)
//	{
//		printf("%d ", cur->_data);
//		cur = cur->_next;
//	}
//	printf("\n");
//}
//void TestQueue()
//{
//	Queue st;
//	QueueInit(&st);
//	QueuePush(&st, 1);
//	QueuePush(&st, 2);
//	QueuePush(&st, 3);
//	QueuePush(&st, 4);
//	QueuePush(&st, 5);
//	int Size = QueueSize(&st);
//	printf("Size=%d\n", Size);
//	Queueprint(&st);
//	int front = QueueFront(&st);
//	printf("front=%d\n", front);
//	int rear = QueueBack(&st);
//	printf("rear=%d\n", rear);
//	QueuePop(&st);
//	QueuePop(&st);
//	Size = QueueSize(&st);
//	printf("Size=%d\n", Size);
//	int isempty = QueueEmpty(&st);
//	printf("isempty=%d\n", isempty);
//}
//int main()
//{
//	TestQueue();
//	return 0;
//}

