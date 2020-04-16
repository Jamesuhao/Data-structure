#include"Adjust_algorithm.h"
#include"heap.h"
#include<iostream>
using namespace std;
void test()
{
	int arr[] = { 16,10,14,8,7,9,3,2,4,1 };
	HeapSort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}