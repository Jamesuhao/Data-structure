#include"ListNode.h"
#include<assert.h>
#include<malloc.h>
//初始化无头单向非循环链表
void SListInit(SList* plist)
{
	assert(plist);
	plist->head = NULL;
}
//摧毁无头单向非循环链表
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->head;
	while (cur)
	{
		SListNode* _next = cur->next;
		free(cur);
		cur = _next;
	}
	plist->head = NULL;
}
//定义结点
SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//尾插
void SListPushBack(SList* plist, SLDataType x)
{
	assert(plist);
	//如果是第一个节点
	if (plist->head == NULL)
	{
		plist->head = BuySListNode(x);
	}
	//如果不是第一个节点
	else
	{
		SListNode* cur = plist->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur = BuySListNode(x);
	}
}
//尾删
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* prev = NULL;
	SListNode* cur = plist->head;
	if (cur == NULL)
	{
		return;
	}
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	cur = NULL;
	if (prev == NULL)
	{
		plist->head = NULL;
	}
	else
	{
		prev->next = NULL;
	}
}
//头插
void SListPushFront(SList* plist, SLDataType x)
{
	assert(plist);
	if (plist->head == NULL)
	{
		plist->head = BuySListNode(x);
	}
	else
	{
		SListNode* cur = plist->head;
		SListNode* newNode = BuySListNode(x);
		newNode->next = cur;
		plist->head = newNode;
	}
}
//头删
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->head == NULL)
	{
		return;
	}
	SListNode* cur = plist->head;
	SListNode* _next = plist->head->next;
	free(cur);
	cur = NULL;
	plist->head = _next;
}
//查找
SListNode* SListFind(SList* plist, SLDataType x)
{
	assert(plist);
	if (plist->head == NULL)
	{
		return NULL;
	}
	SListNode* cur = plist->head;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//在pos位的后面进行插入
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos);
	SListNode* cur = BuySListNode(x);
	cur->next = pos->next;
	pos->next=cur;
}
//在pos位的后面删除
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* cur = pos->next;
	if (cur == NULL)
	{
		return;
	}
	SListNode* next = cur->next;
	pos->next = next;
	free(cur);
	cur = NULL;
}
//删除某个元素
void SListRemove(SList* plist, SLDataType x)
{
	assert(plist);
	if (plist->head == NULL)
	{
		return;
	}
	SListNode* cur = plist->head;
	SListNode* prev = NULL;
	while (cur)
	{
		if (cur->data == x)
		{
			if (prev == NULL)
			{
				plist->head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void SListPrint(SList* plist)
{
	assert(plist);
	if (plist->head == NULL)
	{
		printf("该链表为空\n");
	}
	else
	{
		SListNode* cur = plist->head;
		while (cur)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
	}
}