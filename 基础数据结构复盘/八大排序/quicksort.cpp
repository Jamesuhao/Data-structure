/*
1.快速排序：
基本思想：任取待排序序列中的某元素作为基准值，按照该基准值将待排序序列分成两个子序列；
				左子序列中所有元素均小于基准值，右子序列均大于基准值；
				然后在左右子序列中重复上述过程，直到所有元素都有序。

具体实现：在待排序序列中选取一个基准值，在left小于right的情况下，遍历待排序序列；
				先从序列的最右边向左遍历选取比基准值小的元素，再从序列的最左边向右遍历选取比基准值大的元素，将两者进行交换；
				当left>=right时，一趟排序结束；
				因为每一次遍历均先从右边向左遍历选取比基准值小的元素，所以相遇位置处的值比小于基准值，此时将left和key位置(即相遇位置)的元素进行交换；
				此时，基准值左边的元素均小于基准值，基准值右边的元素均大于基准值。

时间复杂度：O(nlogn)~O(n^2)
	最好情况：每一次恰好中分O(nlogn)
	最坏情况：退化成冒泡排序O(n^2)

空间复杂度：O(logn)

稳定性：不稳定

优化：对基准值进行优化，采取三数取中法选择基准值
*/
//代码：
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