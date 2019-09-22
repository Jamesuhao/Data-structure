#include<stdio.h>
#include"ListNode.h"
#include<assert.h>
#include<malloc.h>
void ListInit(List* plist)
{
	assert(plist);
	plist->_head = CreatListNode(0);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* cur=plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}
ListNode* CreatListNode(DataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	return newNode;
}
void ListPushBack(List* plist, DataType x)
{
	assert(plist);
	ListNode* newNode = CreatListNode(x);
	ListNode* tail = plist->_head->_prev;
	tail->_next = newNode;
	newNode->_next = plist->_head;
	newNode->_prev = tail;
	plist->_head->_prev = newNode;
}
void ListPopBack(List* plist)
{
	assert(plist);
	ListNode* prev, * tail;
	if (plist->_head == plist->_head->_next)
	{
		return;
	}
	tail = plist->_head->_prev;
	prev = tail->_prev;

	prev->_next = plist->_head;
	plist->_head->_prev = prev;
	free(tail);
	tail = NULL;
}
void ListPushFront(List* plist, DataType x)
{
	assert(plist);
	ListNode* newNode = CreatListNode(x);
	ListNode* next = plist->_head->_next;
	plist->_head->_next = newNode;
	newNode->_prev = plist->_head;
	newNode->_next = next;
	next->_prev = newNode;
}
void ListPopFront(List* plist)
{
	assert(plist);
	ListNode* next = plist->_head->_next;
	ListNode* nextnext=next->_next;
	if (plist->_head == plist->_head->_next)
	{
		return;
	}
	plist->_head->_next = nextnext;
	nextnext->_prev = plist->_head;
	free(next);
	next = NULL;
}

void ListInsert(List* plist, ListNode* pos, DataType x)
{
	assert(plist && pos);
	ListNode* prev = pos->_prev;
	ListNode* newNode = CreatListNode(x);
	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = pos;
	pos->_prev = newNode;
}
void ListErase(List* plist,ListNode* pos)
{
	assert(plist && pos);
	ListNode* prev, * next;
	if (plist->_head == pos)
	{
		return;
	}
	prev = pos->_prev;
	next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}
void ListPrint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void testList()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);

	ListPushFront(&list, 1);
	ListPushFront(&list, 2);
	ListPushFront(&list, 3);
	ListPushFront(&list, 4);
	ListPrint(&list);
	ListPopBack(&list);
	ListPopFront(&list);
	ListPrint(&list);
	ListDestory(&list);
	ListPrint(&list);
}
int main()
{
	testList();
	return 0;
}
