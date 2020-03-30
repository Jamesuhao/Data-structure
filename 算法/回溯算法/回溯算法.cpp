#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
#if 0
//子集树模板代码
void func(int arr[], int i, int length,int x[])
{
	if (i == length)//递归结束的条件
	{
		for (int j = 0; j < length; ++j)
		{
			if (x[j] == 1)
			{
				cout << arr[j] << " ";
			}
		}
		cout << endl;
	}
	else
	{
		//写法一：
		x[i] = 1;//选择i节点
		func(arr, i + 1, length,x);//遍历i的左孩子

		x[i] = 0;//不选择i节点
		func(arr, i + 1, length,x);//遍历i的右孩子

		//写法二：
		/*
		for (int k = 1; k >= 0; --k)
		{
			x[i] = k;//选择节点
			func(arr, i + 1, length, x);
		}
		*/
	}
}
int main()
{
	int arr[] = { 1,2,3 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int x[3] = { 0 };
	func(arr, 0, length,x);
	return 0;
}
/*
整数选择问题1：给定一组整数，从里面挑选出一组整数，让选择的整数的和，与剩下的整数的和差值最小。
*/
int arr[] = {12,6,7,11,16,3,8};
const int length = sizeof(arr) / sizeof(arr[0]);
//int x[length] = { 0 }; //子集树辅助数组，记录节点走向左孩子还是右孩子，代表i节点被选择还是未被选择
//int bestx[length] = { 0 };//记录最优解
vector<int>x;
vector<int>bestx;
unsigned int min = 0xFFFFFFFF;//记录最小的差值
int sum = 0;//记录所选子集数字的总和
int r = 0;//记录未选择数字的和
//生成子集树
void func(int i)
{
	if (i == length)//访问到子集树的一个叶子节点
	{
		//sum
		int result = abs(sum - r);
		if (result < min)
		{
			min = result;
			//需要记录一下差值最小的子集
			/*for (int j = 0; j < length; j++)
			{
				bestx[j] = x[j];
			}*/
			bestx = x;
		}

	}
	else
	{
		//走向左孩子
		//x[i] = 1;   选择
		x.push_back(arr[i]);//选择
		sum += arr[i];
		r -= arr[i];
		func(i + 1);
		//回溯到父节点，走向右孩子
		//x[i] = 0;//不选择
		x.pop_back();//不选择
		sum -= arr[i];
		r += arr[i];
		func(i + 1);
	}
}
int main()
{
	for (int v : arr)
	{
		r += v;
	}
	func(0);
	for (const auto& v : bestx)
	{
		cout << v << " ";
	}
	//for (int i = 0; i < length; ++i)
	//{
	//	if (bestx[i] == 1)
	//	{
	//		cout << arr[i] << " ";
	//	}
	//}
	cout << endl;
	cout << min << endl;
	return 0;
}
/*
整数选择问题2：给定2n个整数，从里面挑选出n个整数，使得所选择的整数的和，与未被挑选的整数的和的差值最小
*/
int arr[] = { 12,6,7,11,16,3,8,8 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int>x;//记录子集中选择的元素
vector<int>bestx;//记录最优解
int sum = 0;//记录子集中所选数字的和
int r = 0;//记录未选择数字的和
unsigned int min = 0xFFFFFFFF;//记录最小差值
int Left = length;//记录未处理的数字个数
int cnt = 0;//记录遍历的子集的个数，用于测试
void func(int i)
{
	if (i == length)//到达叶子节点
	{
		cnt++;
		if (x.size() != length / 2)
		{
			return;
		}
		//得到子集树的一个解，对应一个叶子节点
		int result = abs(sum - r);
		if (result < min)
		{
			min = result;
			bestx = x;
		}
	}
	else
	{
		Left--;//处理了一个节点，表示剩余的未处理的元素的个数
		if (x.size() < length / 2)//剪左树枝，提高算法效率。选择数字的前提：还未选择够n个整数
		{
			x.push_back(arr[i]);
			sum += arr[i];
			r -= arr[i];
			func(i + 1);//遍历i的左孩子，选择i号位元素
			x.pop_back();
			sum -= arr[i];
			r += arr[i];
		}
		//右树枝剪枝操作：剪掉已选择的数字的个数+未来能选择的所有的数字的个数<n的操作
		if (x.size() + Left >= length / 2)
		{
			func(i + 1);//遍历i的右孩子，不选择i号位元素
		}
		//当前i节点已处理完成，回溯到其父节点了
		Left++;
	}
}
int main()
{
	for (const int v : arr)
	{
		r += v;
	}
	func(0);
	for (const int v : bestx)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "min："<<min << endl;
	cout << "cnt："<<cnt << endl;
	return 0;
}
/*
挑选数字1：有一组整数，请挑选出一组数字，让他们的和等于指定的值，输出存在解，不存在输出。
*/
int arr[] = { 4,8,12,16,7,9,3,6};
int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
vector<int>x;//记录选择的数字
int sum = 0;
int cnt = 0;
int Left = 0;//记录未处理的数字的和
void func(int i)
{
	if (i == length)
	{
		cnt++;
		if (sum != number)
		{
			return;
		}
		for (int v : x)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	else
	{
		Left -= arr[i];//处理当前节点
		//左剪枝：剪掉已选择的数字的和+即将要选择的数字>number
		if (sum + arr[i] <= number)
		{
			sum += arr[i];
			x.push_back(arr[i]);
			func(i + 1);
			sum -= arr[i];
			x.pop_back();
		}
		//右剪枝：剪掉已选择+未选择的数的总和(i+1,i+2...n)<18
		if (sum + Left >= number)
		{
			func(i + 1);
		}
		//回溯到父节点
		Left += arr[i];
	}
}
int main()
{
	for (int v : arr)
	{
		Left += v;
	}
	func(0);
	cout << "cnt：" <<cnt<< endl;
	return 0;
}

/*
挑选数字2：有一组整数，请挑选出一组数字，让他们的和等于指定的值，存在解输出。
*/
int arr[] = { 4,8,12,16,7,9,3 ,3};
int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
vector<int>vec;//存放选择的数字
int cnt = 0;
void func(int i, int number)
{
	if (number == 0)
	{
		cnt++;
		for (int v : vec)
		{
			cout << v << " ";
		}
		cout << endl;
	} 
	else
	{
		//以当前节点开始，把剩余元素的孩子节点生成
		for (int k = i; k < length; ++k)
		{
			if (number >= arr[k])//剩余的元素必须小于number(待组成的元素值)
			{
				vec.push_back(arr[k]);
				//从当前层遍历到下一层的时候  arr[k] != arr[k-1]
				//不允许重复选择元素
				func(k + 1, number-arr[k]);//遍历arr[k]的孩子节点
				//允许重复选择元素
				//func(k, number - arr[k]);
				vec.pop_back();
			}
		}
	}
}
int main()
{
	func(0, number);
	cout << cnt << endl;
	return 0;
}
/*
0-1背包问题：有一组物品，其重量分别是：w1,w2...wn，其价值分别是v1,v2...vn，现有一个背包，其容量是C。
问怎么把物品装入背包，能够使背包的价值最大化？
*/
int w[] = { 12,5,8,9,6 };//物品的重量
int v[] = { 9,2,4,7,8 };//物品的价值
const int length = sizeof(w) / sizeof(w[0]);
vector<int>x;//选择的物品
vector<int>bestx;//记录最优选择的物品
int c = 20;//背包的容量
int cw = 0;//已选择物品的重量
int cv = 0;//已选择物品的价值
int bestv = 0;//记录装入背包的物品最大价值
int r = 0;//未处理物品的总价值
void func(int i)
{
	if (i == length)
	{
		if (bestv <= cv)
		{
			bestv = cv;
			bestx = x;
		}
	}
	else
	{
		r -= v[i];
		if (cw + w[i] <= c)//已选择物品的重量+即将选择的第i号物品的重量
		{
			cw += w[i];
			cv += v[i];
			x.push_back(w[i]);
			func(i + 1);
			cw -= w[i];
			cv -= v[i];
			x.pop_back();
		}
		if (cv + r > bestv)
		{
			func(i + 1);
		}
		r += v[i];
	}
}
int main()
{
	for (int val : v)
	{
		r += val;
	}
	func(0);
	for (int w : bestx)
	{
		cout << w << " ";
	}
	cout << endl;
	cout << "bestv:" << bestv << endl;
	return 0;
}
void _letterCasePermutation(int i, string S,vector<string>& res)
{
	int length = S.size();
	if (i == length)
	{
		res.push_back(S);
	}
	else
	{
		if (S[i] >= 'A' && S[i] <= 'Z')
		{
			_letterCasePermutation(i + 1, S, res);
			S[i] += 32;
			_letterCasePermutation(i + 1, S, res);
		}
		else if (S[i] >= 'a' && S[i] <= 'z')
		{
			_letterCasePermutation(i + 1, S, res);
			S[i] -= 32;
			_letterCasePermutation(i + 1, S, res);
		}
		else
		{
			_letterCasePermutation(i + 1, S, res);
		}
	}
}
vector<string> letterCasePermutation(string S)
{
	vector<string>res;
	_letterCasePermutation(0, S, res);
	return res;
}
int main()
{
	string S = "a1b2";
	vector<string>vec;
	vec=letterCasePermutation(S);
	for (const auto v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
}
#endif
