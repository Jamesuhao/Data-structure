/*
1.��������
����˼�룺��ȡ�����������е�ĳԪ����Ϊ��׼ֵ�����ոû�׼ֵ�����������зֳ����������У�
				��������������Ԫ�ؾ�С�ڻ�׼ֵ���������о����ڻ�׼ֵ��
				Ȼ�����������������ظ��������̣�ֱ������Ԫ�ض�����

����ʵ�֣��ڴ�����������ѡȡһ����׼ֵ����leftС��right������£��������������У�
				�ȴ����е����ұ��������ѡȡ�Ȼ�׼ֵС��Ԫ�أ��ٴ����е���������ұ���ѡȡ�Ȼ�׼ֵ���Ԫ�أ������߽��н�����
				��left>=rightʱ��һ�����������
				��Ϊÿһ�α������ȴ��ұ��������ѡȡ�Ȼ�׼ֵС��Ԫ�أ���������λ�ô���ֵ��С�ڻ�׼ֵ����ʱ��left��keyλ��(������λ��)��Ԫ�ؽ��н�����
				��ʱ����׼ֵ��ߵ�Ԫ�ؾ�С�ڻ�׼ֵ����׼ֵ�ұߵ�Ԫ�ؾ����ڻ�׼ֵ��

ʱ�临�Ӷȣ�O(nlogn)~O(n^2)
	��������ÿһ��ǡ���з�O(nlogn)
	�������˻���ð������O(n^2)

�ռ临�Ӷȣ�O(logn)

�ȶ��ԣ����ȶ�

�Ż����Ի�׼ֵ�����Ż�����ȡ����ȡ�з�ѡ���׼ֵ
*/
//���룺
#include<iostream>
#include<vector>
#include<algorithm>
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int Portion(std::vector<int>& vec, int left, int right)
{
	int key = vec[left];
	int start = left;
	while (left < right)
	{
		while (left < right && vec[right] >= key)
			--right;
		while (left < right && vec[left] <= key)
			++left;
		swap(vec[left], vec[right]);
	}
	swap(vec[start], vec[left]);
	return left;
}
void QuickSort(std::vector<int>& vec, int left, int right)
{
	if (left >= right)
		return;
	int key = Portion(vec, left, right);
	QuickSort(vec, left, key - 1);
	QuickSort(vec, key + 1, right);
}