#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
#if 0
//�Ӽ���ģ�����
void func(int arr[], int i, int length,int x[])
{
	if (i == length)//�ݹ����������
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
		//д��һ��
		x[i] = 1;//ѡ��i�ڵ�
		func(arr, i + 1, length,x);//����i������

		x[i] = 0;//��ѡ��i�ڵ�
		func(arr, i + 1, length,x);//����i���Һ���

		//д������
		/*
		for (int k = 1; k >= 0; --k)
		{
			x[i] = k;//ѡ��ڵ�
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
����ѡ������1������һ����������������ѡ��һ����������ѡ��������ĺͣ���ʣ�µ������ĺͲ�ֵ��С��
*/
int arr[] = {12,6,7,11,16,3,8};
const int length = sizeof(arr) / sizeof(arr[0]);
//int x[length] = { 0 }; //�Ӽ����������飬��¼�ڵ��������ӻ����Һ��ӣ�����i�ڵ㱻ѡ����δ��ѡ��
//int bestx[length] = { 0 };//��¼���Ž�
vector<int>x;
vector<int>bestx;
unsigned int min = 0xFFFFFFFF;//��¼��С�Ĳ�ֵ
int sum = 0;//��¼��ѡ�Ӽ����ֵ��ܺ�
int r = 0;//��¼δѡ�����ֵĺ�
//�����Ӽ���
void func(int i)
{
	if (i == length)//���ʵ��Ӽ�����һ��Ҷ�ӽڵ�
	{
		//sum
		int result = abs(sum - r);
		if (result < min)
		{
			min = result;
			//��Ҫ��¼һ�²�ֵ��С���Ӽ�
			/*for (int j = 0; j < length; j++)
			{
				bestx[j] = x[j];
			}*/
			bestx = x;
		}

	}
	else
	{
		//��������
		//x[i] = 1;   ѡ��
		x.push_back(arr[i]);//ѡ��
		sum += arr[i];
		r -= arr[i];
		func(i + 1);
		//���ݵ����ڵ㣬�����Һ���
		//x[i] = 0;//��ѡ��
		x.pop_back();//��ѡ��
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
����ѡ������2������2n����������������ѡ��n��������ʹ����ѡ��������ĺͣ���δ����ѡ�������ĺ͵Ĳ�ֵ��С
*/
int arr[] = { 12,6,7,11,16,3,8,8 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int>x;//��¼�Ӽ���ѡ���Ԫ��
vector<int>bestx;//��¼���Ž�
int sum = 0;//��¼�Ӽ�����ѡ���ֵĺ�
int r = 0;//��¼δѡ�����ֵĺ�
unsigned int min = 0xFFFFFFFF;//��¼��С��ֵ
int Left = length;//��¼δ��������ָ���
int cnt = 0;//��¼�������Ӽ��ĸ��������ڲ���
void func(int i)
{
	if (i == length)//����Ҷ�ӽڵ�
	{
		cnt++;
		if (x.size() != length / 2)
		{
			return;
		}
		//�õ��Ӽ�����һ���⣬��Ӧһ��Ҷ�ӽڵ�
		int result = abs(sum - r);
		if (result < min)
		{
			min = result;
			bestx = x;
		}
	}
	else
	{
		Left--;//������һ���ڵ㣬��ʾʣ���δ�����Ԫ�صĸ���
		if (x.size() < length / 2)//������֦������㷨Ч�ʡ�ѡ�����ֵ�ǰ�᣺��δѡ��n������
		{
			x.push_back(arr[i]);
			sum += arr[i];
			r -= arr[i];
			func(i + 1);//����i�����ӣ�ѡ��i��λԪ��
			x.pop_back();
			sum -= arr[i];
			r += arr[i];
		}
		//����֦��֦������������ѡ������ֵĸ���+δ����ѡ������е����ֵĸ���<n�Ĳ���
		if (x.size() + Left >= length / 2)
		{
			func(i + 1);//����i���Һ��ӣ���ѡ��i��λԪ��
		}
		//��ǰi�ڵ��Ѵ�����ɣ����ݵ��丸�ڵ���
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
	cout << "min��"<<min << endl;
	cout << "cnt��"<<cnt << endl;
	return 0;
}
/*
��ѡ����1����һ������������ѡ��һ�����֣������ǵĺ͵���ָ����ֵ��������ڽ⣬�����������
*/
int arr[] = { 4,8,12,16,7,9,3,6};
int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
vector<int>x;//��¼ѡ�������
int sum = 0;
int cnt = 0;
int Left = 0;//��¼δ��������ֵĺ�
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
		Left -= arr[i];//����ǰ�ڵ�
		//���֦��������ѡ������ֵĺ�+����Ҫѡ�������>number
		if (sum + arr[i] <= number)
		{
			sum += arr[i];
			x.push_back(arr[i]);
			func(i + 1);
			sum -= arr[i];
			x.pop_back();
		}
		//�Ҽ�֦��������ѡ��+δѡ��������ܺ�(i+1,i+2...n)<18
		if (sum + Left >= number)
		{
			func(i + 1);
		}
		//���ݵ����ڵ�
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
	cout << "cnt��" <<cnt<< endl;
	return 0;
}

/*
��ѡ����2����һ������������ѡ��һ�����֣������ǵĺ͵���ָ����ֵ�����ڽ������
*/
int arr[] = { 4,8,12,16,7,9,3 ,3};
int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
vector<int>vec;//���ѡ�������
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
		//�Ե�ǰ�ڵ㿪ʼ����ʣ��Ԫ�صĺ��ӽڵ�����
		for (int k = i; k < length; ++k)
		{
			if (number >= arr[k])//ʣ���Ԫ�ر���С��number(����ɵ�Ԫ��ֵ)
			{
				vec.push_back(arr[k]);
				//�ӵ�ǰ���������һ���ʱ��  arr[k] != arr[k-1]
				//�������ظ�ѡ��Ԫ��
				func(k + 1, number-arr[k]);//����arr[k]�ĺ��ӽڵ�
				//�����ظ�ѡ��Ԫ��
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
0-1�������⣺��һ����Ʒ���������ֱ��ǣ�w1,w2...wn�����ֵ�ֱ���v1,v2...vn������һ����������������C��
����ô����Ʒװ�뱳�����ܹ�ʹ�����ļ�ֵ��󻯣�
*/
int w[] = { 12,5,8,9,6 };//��Ʒ������
int v[] = { 9,2,4,7,8 };//��Ʒ�ļ�ֵ
const int length = sizeof(w) / sizeof(w[0]);
vector<int>x;//ѡ�����Ʒ
vector<int>bestx;//��¼����ѡ�����Ʒ
int c = 20;//����������
int cw = 0;//��ѡ����Ʒ������
int cv = 0;//��ѡ����Ʒ�ļ�ֵ
int bestv = 0;//��¼װ�뱳������Ʒ����ֵ
int r = 0;//δ������Ʒ���ܼ�ֵ
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
		if (cw + w[i] <= c)//��ѡ����Ʒ������+����ѡ��ĵ�i����Ʒ������
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
