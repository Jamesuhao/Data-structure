#pragma once
#include<stdio.h>
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	struct ListNode* _head;
}List;
void ListInit(List* plist);//��ʼ����ͷ˫��ѭ������
void ListDestory(List* plist);//����
ListNode* CreatListNode(DataType x);//
void ListPushBack(List* plist, DataType x);//β��
void ListPopBack(List* plist);//βɾ
void ListPushFront(List* plist, DataType x);//ͷ��
void ListPopFront(List* plist);//ͷɾ
//ListNode* ListFind(List* plist, DataType x);
void ListInsert(List* plist,ListNode* pos, DataType x);//��posǰ�����
void ListErase(List* plist,ListNode* pos); // ɾ��posλ�õĽڵ�
void ListPrint(List* plist);
void testList();
