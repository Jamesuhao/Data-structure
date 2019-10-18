#include<stdio.h>
//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqList;
void SeqListInit(SeqList* psl); //初始化顺序表
void SeqListDestory(SeqList* psl);////销毁顺序表
void CheckCapacity(SeqList* psl); //检查顺序表容量
void SeqListPushBack(SeqList* psl, SLDataType x); //尾插
void SeqListPopBack(SeqList* psl); //尾删
void SeqListPushFront(SeqList* psl, SLDataType x); //头插
void SeqListPopFront(SeqList* psl);//头删
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//在第pos位插入 
void SeqListErase(SeqList* psl, size_t pos); //删除第pos位数据
void SeqListRemoveAll(SeqList* psl, SLDataType x); //删除所有x
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); //修改第pos位数据
int SeqListFind(SeqList* psl, SLDataType x);//查找 
void SeqListPrint(SeqList* psl);//打印顺序表
int SeqListSize(SeqList* psl);//顺序表的大小
void SeqListBubbleSort(SeqList* psl); //冒泡排序
int SeqListBinaryFind(SeqList* psl, SLDataType x);//顺序表二分查找
void TestSeqList();//测试