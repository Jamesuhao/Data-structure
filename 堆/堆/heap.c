#include"heap.h"
#include<malloc.h>
#include<assert.h>
//创建一个大堆
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
//初始化为空堆
void HeapEmptyInit(Heap* hp)
{
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
//交换
void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//向下调整算法
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
//向上调整算法
void ShiftUp(HPDataType* a, int n, int child)
{
	assert(a);//对参数的合法性进行检查
	int parent = (child-1)/2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//销毁堆
void HeapDestory(Heap* hp)
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_capacity = 0;
		hp->_size = 0;
	}
}
//插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	//检查容量
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newcapacity);
		hp->_capacity = newcapacity;
	}
	//尾插
	hp->_a[hp->_size] = x;
	hp->_size++;
	//向上调整
	ShiftUp(hp->_a, hp->_size, hp->_size - 1);
}
//删除堆顶元素，最值。
void HeapPop(Heap* hp)
{
	assert(hp);
	if (HeapEmpty(hp) == 0)
	{
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		hp->_size--;
		ShiftDown(hp->_a, hp->_size, 0);
	}
}
//返回堆顶元素
HPDataType HeapTop(Heap* hp)
{
	assert(hp && hp->_size);
	return hp->_a[0];
}
//返回堆的大小
int HeapSize(Heap* hp)
{
	assert(hp && hp->_size);
	return hp->_size;
}
//判断堆是否为空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 1 : 0;
}
// 堆排序 ：O(N*log(N)+N(建堆))--->O(N)
void HeapSort(int* a, int n)
{
	//建堆
	int i = 0;
	int end = n - 1;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(a, n, i);
	}
	//堆排序
	//交换
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		ShiftDown(a, end, 0);
		end--;
	}
}
//测试
void TestHeap()
{
	int i = 0;
	int a[] = { 1,5,3,8,7,6 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);
	//Heap hp;
	//HeapEmptyInit(&hp);
	//HeapPush(&hp, 1);
	//HeapPush(&hp, 2);
	//HeapPush(&hp, 3);
	//HeapPush(&hp, 4);
	//HeapPush(&hp, 5);
	//HeapPush(&hp, 6);
	//HeapPush(&hp, 7);
	//HeapPop(&hp);
	//HeapPrint(&hp);
}
//打印堆
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeapSort()
{
	int i = 0;
	int a[] = { 1,5,3,8,7,6 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	TestHeap();
	TestHeapSort();
	return 0;
}