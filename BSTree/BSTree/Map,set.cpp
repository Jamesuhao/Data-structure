#include<iostream>
#include<stack>
#include <utility>
using namespace std;
/*
红黑树实现map,set
*/

//枚举建立节点颜色
enum CLOLR
{
	BLACK,
	RED
};
//节点只关心value
template<typename V>
struct RBNode
{
	RBNode<V>* _left;
	RBNode<V>* _right;
	RBNode<V>* _parent;
	V _value;
	//颜色
	CLOLR _color;
	RBNode(const V& value = V())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};
template<typename V>
struct RBTIterator
{
	//封装节点，实现迭代器的功能，类似于list迭代器的实现
	typedef RBNode<V> Node;
	typedef Node* pNode;
	typedef RBTIterator<V> self;
	pNode _node;
	RBTIterator(pNode node)
		:_node(node)
	{ }
	V& operator*()
	{
		return _node->_value;
	}
	V* operator ->()
	{
		return &_node->_value;
	}
	bool operator!=(const self& it)
	{
		return _node != it._node;
	}
	/*
	前置++：中序遍历，当前节点的左子树已经访问完了，
			判断当前迭代器所在的节点是否有右节点
			如果有：迭代器移动到当前节点右子树的最左节点
			如果没有：向上回溯，找到一个满足当前节点不是所找到节点的右子树的节点
	*/
	self& operator++()
	{
		//如果存在右节点，移动到右子树的最左节点
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		//不存在右节点，向上回溯，找到一个满足当前节点不是所找到节点的右子树的节点
		else
		{
			pNode parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			//特殊情况：_node->_right==parent
			//整棵树没有右子树，且_node指向_header
			if (_node->_right != parent)
				_node = parent;
		}
		return *this;
	}
	/*
	前置--：
	当前节点的左孩子存在：走到左子树的最右节点
	当前节点的左孩子不存在：向上回溯，找到一个满足当前节点不是所找到节点的左子树的节点
	*/
	self& operator--()
	{
		if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
			{
				_node = _node->_right;
			}
		}
		else
		{
			pNode parent = _node->_parent;
			while (_node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if (_node->_left != parent)
			{
				_node = parent;
			}
		}
		return *this;
	}
};
template<typename K, typename V,typename KeyOfValue>
class RBTree
{
public:
	typedef RBNode<V>Node;
	typedef Node* pNode;
	typedef RBTIterator<V> iterator;
	iterator begin()
	{
		return iterator(_header->_left);
	}
	iterator end()
	{
		return iterator(_header);
	}
	iterator rbegin()
	{
		return iterator(_header->_right);
	}
	RBTree()
	{
		//构建一个空的红黑树
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}
	pair<iterator,bool> insert(const V& value)
	{
		//搜索树的插入
		if (_header->_parent == nullptr)
		{
			//空树，创建根节点
			pNode root = new Node(value);
			//根的颜色是黑色
			root->_color = BLACK;
			//根的父亲是头
			root->_parent = _header;
			//头的父亲是根
			_header->_parent = root;
			//头的左孩子是树的最左节点
			_header->_left = root;
			//头的右孩子是树的最右节点
			_header->_right = root;
			return make_pair(iterator(root), true);
		}
		//从头开始搜索
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		//通过仿函数对象获取V对应的K
		KeyOfValue kov;
		while (cur)
		{
			//对于不同的V，需要获取V对应的K
			if (kov(cur->_value) == kov(value))
			{
				return make_pair(iterator(cur),false);
			}
			else if (kov(cur->_value) > kov(value))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
		//找到插入位置，生成新节点，进行插入
		cur = new Node(value);
		pNode newnode = cur;
		//如果新节点小于父节点，则插在左边
		if (kov(parent->_value) > kov(cur->_value))
		{
			parent->_left = cur;
		}
		//如果新节点大于父节点，则插在右边
		else
		{
			parent->_right = cur;
		}
		//连接新节点的父节点指向
		cur->_parent = parent;

		//调整和更新(更新颜色）
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				//uncle存在且为红
				if (uncle && uncle->_color == RED)
				{
					//修改颜色
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//继续向上更新
					cur = gfather;
				}
				else
				{
					//如果存在双旋的场景，可以先进行一次单旋，使它变成单旋的场景
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//右旋
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				pNode uncle = gfather->_left;
				//uncle存在且为红
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				//uncle不存在或者uncle存在且为黑
				else
				{
					//判断是否是双旋的场景
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		//根的颜色始终是黑的
		_header->_parent->_color = BLACK;
		//更新_header->_left,_header->_right
		_header->_left = leftMost();
		_header->_right = rightMost();
		return make_pair(iterator(newnode),true);
	}
	void RotateR(pNode parent)
	{
		if (parent == nullptr)
		{
			return;
		}
		pNode subL = parent->_left;
		pNode subLR = subL->_right;
		pNode gparent = parent->_parent;
		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		if (parent != _header->_parent)
		{
			subL->_parent = gparent;
			if (gparent->_left == parent)
			{
				gparent->_left = subL;
			}
			else
			{
				gparent->_right = subL;
			}
		}
		else
		{
			_header->_parent = subL;
			subL->_parent = _header;
		}
		parent->_parent = subL;
	}
	void RotateL(pNode parent)
	{
		if (parent == nullptr)
		{
			return;
		}
		pNode gparent = parent->_parent;
		pNode subR = parent->_right;
		pNode subRL = subR->_left;
		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		if (parent != _header->_parent)
		{
			subR->_parent = gparent;
			if (gparent->_left == parent)
			{
				gparent->_left = subR;
			}
			else
			{
				gparent->_right = subR;
			}
		}
		else
		{
			_header->_parent = subR;
			subR->_parent = _header;

		}
		parent->_parent = subR;
	}
	pNode leftMost()
	{
		pNode cur = _header->_parent;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	pNode rightMost()
	{
		pNode cur = _header->_parent;
		while (cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}
	void inOrder()
	{
		if (_header->_parent == nullptr)
		{
			return;
		}
		pNode cur = _header->_parent;
		stack<pNode>s;
		while (!s.empty() || cur != nullptr)
		{
			if (cur != nullptr)
			{
				s.push(cur);
				cur = cur->_left;
			}
			else
			{
				pNode top = s.top();
				s.pop();
				cout << "<" << top->_value.first << "----->" << top->_value.second << "> ";
				cur = top->_right;
			}
		}
		cout << endl;
	}
	bool isRBTree()
	{
		pNode root = _header->_parent;
		if (root == nullptr)
		{
			return true;
		}
		if (root->_color == RED)
		{
			cout << "根节点必须是黑色" << endl;
			return false;
		}
		//每条路径上黑色节点的个数必须相同
		//先任意遍历一条路径，统计出一条路径中所有的黑色节点
		//此处遍历最右路径
		pNode cur = root;
		int totalBlackCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
			{
				++totalBlackCount;
			}
			cur = cur->_right;
		}
		int curBlackCount = 0;
		return _isRBTree(root, curBlackCount, totalBlackCount);
	}
	bool _isRBTree(pNode root, int curBlackCount, int totalBlackCount)
	{
		//判断每条路径上黑色节点是否相同
		//当前节点为空时，表示当前路劲已经遍历完
		if (root == nullptr)
		{
			if (curBlackCount != totalBlackCount)
			{
				cout << "每条路径上黑色节点个数不同" << endl;
				return false;
			}
			return true;
		}
		if (root->_color == BLACK)
		{
			++curBlackCount;
		}
		//判断有否存在两个红色节点连续
		pNode parent = root->_parent;
		if (parent && parent->_color == RED && root->_color == RED)
		{
			cout << "两个红色节点连续" << endl;
			return false;
		}
		return _isRBTree(root->_left, curBlackCount, totalBlackCount)
			&& _isRBTree(root->_right, curBlackCount, totalBlackCount);
	}
	
private:
	pNode _header;//头结点
};
template<class K,class V>
class MyMap
{
	struct MapKeyOfVale
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename RBTree<K, pair<K,V>, MapKeyOfVale>::iterator iterator;
	iterator begin()
	{
		return _rb.begin();
	}
	iterator end()
	{
		return _rb.end();
	}
	iterator rbegin()
	{
		return _rb.rbegin();
	}
	V& operator[](const K& key)
	{
		return (*(_rb.insert(make_pair(key, V())).first)).second;
	}
	pair < iterator, bool> insert(const pair<K, V>& data)
	{
		return _rb.insert(data);
	}
private:
	RBTree<K, pair<K, V>,MapKeyOfVale>_rb;
};
template<typename K>
class MySet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;
	pair<iterator,bool> insert(const K& value)
	{
		return _rb.insert(value);
	}
private:
	RBTree<K, K, SetKeyOfValue>_rb;
};
void testMap()
{
	MyMap<int, int>mp;
	mp.insert(make_pair(2, 2));
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(3, 3));
	mp.insert(make_pair(4, 4));
	mp[4] = 5;
	mp[10] = 100;
	MyMap<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "---" << it->second << "  ";
		++it;
	}
	cout << endl;
	MyMap<int, int>::iterator it1 = mp.begin();
	it1 = mp.rbegin();
	while (it1 != mp.end())
	{
		cout << it1->first << "---" << it1->second << "  ";
		--it1;
	}
	cout << endl;
}
void testSet()
{
	MySet<int>st;
	st.insert(1);
	st.insert(2);
	st.insert(3);
	st.insert(4);
}
int main()
{
	testMap();
	//testSet();
	return 0;
}