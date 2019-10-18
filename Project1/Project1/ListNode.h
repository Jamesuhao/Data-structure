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
void SListInit(SList* plist);//��ʼ����ͷ�����ѭ������
void SListDestory(SList* plist);//�ݻ���ͷ�����ѭ������
SListNode* BuySListNode(SLDataType x);//������
void SListPushBack(SList* plist, SLDataType x);//β��
void SListPopBack(SList* plist);//βɾ
void SListPushFront(SList* plist, SLDataType x);//ͷ��
void SListPopFront(SList* plist);//ͷɾ
SListNode* SListFind(SList* plist, SLDataType x);//����
void SListInsertAfter(SListNode* pos, SLDataType x);//��posλ�ĺ�����в���
void SListEraseAfter(SListNode* pos);//��posλ�ĺ���ɾ��
void SListRemove(SList* plist, SLDataType x);//ɾ��ĳ��Ԫ��
void SListPrint(SList* plist);//��ӡ����
