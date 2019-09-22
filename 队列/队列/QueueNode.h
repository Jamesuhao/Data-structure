#pragma once
#include<stdio.h>
typedef int DataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front;//∂”Õ∑
	QueueNode* _rear;//∂”Œ≤
}Queue;
void QueueInit(Queue* p);
void QueueDestory(Queue* p);

void QueuePush(Queue* p,DataType x);
void QueuePop(Queue* p);

DataType QueueFront(Queue* p);
DataType QueueBack(Queue* p);
int QueueEmpty(Queue* p);
//int QueueSize(Queue* p);
void Queueprint(Queue* p);
void TestQueue();