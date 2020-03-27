#if 0
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
//状态标记元素
enum State
{
	EXIST,//存在
	DELETE,//删除
	EMPTY//空
};
template<class K,class V>
struct Node
{
	pair<K, V>_value;
	State _state;
};
template<class K,class V>
class HashTable
{
public:
	typedef Node<K, V>Node;
	HashTable(size_t N = 2)
	{
		_table.resize(N);//resize之后还可以使用[]进行随机访问
		for (size_t i = 0; i < N; ++i)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}
	bool insert(const pair<K, V>& value)
	{
		//检查容量
		checkCapacity();

		int idx = value.first % _table.size();
		while (_table[idx]._state == EXIST)
		{
			if (_table[idx]._value.first == value.first)
			{
				return false;
			}
			++idx;
			//如果遍历到表尾，则从头开始查找
			if (idx == _table.size())
			{
				idx = 0;
			}
		}
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		++_size;
		return true;
	}
	void checkCapacity()
	{
		//如果超过负载因子，那就需要扩容
		//负载因子：元素个数/数组大小
		if (_size * 10 / _table.size() >= 7)//此处数据皆为整数，无法与0.7比较，所以对两边同*10
		{
			int newsize = _table.size() * 2;
			//增容：
			/*
			不能直接resize，因为元素在新表中的位置可能会发生变化
			_table.resize(newsize);
			*/
			//建新表，旧表中的每一个元素重新计算他们在新表中的位置
			HashTable<K, V>newHashTable(newsize);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				//把旧表中有效的元素全部存入新表
				if (_table[i]._state == EXIST)
				{
					newHashTable.insert(_table[i]._value);
				}
			}	
			_table.swap(newHashTable._table);
		}
	}
	Node* find(const K& key)
	{
		int idx = key % _table.size();
		//查找时遇到空结束
		while (_table[idx]._state != EMPTY)
		{
			//DELETE,EXIST
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
			{
				return &_table[idx] ;
			}
			++idx;
			//检查是否越界
			if (idx == _table.size())
			{
				++idx;
			}
		}
		return nullptr;
	}
	bool erase(const K& key)
	{
		//查找是否存在带删除元素
		Node* pNode = find(key);
		//如果找到了，假删除
		if (pNode)
		{
			pNode->_state = DELETE;
			--_size;
			return true;
		}
		return false;
	}
	void hashTblePrint()
	{             
		for (int i = 0; i < _table.size(); ++i)
		{
			if (_table[i]._state == EXIST)
			{
				cout << _table[i]._value.first << "---->" << _table[i]._value.second << endl;
			}
		}
	}
private:
	vector <Node>_table;
	size_t _size;//已存放元素的个数
};

void test()
{
	HashTable<int, int>ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(18, 18));
	ht.insert(make_pair(23, 23));
	ht.insert(make_pair(4, 4));
	ht.insert(make_pair(54, 54));
	ht.hashTblePrint();
	cout << ht.erase(18) << endl;
	ht.hashTblePrint();
	cout << ht.erase(100) << endl;
	ht.hashTblePrint();
}
int main()
{
	test();
	return 0;
}
#endif