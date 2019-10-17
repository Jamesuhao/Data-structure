#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
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
//直接选择排序
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
//堆排序
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
//冒泡排序
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
//快排
//三数取中法(优化方法一中的取基准问题)。保证每次的划分均衡
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
//方式一：
//时间复杂度：O(logN*N)
//空间复杂度：O(logN)
//快排的一次排序：确定基准值的位置
int PatrSort(int* a, int left, int right)
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

//进行递归
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 < 5)
	{
		Insertsort(a + left, right - left + 1);
	}
	else
	{
		int mid = PatrSort(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
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
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	TestSort();
	return 0;
}
void QuickSort(int* arr, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && arr[key] <= arr[right])
			right--;
		while (left < right && arr[key] >= arr[left])
			left++;
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[key], &arr[left]);
	return left;
}