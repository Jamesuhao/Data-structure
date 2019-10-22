#include<stdio.h>
#include<string.h>
//1.直接插入排序：待排序序列越接近有序，时间效率越高
//平均时间复杂度：O(N^2)
//最好时间复杂度：O(N)
//最坏时间复杂度：O(N^2)
//辅助空间：O(1)
//稳定性：稳定
void InserSort(int* arr, int length)
{
	int end = 0;
	int i = 0;
	int tmp = 0;
	//对参数的合法性进行检查
	if (arr == NULL || length <= 0)
		return;
	//插入排序的特点就是待排序元素i前的所有元素已经有序，并且不断将元素后移
	//当待排序元素为最后一个元素时即停止排序
	for (i = 0; i < length-1; i++)
	{
		//一个元素的插入
		end = i;
		tmp = arr[end + 1];
		//从该元素前最靠近该元素的位置开始，为该元素寻找合适位置并且其他大于该元素的元素后移
		while (end >= 0 && tmp < arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		//进行插入
		arr[end + 1] = tmp;
	}
}
//2.shell(希尔)排序:对插入排序的一种优化
void ShellSort(int* arr, int length)
{

}
//3.选择排序
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* arr, int length)
{
	if (arr == NULL || length <= 0)
		return;
	int start = 0;
	int end = length - 1;
	int min = 0;
	int max = 0;
	int i = 0;
	while (start < end)
	{
		min = max = start;
		for (i = start; i < end; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		Swap(&arr[start], &arr[min]);
		if (max == start)
			max = min;
		Swap(&arr[end], &arr[max]);
		start++;
		end--;
	}
}
void Print(int* arr,int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void TestSort()
{
	int arr[10] = { 7,4,9,2,3,1,0,5,8,6 };
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	//InserSort(arr, sizeof(arr) / sizeof(arr[0]));
	//Print(arr, sizeof(arr) / sizeof(arr[0]));
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	TestSort();
	return 0;
}