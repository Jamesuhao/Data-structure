//#pragma once
//#include<stdio.h>
//#include<assert.h>
//#include<malloc.h>
//
//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* _a;
//	int _size;
//	int capacity;
//}Heap;
//void HeapInit(Heap* hp, HPDataType* a, int n);//初始化堆
//void HeapEmptyInit(Heap* hp);//初始化一个空堆
//void ShiftDown(HPDataType* a, int n, int root);//向下调整算法
//void ShiftUp(HPDataType* a, int n, int child);//向上调整算法
//void HeapDestory(Heap* hp);//销毁堆
//void HeapPush(Heap* hp, HPDataType x);//插入
//void HeapPop(Heap* hp);//删除
//HPDataType HeapTop(Heap* hp);//获取堆顶元素
//int HeapSize(Heap* hp);//堆的大小
//int HeapEmpty(Heap* hp);//判断堆是否为空
//void HeapSort(int* a, int n);// 堆排序 
//void TestHeap();
//void HeapPrint(Heap* hp);
//void TestHeapSort();