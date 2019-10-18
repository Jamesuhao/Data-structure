#pragma once
#include<stdio.h>
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;
typedef struct SList
{
	SListNode* head;
}SList;
void SListInit(SList* plist);//初始化无头单向非循环链表
void SListDestory(SList* plist);//摧毁无头单向非循环链表
SListNode* BuySListNode(SLDataType x);//定义结点
void SListPushBack(SList* plist, SLDataType x);//尾插
void SListPopBack(SList* plist);//尾删
void SListPushFront(SList* plist, SLDataType x);//头插
void SListPopFront(SList* plist);//头删
SListNode* SListFind(SList* plist, SLDataType x);//查找
void SListInsertAfter(SListNode* pos, SLDataType x);//在pos位的后面进行插入
void SListEraseAfter(SListNode* pos);//在pos位的后面删除
void SListRemove(SList* plist, SLDataType x);//删除某个元素
void SListPrint(SList* plist);//打印链表
