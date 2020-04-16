#pragma once
#include<iostream>
#include<cstdio>
using namespace std;
//顺序表的动态存储
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	size_t size; //有效元素的个数
	size_t capacity;  //容量大小
}SeqList;
void SeqListInit(SeqList* sql);//初始化
void SeqListDestory(SeqList* sql);//销毁

void SeqListCheckCapacity(SeqList* sql);//检查容量
void SeqListPsuhBack(SeqList* sql, SLDataType data);//尾插
void SeqListPopBack(SeqList* sql);//尾删
void SeqListPushFront(SeqList* sql, SLDataType data);//头插
void SeqListPopFront(SeqList* sql);//头删

int SeqListFind(SeqList* sql, SLDataType data);//查询
void SeqListInsert(SeqList* sql, size_t pos, SLDataType data);//指定位置插入
void SeqListErase(SeqList* sql, size_t pos);//指定位置删除
void SeqListRemove(SeqList* sql, SLDataType data);//删除数组中所有data
void SeqListBubbleSort(SeqList* sql);//冒泡排序
size_t SeqListBinaryFind(SeqList* sql, SLDataType data);//二分查找