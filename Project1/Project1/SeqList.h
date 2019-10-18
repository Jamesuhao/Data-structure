#include<stdio.h>
//��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqList;
void SeqListInit(SeqList* psl); //��ʼ��˳���
void SeqListDestory(SeqList* psl);////����˳���
void CheckCapacity(SeqList* psl); //���˳�������
void SeqListPushBack(SeqList* psl, SLDataType x); //β��
void SeqListPopBack(SeqList* psl); //βɾ
void SeqListPushFront(SeqList* psl, SLDataType x); //ͷ��
void SeqListPopFront(SeqList* psl);//ͷɾ
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//�ڵ�posλ���� 
void SeqListErase(SeqList* psl, size_t pos); //ɾ����posλ����
void SeqListRemoveAll(SeqList* psl, SLDataType x); //ɾ������x
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); //�޸ĵ�posλ����
int SeqListFind(SeqList* psl, SLDataType x);//���� 
void SeqListPrint(SeqList* psl);//��ӡ˳���
int SeqListSize(SeqList* psl);//˳���Ĵ�С
void SeqListBubbleSort(SeqList* psl); //ð������
int SeqListBinaryFind(SeqList* psl, SLDataType x);//˳�����ֲ���
void TestSeqList();//����