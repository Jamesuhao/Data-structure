#pragma once
#include<iostream>
using namespace std;

typedef int SLDataType;
typedef struct SListNode
{
	SLDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;
void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuyListNode(SLDataType x);
void SListPushFront(SList* plist, SLDataType x);
void SListPopFront(SList* plist);
void SListPushBack(SList* plist, SLDataType x);
void SListPopBack(SList* plist);
SListNode* SListFind(SList* plist, SLDataType x);

void SListInsertAfter(SList* plist, SListNode* pos, SLDataType x);
void SListEraseAfter(SList* plist, SListNode* pos);