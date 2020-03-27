#if 0
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
//״̬���Ԫ��
enum State
{
	EXIST,//����
	DELETE,//ɾ��
	EMPTY//��
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
		_table.resize(N);//resize֮�󻹿���ʹ��[]�����������
		for (size_t i = 0; i < N; ++i)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}
	bool insert(const pair<K, V>& value)
	{
		//�������
		checkCapacity();

		int idx = value.first % _table.size();
		while (_table[idx]._state == EXIST)
		{
			if (_table[idx]._value.first == value.first)
			{
				return false;
			}
			++idx;
			//�����������β�����ͷ��ʼ����
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
		//��������������ӣ��Ǿ���Ҫ����
		//�������ӣ�Ԫ�ظ���/�����С
		if (_size * 10 / _table.size() >= 7)//�˴����ݽ�Ϊ�������޷���0.7�Ƚϣ����Զ�����ͬ*10
		{
			int newsize = _table.size() * 2;
			//���ݣ�
			/*
			����ֱ��resize����ΪԪ�����±��е�λ�ÿ��ܻᷢ���仯
			_table.resize(newsize);
			*/
			//���±��ɱ��е�ÿһ��Ԫ�����¼����������±��е�λ��
			HashTable<K, V>newHashTable(newsize);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				//�Ѿɱ�����Ч��Ԫ��ȫ�������±�
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
		//����ʱ�����ս���
		while (_table[idx]._state != EMPTY)
		{
			//DELETE,EXIST
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
			{
				return &_table[idx] ;
			}
			++idx;
			//����Ƿ�Խ��
			if (idx == _table.size())
			{
				++idx;
			}
		}
		return nullptr;
	}
	bool erase(const K& key)
	{
		//�����Ƿ���ڴ�ɾ��Ԫ��
		Node* pNode = find(key);
		//����ҵ��ˣ���ɾ��
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
	size_t _size;//�Ѵ��Ԫ�صĸ���
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