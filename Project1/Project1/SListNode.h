#pragma once
#include<stdio.h>
typedef int DataType;

typedef struct ListNode
{
	DataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;
typedef struct List
{
	struct ListNode* _head;
}List;
void ListInit(List* plist);//初始化带头双向循环链表
void ListDestory(List* plist);//销毁
ListNode* GreatListNode(DataType x);//创造新结点
void ListPushBack(List* plist, DataType x);//尾插
void ListPopBack(List* plist);//尾删
void ListPushFront(List* plist, DataType x);//头插
void ListPopFront(List* plist);//头删
void ListInsert(List* plist, ListNode* pos, DataType x);//在pos前面插入
void ListErase(List* plist, ListNode* pos); // 删除pos位置的节点
void ListPrint(List* plist);
void testList();
