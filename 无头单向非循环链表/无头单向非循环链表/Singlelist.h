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
void SListInit(SList* plist);//��ʼ����ͷ�����ѭ������
void SListDestory(SList* plist);//�ݻ���ͷ�����ѭ������
SListNode* BuySListNode(SLTDatatype x);//������
void SListPushBack(SList* plist, SLTDatatype x);//β��
void SListPopBack(SList* plist);//βɾ
void SListPushFront(SList* plist, SLTDatatype x);//ͷ��
void SListPopFront(SList* plist);//ͷɾ
SListNode* SListFind(SList* plist, SLTDatatype);
void SListInsertAfter(SListNode* pos, SLTDatatype x);//��posλ�ĺ�����в���
void SListEraseAfter(SListNode* pos);//��posλ�ĺ���ɾ��
void SListRemove(SList* plist, SLTDatatype x);//ɾ��ĳ��Ԫ��
void SListPrint(SList* plist);//��ӡ����
void SListTest();//����
