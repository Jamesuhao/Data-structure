#include<iostream>
#include<stack>
#include <utility>
using namespace std;
/*
�����ʵ��map,set
*/

//ö�ٽ����ڵ���ɫ
enum CLOLR
{
	BLACK,
	RED
};
//�ڵ�ֻ����value
template<typename V>
struct RBNode
{
	RBNode<V>* _left;
	RBNode<V>* _right;
	RBNode<V>* _parent;
	V _value;
	//��ɫ
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
	//��װ�ڵ㣬ʵ�ֵ������Ĺ��ܣ�������list��������ʵ��
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
	ǰ��++�������������ǰ�ڵ���������Ѿ��������ˣ�
			�жϵ�ǰ���������ڵĽڵ��Ƿ����ҽڵ�
			����У��������ƶ�����ǰ�ڵ�������������ڵ�
			���û�У����ϻ��ݣ��ҵ�һ�����㵱ǰ�ڵ㲻�����ҵ��ڵ���������Ľڵ�
	*/
	self& operator++()
	{
		//��������ҽڵ㣬�ƶ���������������ڵ�
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		//�������ҽڵ㣬���ϻ��ݣ��ҵ�һ�����㵱ǰ�ڵ㲻�����ҵ��ڵ���������Ľڵ�
		else
		{
			pNode parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			//���������_node->_right==parent
			//������û������������_nodeָ��_header
			if (_node->_right != parent)
				_node = parent;
		}
		return *this;
	}
	/*
	ǰ��--��
	��ǰ�ڵ�����Ӵ��ڣ��ߵ������������ҽڵ�
	��ǰ�ڵ�����Ӳ����ڣ����ϻ��ݣ��ҵ�һ�����㵱ǰ�ڵ㲻�����ҵ��ڵ���������Ľڵ�
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
		//����һ���յĺ����
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}
	pair<iterator,bool> insert(const V& value)
	{
		//�������Ĳ���
		if (_header->_parent == nullptr)
		{
			//�������������ڵ�
			pNode root = new Node(value);
			//������ɫ�Ǻ�ɫ
			root->_color = BLACK;
			//���ĸ�����ͷ
			root->_parent = _header;
			//ͷ�ĸ����Ǹ�
			_header->_parent = root;
			//ͷ����������������ڵ�
			_header->_left = root;
			//ͷ���Һ������������ҽڵ�
			_header->_right = root;
			return make_pair(iterator(root), true);
		}
		//��ͷ��ʼ����
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		//ͨ���º��������ȡV��Ӧ��K
		KeyOfValue kov;
		while (cur)
		{
			//���ڲ�ͬ��V����Ҫ��ȡV��Ӧ��K
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
		//�ҵ�����λ�ã������½ڵ㣬���в���
		cur = new Node(value);
		pNode newnode = cur;
		//����½ڵ�С�ڸ��ڵ㣬��������
		if (kov(parent->_value) > kov(cur->_value))
		{
			parent->_left = cur;
		}
		//����½ڵ���ڸ��ڵ㣬������ұ�
		else
		{
			parent->_right = cur;
		}
		//�����½ڵ�ĸ��ڵ�ָ��
		cur->_parent = parent;

		//�����͸���(������ɫ��
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				//uncle������Ϊ��
				if (uncle && uncle->_color == RED)
				{
					//�޸���ɫ
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//�������ϸ���
					cur = gfather;
				}
				else
				{
					//�������˫���ĳ����������Ƚ���һ�ε�����ʹ����ɵ����ĳ���
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//����
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				pNode uncle = gfather->_left;
				//uncle������Ϊ��
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				//uncle�����ڻ���uncle������Ϊ��
				else
				{
					//�ж��Ƿ���˫���ĳ���
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
		//������ɫʼ���Ǻڵ�
		_header->_parent->_color = BLACK;
		//����_header->_left,_header->_right
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
			cout << "���ڵ�����Ǻ�ɫ" << endl;
			return false;
		}
		//ÿ��·���Ϻ�ɫ�ڵ�ĸ���������ͬ
		//���������һ��·����ͳ�Ƴ�һ��·�������еĺ�ɫ�ڵ�
		//�˴���������·��
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
		//�ж�ÿ��·���Ϻ�ɫ�ڵ��Ƿ���ͬ
		//��ǰ�ڵ�Ϊ��ʱ����ʾ��ǰ·���Ѿ�������
		if (root == nullptr)
		{
			if (curBlackCount != totalBlackCount)
			{
				cout << "ÿ��·���Ϻ�ɫ�ڵ������ͬ" << endl;
				return false;
			}
			return true;
		}
		if (root->_color == BLACK)
		{
			++curBlackCount;
		}
		//�ж��з����������ɫ�ڵ�����
		pNode parent = root->_parent;
		if (parent && parent->_color == RED && root->_color == RED)
		{
			cout << "������ɫ�ڵ�����" << endl;
			return false;
		}
		return _isRBTree(root->_left, curBlackCount, totalBlackCount)
			&& _isRBTree(root->_right, curBlackCount, totalBlackCount);
	}
	
private:
	pNode _header;//ͷ���
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