#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
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
//ֱ��ѡ������
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
//������
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
//ð������
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
//����
//����ȡ�з�(�Ż�����һ�е�ȡ��׼����)����֤ÿ�εĻ��־���
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
//��ʽһ��
//ʱ�临�Ӷȣ�O(logN*N)
//�ռ临�Ӷȣ�O(logN)
//���ŵ�һ������ȷ����׼ֵ��λ��
int PatrSort(int* a, int left, int right)
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

//���еݹ�
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