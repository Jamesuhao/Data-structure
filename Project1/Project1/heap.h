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
//void HeapInit(Heap* hp, HPDataType* a, int n);//��ʼ����
//void HeapEmptyInit(Heap* hp);//��ʼ��һ���ն�
//void ShiftDown(HPDataType* a, int n, int root);//���µ����㷨
//void ShiftUp(HPDataType* a, int n, int child);//���ϵ����㷨
//void HeapDestory(Heap* hp);//���ٶ�
//void HeapPush(Heap* hp, HPDataType x);//����
//void HeapPop(Heap* hp);//ɾ��
//HPDataType HeapTop(Heap* hp);//��ȡ�Ѷ�Ԫ��
//int HeapSize(Heap* hp);//�ѵĴ�С
//int HeapEmpty(Heap* hp);//�ж϶��Ƿ�Ϊ��
//void HeapSort(int* a, int n);// ������ 
//void TestHeap();
//void HeapPrint(Heap* hp);
//void TestHeapSort();