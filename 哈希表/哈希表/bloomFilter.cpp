#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
λͼ�����ݵ�Ԫ��С�Ĺ�ϣ��
��ϣ������������Ϊ��ֱ�Ӷ�ַ��num/32,num%32
*/
class BitMap
{
public:
	BitMap(size_t range)
	{
		_array.resize((range >> 5) + 1);
	}
	//�������
	void set(int data)
	{
		//ͨ����ϣ��������λ��
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] |= (1 << bitIdx);
	}
	//����
	bool test(int data)
	{
		//ͨ����ϣ��������λ��
		int idx = data >> 5;
		int bitIdx = data % 32;
		return (_array[idx] >> bitIdx) & 1;
	}
	//ɾ��
	void reset(int data)
	{
		//ͨ����ϣ��������λ��
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] &= ~(1 << bitIdx);
	}
private:
	vector<int>_array;
};
template<class K, class HF1, class HF2, class HF3>
class BloomFilter
{
public:
	//K = m/2*ln2   => m=nk/ln2
	//m��ʾ�����С��k��ʾ��ϣ�����ĸ���
	BloomFilter(size_t range)
		:_bm(range * 5)
		, _bitNum(range * 5)
	{ }
	void set(const K& key)
	{
		//��ֹidxԽ�磺%_bitNum
		size_t idx1 = HF1()(key) % _bitNum;
		size_t idx2 = HF2()(key) % _bitNum;
		size_t idx3 = HF3()(key) % _bitNum;
		_bm.set(idx1);
		_bm.set(idx2);
		_bm.set(idx3);
	}
	bool test(const string& key)
	{
		size_t idx1 = HF1()(key) % _bitNum;
		size_t idx2 = HF2()(key) % _bitNum;
		size_t idx3 = HF3()(key) % _bitNum;
		if (!_bm.test(idx1))
			return false;
		if (!_bm.test(idx2))
			return false;
		if (!_bm.test(idx3))
			return false;
		return true;
	}
private:
	BitMap _bm;
	size_t _bitNum;
};
struct HF1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};
struct HF2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};
struct HF3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		size_t magic = 63689;
		for (const auto& ch : str)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};
void testBloomFilter()
{
	BloomFilter<string, HF1, HF2, HF3>bf(10);
	string str1 = "1233asdasdwadasdsandklwnld";
	string str2 = "1233asdasdwadasdsandklwnlc";
	string str3 = "1233asdasdwadasdsandklwnle";

	bf.set(str1);
	bf.set(str2);
	bf.set(str3);

	bool ret = bf.test(str1);
	ret = bf.test(str2);
	ret = bf.test(str3);
	ret = bf.test(str3 + 'a');
}
int main()
{
	testBloomFilter();
	return 0;
}