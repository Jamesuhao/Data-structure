#include<stdio.h>
#include<string.h>
//1.ֱ�Ӳ������򣺴���������Խ�ӽ�����ʱ��Ч��Խ��
//ƽ��ʱ�临�Ӷȣ�O(N^2)
//���ʱ�临�Ӷȣ�O(N)
//�ʱ�临�Ӷȣ�O(N^2)
//�����ռ䣺O(1)
//�ȶ��ԣ��ȶ�
void InserSort(int* arr, int length)
{
	int end = 0;
	int i = 0;
	int tmp = 0;
	//�Բ����ĺϷ��Խ��м��
	if (arr == NULL || length <= 0)
		return;
	//����������ص���Ǵ�����Ԫ��iǰ������Ԫ���Ѿ����򣬲��Ҳ��Ͻ�Ԫ�غ���
	//��������Ԫ��Ϊ���һ��Ԫ��ʱ��ֹͣ����
	for (i = 0; i < length-1; i++)
	{
		//һ��Ԫ�صĲ���
		end = i;
		tmp = arr[end + 1];
		//�Ӹ�Ԫ��ǰ�����Ԫ�ص�λ�ÿ�ʼ��Ϊ��Ԫ��Ѱ�Һ���λ�ò����������ڸ�Ԫ�ص�Ԫ�غ���
		while (end >= 0 && tmp < arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		//���в���
		arr[end + 1] = tmp;
	}
}
//2.shell(ϣ��)����:�Բ��������һ���Ż�
void ShellSort(int* arr, int length)
{

}
//3.ѡ������
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