#include<iostream>
#include "heap.h"
#include"Adjust_algorithm.h"
using namespace std;
void HeapEmptyInit(Heap* hp)
{
	hp->_a = nullptr;
	hp->_capacity = 0;
	hp->_size = 0;
}
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	if (hp == nullptr || a == nullptr)
	{
		return;
	}
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	for (int i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(hp->_a, n, i);
	}
	hp->_capacity = hp->_size = n;
}
void HeapDestory(Heap* hp)
{
	if (hp)
	{
		free(hp->_a);
		hp->_a = nullptr;
		hp->_capacity = 0;
		hp->_size = 0;
	}
}
void HeapPsuh(Heap* hp, HPDataType data)
{
	if (hp == nullptr)
	{
		return;
	}
	if (hp->_capacity == hp->_size)
	{
		int newCapacity = hp->_capacity == 0 ? 10 : hp->_capacity * 2;
		HPDataType* p = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newCapacity);
		if (p)
		{
			hp->_a = p;
			p = nullptr;
		}
		hp->_capacity = newCapacity;
	}
	hp->_a[hp->_size] = data;
	hp->_size++;
	ShiftUp(hp->_a, hp->_size, hp->_size - 1);
}
void HeapPop(Heap* hp)
{
	if (hp == nullptr)
	{
		return;
	}
	if (!HeapEmpty(hp))
	{
		swap(hp->_a[0], hp->_a[hp->_size - 1]);
		hp->_size--;
		ShiftDown(hp->_a, hp->_size, 0);
	}
}
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	if (hp == nullptr)
	{
		return 0;
	}
	return hp->_size;
}
bool HeapEmpty(Heap* hp)
{
	if (hp)
	{
		if (hp->_size != 0)
		{
			return true;
		}
	}
	return false;
}
void HeapSort(int* a, int n)
{
	if (a == nullptr)
	{
		return;
	}
	for (int i = (n - 2) / 2; i > 0; --i)
	{
		ShiftDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(a[0], a[end]);
		ShiftDown(a, end, 0);
		--end;
	}
}