#pragma once
#include<stdio.h>
#pragma once
#include<stdio.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	struct ListNode* _head;
}List;
void ListInit(List* plist);//初始化带头双向循环链表
void ListDestory(List* plist);
void ListpushBack(List* plist, LTDataType x);
void ListPopBack(List* plist, LTDataType x);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist, LTDataType x);
ListNode* ListFind(List* plist, LTDataType x);