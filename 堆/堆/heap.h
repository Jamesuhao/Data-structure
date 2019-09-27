#pragma once
#include<stdio.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapEmptyInit(Heap* hp);
void ShiftDown(HPDataType* a, int n, int root);//���µ����㷨
void ShiftUp(HPDataType* a, int n, int child);//���ϵ����㷨
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x); 
void HeapPop(Heap* hp); 
HPDataType HeapTop(Heap* hp); 
int HeapSize(Heap* hp); 
int HeapEmpty(Heap* hp);
void HeapSort(int* a, int n);// ������ 
void TestHeap();
void HeapPrint(Heap* hp);
void TestHeapSort();