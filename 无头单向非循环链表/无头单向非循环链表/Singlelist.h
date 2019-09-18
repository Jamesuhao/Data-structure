#pragma once
#include<stdio.h>
typedef int SLTDatatype;
typedef struct SListNode
{
	SLTDatatype _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	struct SListNode* _head;
}SList;
void SListInit(SList* plist);//初始化无头单向非循环链表
void SListDestory(SList* plist);//摧毁无头单向非循环链表
SListNode* BuySListNode(SLTDatatype x);//定义结点
void SListPushBack(SList* plist, SLTDatatype x);//尾插
void SListPopBack(SList* plist);//尾删
void SListPushFront(SList* plist, SLTDatatype x);//头插
void SListPopFront(SList* plist);//头删
SListNode* SListFind(SList* plist, SLTDatatype);
void SListInsertAfter(SListNode* pos, SLTDatatype x);//在pos位的后面进行插入
void SListEraseAfter(SListNode* pos);//在pos位的后面删除
void SListRemove(SList* plist, SLTDatatype x);//删除某个元素
void SListPrint(SList* plist);//打印链表
void SListTest();//测试
