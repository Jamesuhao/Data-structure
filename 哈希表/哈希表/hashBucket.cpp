#include<iostream>
#include<vector>
using namespace std;

//数组+单链表
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
//前置声明：
template<class K, class V, class KeyOfValue>
class HashBucket;

//哈希表的迭代器
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
			//找到当前哈希表中下一个非空链表的头节点
			//计算当前节点在表中的位置
			KeyOfValue kov;
			//友元类可以直接访问私有成员
			int idx = kov(_node->_data % _ht->_table.size());
			//从哈希表的下一个位置开始找到下一个非空链表的头节点
			++idx;
			for (; idx < _ht->_table.size(); ++idx)
			{
				//找到了一个非空链表的头节点
				if (_ht->_table[idx])
				{
					_node = _ht->_table[idx];
					break;
				}
				//有可能后面的节点都为空节点
				if (idx == _ht->_table.size())
				{
					_node = nullptr;//表示是end迭代器的
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
	//把迭代器声明为哈希表的友元类
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
	//不允许插入重复的元素
	bool insert(const V& data)
	{
		checkCapacity();
		//搜索key是否已经存在
		//计算位置
		KeyOfValue kov;
		//除留取余法：计算插入位置
		int idx = kov(data) % _table.size();
		//遍历链表  
		pNode cur = _table[idx];
		while (cur)
		{
			if (kov(cur->_data) == kov(data))
			{
				return false;
			}
			cur = cur->_next;
		}
		//插入    头插
		cur = new Node(data);
		cur->_next = _table[idx];
		_table[idx] = cur;
		
		++_size;
		return true;
	}
	void checkCapacity()
	{
		//负载因子：可以为1
		if (_size == _table.size())
		{
			size_t newCapacity = (_table.size() == 0 ? 10 : 2 * _table.size());
			
			//创建新的vector
			vector<pNode>_newtable;
			_newtable.resize(newCapacity);
			KeyOfValue kov;
			//遍历旧表，酒标节点重新挂载到新表中
			for (size_t i = 0; i < _table.size(); ++i)
			{
				pNode cur = _table[i];
				//遍历当前链表的每一个节点
				while (cur)
				{
					//保存旧表的next节点
					pNode next = cur->_next;
					int idx = kov(cur->_data) % _newtable.size();
					cur->_next = _newtable[idx];
					_newtable[idx] = cur;
					cur = next;
				}
				//旧表当前位置编程空链表
				_table[i] = nullptr;
			}
			_table.swap(_newtable);
		}
		
		bool erase(const K & key);
		pNode find(const K & key);
	}
private:
	//指针数组
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
	//哈希表实现
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


