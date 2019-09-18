#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include"Singlelist.h"
//无头单向非循环
//初始化单链表
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
//销毁单链表
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{	
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}
//定义新结点
SListNode* BuySListNode(SLTDatatype x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
//尾插 O(n)
void SListPushBack(SList* plist, SLTDatatype x)
{
	assert(plist);
	//空链表
	if (plist->_head == NULL)
	{
		//SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
		//newnode->_data = x;
		//newnode->_next = NULL;
		plist->_head = BuySListNode(x);
	}
	else
	{	
		//遍历单链表
		SListNode* cur = plist->_head;
		//找到最后一个结点
		while (cur->_next)
		{
			cur = cur->_next;
		}
		//插入
		cur->_next = BuySListNode(x);
	}
}
//尾删 O(n)
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* prev = NULL;
	if (cur == NULL)
	{
		return;
	}
	//找到最后一个结点
	while (cur->_next)
	{
		prev = cur;
		cur = cur->_next;
	}
	//删除
	free(cur);
	cur = NULL;
	//删除的是头结点
	if (prev == NULL)
	{
		plist->_head = NULL;
	}
	else
	{
		prev->_next = NULL;
	}
}
//头插O(1)
void SListPushFront(SList* plist, SLTDatatype x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* newnode = BuySListNode(x);
	newnode->_next = cur;
	plist->_head = newnode;
}
//头删O(1)
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* cur = NULL;
	SListNode* next = NULL;
	if (plist->_head == NULL)
	{
		return;
	}
	cur = plist->_head;
	next = plist->_head->_next;
	free(cur);
	cur = NULL;
	plist->_head = next;
}
//查找
SListNode* SListFind(SList* plist, SLTDatatype x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDatatype x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	SListNode* next = pos->_next;
	pos->_next = newnode;
	newnode->_next = next;

}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->_next;
	if (next==NULL)
	{
		return;
	}
	else
	{
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}
void SListRemove(SList* plist, SLTDatatype x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* prev = NULL;

	while (cur)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)
			{
				plist->_head = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}

	}
}
void SListPrint(SList* plist)
{
	SListNode* cur = plist->_head;
	assert(plist);
	if (plist->_head == NULL)
	{
		printf("链表为空\n");
	}
	else
	{
		while (cur)
		{
			printf("%d->", cur->_data);
			cur = cur->_next;
		}
		printf("NULL\n");
	}
}
void SListTest()
{
	SList s1;
	SListInit(&s1);
	SListPushBack(&s1, 1);
	SListPushBack(&s1, 2);
	SListPushBack(&s1, 3);
	SListPushBack(&s1, 4);
	SListPopBack(&s1);
	SListPushFront(&s1, 1);
	SListPushFront(&s1, 2);
	SListPushFront(&s1, 3);
	SListPushFront(&s1, 4);
	SListPopFront(&s1);
	SListInsertAfter(s1._head->_next->_next, 5);
	SListEraseAfter(s1._head->_next);
	SListRemove(&s1, 3);
	
	
	SListPrint(&s1);
}
int main()
{
	
	SListTest();
	return 0;
}
