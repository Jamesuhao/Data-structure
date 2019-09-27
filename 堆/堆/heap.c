#include"heap.h"
#include<malloc.h>
#include<assert.h>
//����һ�����
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	int i = 0;
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	//�����������һ��������ʼ����
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(hp->_a, n, i);
	}
	hp->_size = n;
	hp->_capacity = n;
}
//��ʼ��Ϊ�ն�
void HeapEmptyInit(Heap* hp)
{
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
//����
void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//���µ����㷨
void ShiftDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//��ǰ����Ƿ��к��ӽ�㣬�к��ӽ���ѭ�����޺������������
	while (child < n)
	{
		//�ж��Ƿ����Һ��ӣ�����У�����֮��ѡ�ϴ�ֵ
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		//�����Ƿ���ڸ���
		if (a[child] > a[parent])
		{
			//����
			Swap(&a[parent], &a[child]);
			//������һ�ε�����λ��
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//��parentΪ���������Ѿ���һ����ѣ���������
			break;
		}
	}
}
//���ϵ����㷨
void ShiftUp(HPDataType* a, int n, int child)
{
	assert(a);//�Բ����ĺϷ��Խ��м��
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
//���ٶ�
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
//����
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	//�������
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newcapacity);
		hp->_capacity = newcapacity;
	}
	//β��
	hp->_a[hp->_size] = x;
	hp->_size++;
	//���ϵ���
	ShiftUp(hp->_a, hp->_size, hp->_size - 1);
}
//ɾ���Ѷ�Ԫ�أ���ֵ��
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
//���ضѶ�Ԫ��
HPDataType HeapTop(Heap* hp)
{
	assert(hp && hp->_size);
	return hp->_a[0];
}
//���ضѵĴ�С
int HeapSize(Heap* hp)
{
	assert(hp && hp->_size);
	return hp->_size;
}
//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 1 : 0;
}
// ������ ��O(N*log(N)+N(����))--->O(N)
void HeapSort(int* a, int n)
{
	//����
	int i = 0;
	int end = n - 1;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(a, n, i);
	}
	//������
	//����
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		ShiftDown(a, end, 0);
		end--;
	}
}
//����
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
//��ӡ��
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