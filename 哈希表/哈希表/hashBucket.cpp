#include<iostream>
#include<vector>
using namespace std;

//����+������
template <class V>
struct HashNode
{
	HashNode<V>* _next;
	V _data;
	HashNode(const V& data = V())
		:_data(data)
		, _next(nullptr)
	{ }
};
//ǰ��������
template<class K, class V, class KeyOfValue>
class HashBucket;

//��ϣ��ĵ�����
template<class K, class V, class KeyOfValue>
struct HIterator
{
	typedef HashNode<V>Node;
	typedef Node* pNode;
	typedef HIterator<K,V, KeyOfValue>Self;
	typedef HashBucket<K, V, KeyOfValue>htbale;

	pNode _node;
	htbale* _ht;
	HIterator(pNode node)
		:_node(node)
	{ }
	V& operator*()
	{
		return _node->_data;
	}
	V* operator->()
	{
		return &_node->_data;
	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->next;
		}
		else
		{
			//�ҵ���ǰ��ϣ������һ���ǿ������ͷ�ڵ�
			//���㵱ǰ�ڵ��ڱ��е�λ��
			KeyOfValue kov;
			//��Ԫ�����ֱ�ӷ���˽�г�Ա
			int idx = kov(_node->_data % _ht->_table.size());
			//�ӹ�ϣ�����һ��λ�ÿ�ʼ�ҵ���һ���ǿ������ͷ�ڵ�
			++idx;
			for (; idx < _ht->_table.size(); ++idx)
			{
				//�ҵ���һ���ǿ������ͷ�ڵ�
				if (_ht->_table[idx])
				{
					_node = _ht->_table[idx];
					break;
				}
				//�п��ܺ���Ľڵ㶼Ϊ�սڵ�
				if (idx == _ht->_table.size())
				{
					_node = nullptr;//��ʾ��end��������
				}
			}
		}
		return *this;
	}
};

template<class K,class V,class KeyOfValue>
class HashBucket
{
public:
	//�ѵ���������Ϊ��ϣ�����Ԫ��
	template<class K, class V, class KeyOfValue>
	friend struct HIterator;

	typedef HashNode<V>Node;
	typedef Node* pNode;

	typedef HIterator<K,V, KeyOfValue>iterator;

	iterator begin()
	{

	}
	iterator end()
	{

	}
	//����������ظ���Ԫ��
	bool insert(const V& data)
	{
		checkCapacity();
		//����key�Ƿ��Ѿ�����
		//����λ��
		KeyOfValue kov;
		//����ȡ�෨���������λ��
		int idx = kov(data) % _table.size();
		//��������  
		pNode cur = _table[idx];
		while (cur)
		{
			if (kov(cur->_data) == kov(data))
			{
				return false;
			}
			cur = cur->_next;
		}
		//����    ͷ��
		cur = new Node(data);
		cur->_next = _table[idx];
		_table[idx] = cur;
		
		++_size;
		return true;
	}
	void checkCapacity()
	{
		//�������ӣ�����Ϊ1
		if (_size == _table.size())
		{
			size_t newCapacity = (_table.size() == 0 ? 10 : 2 * _table.size());
			
			//�����µ�vector
			vector<pNode>_newtable;
			_newtable.resize(newCapacity);
			KeyOfValue kov;
			//�����ɱ��Ʊ�ڵ����¹��ص��±���
			for (size_t i = 0; i < _table.size(); ++i)
			{
				pNode cur = _table[i];
				//������ǰ�����ÿһ���ڵ�
				while (cur)
				{
					//����ɱ��next�ڵ�
					pNode next = cur->_next;
					int idx = kov(cur->_data) % _newtable.size();
					cur->_next = _newtable[idx];
					_newtable[idx] = cur;
					cur = next;
				}
				//�ɱ�ǰλ�ñ�̿�����
				_table[i] = nullptr;
			}
			_table.swap(_newtable);
		}
		
		bool erase(const K & key);
		pNode find(const K & key);
	}
private:
	//ָ������
	vector<pNode>_table;
	size_t _size = 0;
};
template<class K,class V>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
	//��ϣ��ʵ��
public:
	bool insert(const pair<K,V>& data)
	{
		return _hb.insert(data);
	}
private:
	HashBucket<K, pair<K, V>, MapKeyOfValue>_hb;
};
template<class V>
class UnorderedSet
{
	struct SetKeyOfValue
	{
		const V& operator()(const V& data)
		{
			return data;
		}
	};
public:
	bool insert(const V& data)
	{
		return _hb.insert(data);
	}
private:
	HashBucket<V ,V, SetKeyOfValue>_hb;
};
void testUnorderedMap()
{
	UnorderedMap<int,int>ump;
	ump.insert(make_pair(1, 1));
	ump.insert(make_pair(2, 2));
	ump.insert(make_pair(3, 3));
	ump.insert(make_pair(4, 4));
	ump.insert(make_pair(5, 5));
}
void testUnorderedSet()
{
	UnorderedSet<int>_ust;
	_ust.insert(1);
	_ust.insert(2);
	_ust.insert(3);
	_ust.insert(4);
	_ust.insert(5);
}
/*
template<class K>
struct KeyOfValue
{
	const K& operator()(const K& key)
	{
		return key;
	}
};
void test()
{
	HashBucket<int, int, KeyOfValue<int>>_hb;
	_hb.insert(21);
	_hb.insert(48);
	_hb.insert(36);
	_hb.insert(43);
	_hb.insert(5);
	_hb.insert(61);
	_hb.insert(78);
	_hb.insert(15);
	_hb.insert(6);
	_hb.insert(23);
	_hb.insert(51);
	_hb.insert(52);
	_hb.insert(53);
	_hb.insert(54);
	_hb.insert(55);
	_hb.insert(56);
}
*/
int main()
{
	//test();
	return 0;
}


