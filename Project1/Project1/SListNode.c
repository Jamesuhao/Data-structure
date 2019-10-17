//#pragma once
//#include"SListNode.h"
//#include<assert.h>
//#include<malloc.h>
////初始化带头双向循环链表
//void ListInit(List* plist)
//{
//	assert(plist);
//	plist->_head = GreatListNode(0);
//	plist->_head->_next = plist->_head;
//	plist->_head->_prev = plist->_head;
//}
////销毁
//void ListDestory(List* plist)
//{
//	assert(plist);
//	ListNode* cur = plist->_head->_next;
//	while (cur != plist->_head)
//	{
//		ListNode* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//	free(plist->_head);
//	plist->_head = NULL;
//}
////创造新节点
//ListNode* GreatListNode(DataType x)
//{
//	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//	if (newNode == NULL)
//	{
//		return NULL;
//	}
//	newNode->_data = x;
//	newNode->_next = NULL;
//	newNode->_prev = NULL;
//	return newNode;
//}
////尾插
//void ListPushBack(List* plist, DataType x)
//{
//	assert(plist);
//	ListNode* cur = GreatListNode(x);
//	ListNode* tail = plist->_head->_prev;
//	if (cur != NULL)
//	{
//		cur->_prev = tail;
//		tail->_next = cur;
//		cur->_next = plist->_head;
//		plist->_head->_prev = cur;
//	}
//}
////尾删
//void ListPopBack(List* plist)
//{
//	assert(plist);
//	if (plist->_head == plist->_head->_next)
//	{
//		return;
//	}
//	ListNode* cur = plist->_head->_prev;
//	ListNode* prev = cur->_prev;
//	prev->_next = plist->_head;
//	plist->_head->_prev = prev;
//	free(cur);
//	cur = NULL;
//}
////头插
//void ListPushFront(List* plist, DataType x)
//{
//	assert(plist);
//	ListNode* cur = GreatListNode(x);
//	if (cur != NULL)
//	{
//		ListNode* next = plist->_head->_next;
//		cur->_prev = plist->_head;
//		cur->_next = next;
//		next->_prev = cur;
//		plist->_head->_next = cur;
//	}
//}
////头删
//void ListPopFront(List* plist)
//{
//	assert(plist);
//	if (plist->_head == plist->_head->_next)
//	{
//		return;
//	}
//	ListNode* cur = plist->_head->_next;
//	ListNode* next = cur->_next;
//	next->_prev = plist->_head;
//	plist->_head->_next = next;
//	free(cur);
//	cur = NULL;
//}
////在pos前面插入
//void ListInsert(List* plist, ListNode* pos, DataType x)
//{
//	assert(plist && pos);
//	ListNode* cur = GreatListNode(x);
//	if (cur == NULL)
//	{
//		return;
//	}
//	ListNode* prev = pos->_prev;
//	cur->_next = pos;
//	cur->_prev = prev;
//	prev->_next = cur;
//	pos->_prev=cur;
//}
//// 删除pos位置的节点
//void ListErase(List* plist, ListNode* pos)
//{
//	assert(plist && pos);
//	if (pos == plist->_head)
//	{
//		return;
//	}
//	ListNode* prev = pos->_prev;
//	ListNode* next = pos->_next;
//	prev->_next = next;
//	next->_prev = prev;
//	free(pos);
//	pos = NULL;
//}
////打印
//void ListPrint(List* plist)
//{
//	assert(plist);
//	if (plist->_head == plist->_head->_next)
//	{
//		printf("该链表为空！\n");
//		return;
//	}
//	ListNode* cur = plist->_head->_next;
//	while (cur != plist->_head)
//	{
//		printf("%d->", cur->_data);
//		cur = cur->_next;
//	}
//	printf("NULL\n");
//}
//void testList()
//{
//	List list;
//	ListInit(&list);
//	//ListPushBack(&list, 1);
//	//ListPushBack(&list, 2);
//	//ListPushBack(&list, 3);
//	//ListPushBack(&list, 4);
//
//	ListPushFront(&list, 1);
//	ListPushFront(&list, 2);
//	ListPushFront(&list, 3);
//	ListPushFront(&list, 4);
//	ListPrint(&list);
//	ListPopBack(&list);
//	ListPrint(&list);
//	ListInsert(&list, list._head->_next->_next, 6);
//	ListPrint(&list);
//	ListPopFront(&list);
//	ListPrint(&list);
//	ListErase(&list, list._head->_next->_next->_next);
//	ListPrint(&list);
//	//ListDestory(&list);
//	//ListPrint(&list);
//}
//int main()  
//{
//	testList();
//	return 0;
//}


