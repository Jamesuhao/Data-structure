#pragma once
#include<iostream>
#include<cstdio>
using namespace std;
//˳���Ķ�̬�洢
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array; // ָ��̬���ٵ�����
	size_t size; //��ЧԪ�صĸ���
	size_t capacity;  //������С
}SeqList;
void SeqListInit(SeqList* sql);//��ʼ��
void SeqListDestory(SeqList* sql);//����

void SeqListCheckCapacity(SeqList* sql);//�������
void SeqListPsuhBack(SeqList* sql, SLDataType data);//β��
void SeqListPopBack(SeqList* sql);//βɾ
void SeqListPushFront(SeqList* sql, SLDataType data);//ͷ��
void SeqListPopFront(SeqList* sql);//ͷɾ

int SeqListFind(SeqList* sql, SLDataType data);//��ѯ
void SeqListInsert(SeqList* sql, size_t pos, SLDataType data);//ָ��λ�ò���
void SeqListErase(SeqList* sql, size_t pos);//ָ��λ��ɾ��
void SeqListRemove(SeqList* sql, SLDataType data);//ɾ������������data
void SeqListBubbleSort(SeqList* sql);//ð������
size_t SeqListBinaryFind(SeqList* sql, SLDataType data);//���ֲ���