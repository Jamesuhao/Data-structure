#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
#include"Stack.h"
//1.直接插入排序
//时间复杂度：O(n^2)
//空间复杂度：O(1)
//适用于已经接近有序的序列
//稳定性：稳定
void Insertsort(int* arr, int n)
{
	int i = 0;
	int end = 0;
	int tmp = 0;
	assert(arr);
	for (i = 0; i < n - 1; i++)
	{
		//单个元素的排序
		//找到已经排好的最后一个元素的位置
		end = i;
		//把end+1位置的元素插入到合适的位置
		tmp = arr[end + 1];
		while (end >= 0 && tmp < arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		//找到合适的位置
		arr[end + 1] = tmp;
	}
}
//2.希尔排序(缩小增量排序)
//时间：O(N^1.3--N^2)
//空间：O(1)
void ShellSort(int* arr, int n)
{
	int i = 0;
	int gap = n;
	int end = 0;
	int tmp = 0;
	//for(gap>=1;gap-=num)//预排序的次数
	//for (num = 0; num < gap; num++)//待排序的组别
	while (gap > 1)
	{
		//gap>1:预排序
		//gap=1:排序
		gap = gap / 2 + 1;//保证最后为插入排序
		for (i = 0; i < n - gap; i++)//插入排序
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
//3.直接选择排序
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
		//每次选择一个最大的和最小的，放到相应的位置
		int i = 0; 
		max = min = begin;
		//小的选第一个，大的选最后一个
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
		//判断最大元素的位置是否变化
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}

}
//4.堆排序
//建堆：向下调整算法
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
//进行堆排序
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
//5.冒泡排序
//时间复杂度:最好情况下：O(N) 最坏情况下：O(N^2)
//空间复杂度:O(1)
//稳定性:稳定
void BubbleSort(int* arr,int n)
{
	int i = 0;
	int end = n - 1;
	while (end > 1)
	{
		//flag:判断一趟比较过程中是否发生元素交换
		//如果未发生元素交换，则说明当前序列已经有序，提前结束
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
//6.快排
//时间复杂度：O(logN*N)
//空间复杂度：O(logN)
//快排的一次排序：确定基准值的位置


//三数取中法(优化取基准问题)。保证每次的划分均衡
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
//1.hoare法：
int PatrSort1(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	int start = left;
	//寻找大于、小于基准值的元素进行交换
	//先从右边找小于k的值
	while (left < right)
	{
		while (left < right && a[right] >= key)
			--right;
		//再从左边找大于k的值
		while (left < right && a[left] <= key)
			++left;
		Swap(&a[left], &a[right]);
	}
	//key的位置确定：即相遇的位置
	Swap(&a[start], &a[left]);
	return left;
}
//2.挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	while (left < right)
	{
		//从右边找小于k的元素
		while (left < right && a[right] >= key)
			--right;
		//填坑
		a[left] = a[right];
		//从左边找大于k的值
		while (left < right && a[left] <= key)
			++left;
		//填坑
		a[right] = a[left];
	}
	//存放key
	//填坑
	a[left] = key;
	return left;
}
//3.前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	//当前序列最后一个小于K的值
	int prev = left;
	//当前序列下一个小于K的值
	int cur = prev + 1;
	int key = a[left];
	while (cur <= right)
	{
		//如果下一个小于k的位置与上一个小于k的位置不连续
		//说明中间有大于k的值，进行交换，大--->向后移动，小<---向前移动
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	Swap(&a[left], &a[prev]);
	return prev;
}
//递归写法：
void QuickSortRecursion(int* a, int left, int right)
{
	if (left >= right)
		return;
	//区间优化：小区间不用递归
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
//非递归写法：
//利用栈模拟递归的过程
void QuickSort(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	if (left < right)
	{
		//把右区间先压栈
		StackPush(&st, right);
		//把左区间压栈
		StackPush(&st, left);
	}
	while (StackEmpty(&st) == 0)
	{
		//区间起始位置
		int start = StackTop(&st);
		StackPop(&st);
		//区间结束位置
		int end = StackTop(&st);
		StackPop(&st);
		//划分当前序列区间
		int mid = PartSort3(a, start, end);
		//划分左区间:左边元素个数大于1时进行划分
		if (start < mid - 1)
		{
			StackPush(&st, mid - 1);
			StackPush(&st, start);
		}
		//划分右区间:右边元素个数大于1时进行划分
		if (end > mid + 1)
		{
			StackPush(&st, end);
			StackPush(&st, mid + 1);
		}
	}
}
//7.归并排序
//时间复杂度:O(N*logN)
//空间复杂度：O(N+logN)---->O(N)
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//区间只剩一个元素时，不需要分解和归并
	if (left >= right)
		return;
	//分解
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//归并[left,mid],[mid+1,right]
	int start1 = left; 
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = right;//begin1---end2->left--->right
	int tmpindex = start1;
	while (start1 <= end1 && start2 <= end2)
	{
		//<:取右边
		//<=:取左边
		if (a[start1] <= a[start2])
			tmp[tmpindex++] = a[start1++];
		else
			tmp[tmpindex++] = a[start2++];
	}
	while(start1<=end1)
		tmp[tmpindex++] = a[start1++];
	while(start2<=end2)
		tmp[tmpindex++] = a[start2++];
	//拷贝到原有数组对应区间
	memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
//8.计数排序
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
	//计数
	for (i = 0; i < n; ++i)
		CountArr[a[i] - min]++;
	//排序
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
