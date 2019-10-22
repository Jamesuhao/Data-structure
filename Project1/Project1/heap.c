//#include"heap.h"
//#include<string.h>
////初始化堆
//void HeapInit(Heap* hp, HPDataType* a, int n)
//{
//	assert(hp && a);
//	if (n == 0)
//		return;
//	int i = 0;
//	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
//	if (hp->_a == NULL)
//		return;
//	for (i = 0; i < n; i++)
//		hp->_a[i] = a[i];
//	//建堆
//	//从最后一颗子树开始
//	for (i = (n - 2) / 2; i >= 0; --i)
//		ShiftDown(hp->_a, n, i);
//	hp->capacity = n;
//	hp->_size = n;
//}
////初始化为一个空堆
//void HeapEmptyInit(Heap* hp)
//{
//	assert(hp);
//	hp->_a = NULL;
//	hp->_size = 0;
//	hp->capacity = 0;
//}
////交换
//void Swap(HPDataType* pa, HPDataType* pb)
//{
//	HPDataType tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
////向下调整算法
//void ShiftDown(HPDataType* a, int n, int root)
//{
//	assert(a);
//	if (n == 0)
//		return;
//	int parent = root;
//	int child = 2 * parent + 1;
//	while (child < n)
//	{
//		//判断是否存在右孩子
//		//存在：如果创建小堆
////	if (child + 1 < n && a[child + 1] < a[child])
////		++child;
////	if (a[child] < a[parent])
////	{
////		Swap(&a[child], &a[parent]);
////		parent = child;
////		child = 2 * parent + 1;
////	}
//		//存在:如果创建大堆
//		if (child + 1 < n && a[child + 1] > a[child])
//			++child;
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		//一次调整完毕
//		else
//			break;
//	}
//}
////向上调整算法
//void ShiftUp(HPDataType* a, int n, int child)
//{
//	assert(a);
//	if (n == 0)
//		return;
//	int parent = (child - 1) / 2;
//	while (child < n)
//	{
//		if (a[parent] < a[child])
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//			break;
//	}
//}
////销毁堆
//void HeapDestory(Heap* hp)
//{
//	assert(hp);
//	if (hp->_a)
//	{
//		free(hp->_a);
//		hp->_a = NULL;
//		hp->capacity = 0;
//		hp->_size = 0;
//	}
//}
////插入
//void HeapPush(Heap* hp, HPDataType x)
//{
//	assert(hp);
//	//检查容量
//	if (hp->capacity == hp->_size)
//	{
//		int newcapacity = hp->capacity == 0 ? 10 : 2 * hp->capacity;
//		HPDataType* space = (HPDataType*)malloc(sizeof(HPDataType));
//		if (space != NULL && hp->_size > 0)
//		{
//			memcpy(space, hp->_a, sizeof(int) * hp->_size);
//			free(hp->_a);
//		}
//		hp->_a = space;
//		hp->capacity = newcapacity;
//	}
//	if (hp->_a != NULL)
//		hp->_a[hp->_size] = x;
//	hp->_size++;
//	ShiftUp(hp->_a, hp->_size, hp->_size - 1);
//}
////删除堆顶元素
//void HeapPop(Heap* hp)
//{
//	assert(hp);
//	if (HeapEmpty(hp) == 0)
//	{
//		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
//		hp->_size--;
//		ShiftDown(hp->_a, hp->_size, 0);
//	}
//}
////获取堆顶元素
//HPDataType HeapTop(Heap* hp)
//{
//	assert(hp);
//	return hp->_a[0];
//}
////堆的大小
//int HeapSize(Heap* hp)
//{
//	assert(hp);
//	return hp->_size;
//}
////判断堆是否为空
//int HeapEmpty(Heap* hp)
//{
//	assert(hp);
//	return hp->_size == 0 ? 1 : 0;
//}
////堆排序
//void HeapSort(int* a, int n)
//{
//	assert(a);
//	int i = 0;
//	int end = n - 1;
//	for (i = (n - 2) / 2; i >= 0; i--)
//		ShiftDown(a, n, i);
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		ShiftDown(a, end, 0);
//		end--;
//	}
//}
//void TestHeap()
//{
//	int i = 0;
//	int a[] = { 1,5,3,8,7,6 };
//	Heap hp;
//	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
//	HeapPrint(&hp);
//	//Heap hp;
//	//HeapEmptyInit(&hp);
//	HeapPush(&hp, 10);
//	HeapPush(&hp, 2);
//	//HeapPush(&hp, 3);
//	//HeapPush(&hp, 4);
//	//HeapPush(&hp, 5);
//	//HeapPush(&hp, 6);
//	//HeapPush(&hp, 7);
//	//HeapPop(&hp);
//	HeapPrint(&hp);
//}
//void HeapPrint(Heap* hp)
//{
//	assert(hp);
//	for (int i = 0; i < hp->_size; ++i)
//	{
//		printf("%d ", hp->_a[i]);
//	}
//	printf("\n");
//}
//void TestHeapSort()
//{
//	int i = 0;
//	int a[] = { 10,2,3,4,5,6,7 };
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	TestHeap();
//	//TestHeapSort();
//	return 0;
//}