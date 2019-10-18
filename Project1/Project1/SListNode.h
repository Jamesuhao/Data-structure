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
void ListInit(List* plist);//��ʼ����ͷ˫��ѭ������
void ListDestory(List* plist);//����
ListNode* GreatListNode(DataType x);//�����½��
void ListPushBack(List* plist, DataType x);//β��
void ListPopBack(List* plist);//βɾ
void ListPushFront(List* plist, DataType x);//ͷ��
void ListPopFront(List* plist);//ͷɾ
void ListInsert(List* plist, ListNode* pos, DataType x);//��posǰ�����
void ListErase(List* plist, ListNode* pos); // ɾ��posλ�õĽڵ�
void ListPrint(List* plist);
void testList();
