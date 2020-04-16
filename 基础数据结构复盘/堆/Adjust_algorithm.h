#pragma once
#include"heap.h"
static void swap(HPDataType& a, HPDataType& b)
{
	HPDataType tmp = a;
	a = b;
	b = tmp;
}
static void ShiftDown(HPDataType* a, int n, int root)
{
	if (a == nullptr)
	{
		return;
	}
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
static void ShiftUp(HPDataType* a, int n, int child)
{
	if (a == nullptr)
	{
		return;
	}
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}