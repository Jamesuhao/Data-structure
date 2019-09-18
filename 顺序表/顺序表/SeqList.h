#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqList;
void SeqListInit(SeqList* psl);//初始化顺序表
void SeqListDestory(SeqList *psl);//摧毁顺序表
void SeqListCheckCapacity(SeqList *psl);//检查容量
void SeqListPushBack(SeqList *psl, SLDataType x);//尾插
void SeqListPopBack(SeqList *psl);//尾删
void SeqListPushFront(SeqList *psl, SLDataType x);//头插
void SeqListPopFront(SeqList *psl);//头删
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x);//向第pos位插入数据
void SeqListErase(SeqList *psl, size_t pos);//删除第pos位数据
int SeqListFind(SeqList *psl, SLDataType x);//查找数据
void SeqListRemoveAll(SeqList *psl, SLDataType x);//按内容删除
void SeqListModify(SeqList *psl, size_t pos, SLDataType x);//修改第pos位的元素
void SeqListPrint(SeqList *psl);//打印顺序表
size_t SeqListSize(SeqList *psl);//顺序表的长度
void SeqListBubbleSort(SeqList *psl);//冒泡法对顺序表排序
int SeqListBinaryFind(SeqList *psl, SLDataType x);//顺序表二分查找