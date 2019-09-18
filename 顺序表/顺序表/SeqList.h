#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqList;
void SeqListInit(SeqList* psl);//��ʼ��˳���
void SeqListDestory(SeqList *psl);//�ݻ�˳���
void SeqListCheckCapacity(SeqList *psl);//�������
void SeqListPushBack(SeqList *psl, SLDataType x);//β��
void SeqListPopBack(SeqList *psl);//βɾ
void SeqListPushFront(SeqList *psl, SLDataType x);//ͷ��
void SeqListPopFront(SeqList *psl);//ͷɾ
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x);//���posλ��������
void SeqListErase(SeqList *psl, size_t pos);//ɾ����posλ����
int SeqListFind(SeqList *psl, SLDataType x);//��������
void SeqListRemoveAll(SeqList *psl, SLDataType x);//������ɾ��
void SeqListModify(SeqList *psl, size_t pos, SLDataType x);//�޸ĵ�posλ��Ԫ��
void SeqListPrint(SeqList *psl);//��ӡ˳���
size_t SeqListSize(SeqList *psl);//˳���ĳ���
void SeqListBubbleSort(SeqList *psl);//ð�ݷ���˳�������
int SeqListBinaryFind(SeqList *psl, SLDataType x);//˳�����ֲ���