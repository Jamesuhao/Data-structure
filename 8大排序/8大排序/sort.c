#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
#include"Stack.h"
//1.ֱ�Ӳ�������
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O(1)
//�������Ѿ��ӽ����������
//�ȶ��ԣ��ȶ�
void Insertsort(int* arr, int n)
{
	int i = 0;
	int end = 0;
	int tmp = 0;
	assert(arr);
	for (i = 0; i < n - 1; i++)
	{
		//����Ԫ�ص�����
		//�ҵ��Ѿ��źõ����һ��Ԫ�ص�λ��
		end = i;
		//��end+1λ�õ�Ԫ�ز��뵽���ʵ�λ��
		tmp = arr[end + 1];
		while (end >= 0 && tmp < arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		//�ҵ����ʵ�λ��
		arr[end + 1] = tmp;
	}
}
//2.ϣ������(��С��������)
//ʱ�䣺O(N^1.3--N^2)
//�ռ䣺O(1)
void ShellSort(int* arr, int n)
{
	int i = 0;
	int gap = n;
	int end = 0;
	int tmp = 0;
	//for(gap>=1;gap-=num)//Ԥ����Ĵ���
	//for (num = 0; num < gap; num++)//����������
	while (gap > 1)
	{
		//gap>1:Ԥ����
		//gap=1:����
		gap = gap / 2 + 1;//��֤���Ϊ��������
		for (i = 0; i < n - gap; i++)//��������
		{
			end = i;
			tmp = arr[end + gap];
			while (end >= 0 && arr[end] > tmp)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}
}
//3.ֱ��ѡ������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int max = 0;
	int min = 0;
	while (begin < end)
	{
		//ÿ��ѡ��һ�����ĺ���С�ģ��ŵ���Ӧ��λ��
		int i = 0; 
		max = min = begin;
		//С��ѡ��һ�������ѡ���һ��
		for (i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] >= a[max])
				max = i;
		}
		Swap(&a[begin], &a[min]);
		//�ж����Ԫ�ص�λ���Ƿ�仯
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}

}
//4.������
//���ѣ����µ����㷨
void ShiftDown(int* arr, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//���ж�����
void HeapSort(int* arr, int n)
{
	int i = 0;
	int end = n - 1;
	for(i = (n - 2) / 2; i >= 0; i--)
	{
		ShiftDown(arr, end, i);
	}
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		ShiftDown(arr, end, 0);
		end--;
	}
}
//5.ð������
//ʱ�临�Ӷ�:�������£�O(N) �����£�O(N^2)
//�ռ临�Ӷ�:O(1)
//�ȶ���:�ȶ�
void BubbleSort(int* arr,int n)
{
	int i = 0;
	int end = n - 1;
	while (end > 1)
	{
		//flag:�ж�һ�˱ȽϹ������Ƿ���Ԫ�ؽ���
		//���δ����Ԫ�ؽ�������˵����ǰ�����Ѿ�������ǰ����
		int flag = 0;
		for (i = 0; i < end; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				flag = 1;
				arr[i] ^= arr[i + 1];
				arr[i + 1] ^= arr[i];
				arr[i] ^= arr[i + 1];
			}
		}
		if (flag == 0)
			break;
		end--;
	}
}
void PrintArray(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//6.����
//ʱ�临�Ӷȣ�O(logN*N)
//�ռ临�Ӷȣ�O(logN)
//���ŵ�һ������ȷ����׼ֵ��λ��


//����ȡ�з�(�Ż�ȡ��׼����)����֤ÿ�εĻ��־���
int getMid(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else
		{
			//mid>left;mid>right
			if (a[left] > a[right])
				return left;
			else
				return right;
		}
	}
	else
	{
		//mid<=left
		if (a[left] < a[right])
			return left;
		else
		{
			if (a[mid] > a[right])
				return mid;
			else
				return right;
		}

	}
}
//1.hoare����
int PatrSort1(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	int start = left;
	//Ѱ�Ҵ��ڡ�С�ڻ�׼ֵ��Ԫ�ؽ��н���
	//�ȴ��ұ���С��k��ֵ
	while (left < right)
	{
		while (left < right && a[right] >= key)
			--right;
		//�ٴ�����Ҵ���k��ֵ
		while (left < right && a[left] <= key)
			++left;
		Swap(&a[left], &a[right]);
	}
	//key��λ��ȷ������������λ��
	Swap(&a[start], &a[left]);
	return left;
}
//2.�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	while (left < right)
	{
		//���ұ���С��k��Ԫ��
		while (left < right && a[right] >= key)
			--right;
		//���
		a[left] = a[right];
		//������Ҵ���k��ֵ
		while (left < right && a[left] <= key)
			++left;
		//���
		a[right] = a[left];
	}
	//���key
	//���
	a[left] = key;
	return left;
}
//3.ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	//��ǰ�������һ��С��K��ֵ
	int prev = left;
	//��ǰ������һ��С��K��ֵ
	int cur = prev + 1;
	int key = a[left];
	while (cur <= right)
	{
		//�����һ��С��k��λ������һ��С��k��λ�ò�����
		//˵���м��д���k��ֵ�����н�������--->����ƶ���С<---��ǰ�ƶ�
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	Swap(&a[left], &a[prev]);
	return prev;
}
//�ݹ�д����
void QuickSortRecursion(int* a, int left, int right)
{
	if (left >= right)
		return;
	//�����Ż���С���䲻�õݹ�
	if (right - left + 1 < 5)
		Insertsort(a + left, right - left + 1);
	else
	{
		//int key = PatrSort1(a, left, right);
		int key = PartSort3(a, left, right);
		QuickSortRecursion(a, left, key - 1);
		QuickSortRecursion(a, key + 1, right);
	}
}
//�ǵݹ�д����
//����ջģ��ݹ�Ĺ���
void QuickSort(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	if (left < right)
	{
		//����������ѹջ
		StackPush(&st, right);
		//��������ѹջ
		StackPush(&st, left);
	}
	while (StackEmpty(&st) == 0)
	{
		//������ʼλ��
		int start = StackTop(&st);
		StackPop(&st);
		//�������λ��
		int end = StackTop(&st);
		StackPop(&st);
		//���ֵ�ǰ��������
		int mid = PartSort3(a, start, end);
		//����������:���Ԫ�ظ�������1ʱ���л���
		if (start < mid - 1)
		{
			StackPush(&st, mid - 1);
			StackPush(&st, start);
		}
		//����������:�ұ�Ԫ�ظ�������1ʱ���л���
		if (end > mid + 1)
		{
			StackPush(&st, end);
			StackPush(&st, mid + 1);
		}
	}
}
//7.�鲢����
//ʱ�临�Ӷ�:O(N*logN)
//�ռ临�Ӷȣ�O(N+logN)---->O(N)
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//����ֻʣһ��Ԫ��ʱ������Ҫ�ֽ�͹鲢
	if (left >= right)
		return;
	//�ֽ�
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�鲢[left,mid],[mid+1,right]
	int start1 = left; 
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = right;//begin1---end2->left--->right
	int tmpindex = start1;
	while (start1 <= end1 && start2 <= end2)
	{
		//<:ȡ�ұ�
		//<=:ȡ���
		if (a[start1] <= a[start2])
			tmp[tmpindex++] = a[start1++];
		else
			tmp[tmpindex++] = a[start2++];
	}
	while(start1<=end1)
		tmp[tmpindex++] = a[start1++];
	while(start2<=end2)
		tmp[tmpindex++] = a[start2++];
	//������ԭ�������Ӧ����
	memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
//8.��������
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int* CountArr = (int*)malloc(sizeof(int) * range);
	memset(CountArr, 0, sizeof(int) * range);
	//����
	for (i = 0; i < n; ++i)
		CountArr[a[i] - min]++;
	//����
	int index = 0;
	for (i = 0; i < range; i++)
	{
		while (CountArr[i]--)
			a[index++] = i + min;
	}
}
void TestSort()
{
	int arr[10] = {10,3,4,5,2,6,7,9,1,8};
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//Insertsort(arr, sizeof(arr) / sizeof(arr[0]));
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSortRecursion(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	TestSort();
	return 0;
}
