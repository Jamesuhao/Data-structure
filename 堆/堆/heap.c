#include"heap.h"
#include<malloc.h>
#include<assert.h>
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	int i = 0;
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	//调整，从最后一颗子树开始调整
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(hp->_a, n, i);
	}
	hp->_size = n;
	hp->_capacity = n;
}
//void HeapInit(Heap* hp)
//{
//	assert(hp);
//	hp->_a = NULL;
//	hp->_capacity = 0;
//	hp->_size = 0;
//}
void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void ShiftDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//当前结点是否有孩子结点，有孩子进入循环，无孩子则无需调整
	while (child < n)
	{
		//判断是否有右孩子，如果有，两者之间选较大值
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		//孩子是否大于父亲
		if (a[child] > a[parent])
		{
			//交换
			Swap(&a[parent], &a[child]);
			//更新下一次调整的位置
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//以parent为根的子树已经是一个大堆，结束调整
			break;
		}
	}
}
void HeapDestory(Heap* hp)
{

}
void HeapPush(Heap* hp, HPDataType x)
{

}
void HeapPop(Heap* hp)
{

}
HPDataType HeapTop(Heap* hp)
{

}
int HeapSize(Heap* hp)
{

}
int HeapEmpty(Heap* hp)
{

}
// 堆排序 
void HeapSort(int* a, int n)
{

}
void TestHeap()
{
	int a[] = { 1,5,3,8,7,6 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}


int main()
{
	TestHeap();
	return 0;
}