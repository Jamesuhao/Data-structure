/*
红黑树性质：
1.根节点是黑色的。
2.如果一个节点是红色的，则它的两个孩子节点是黑色的。--->红色节点是不连续的
3. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均包含相同数目的黑色结点
*/
#include<iostream>
#include<stack>
#include <utility>
using namespace std;
//枚举建立节点颜色
enum CLOLR
{
	BLACK,
	RED
};
template<typename K,typename V>
struct RBNode
{
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;
	RBNode<K, V>* _parent;
	pair<K, V>_value;
	//颜色
	CLOLR _color;
	RBNode(const pair<K,V>&value=pair<K,V>())
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_value(value)
		,_color(RED)
	{}
};
template<typename K,typename V>
class RBTree
{
public:
	typedef RBNode<K, V>Node;
	typedef Node* pNode;
	RBTree()
	{
		//构建一个空的红黑树
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}
	bool insert(const pair<K, V>& value)
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
			return true;
		}
		//从头开始搜索
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		while (cur)
		{
			//按照key值确定位置,key不能重复
			if (cur->_value.first == value.first)
			{
				return false;
			}
			else if (cur->_value.first > value.first)
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
		//如果新节点小于父节点，则插在左边
		if (parent->_value.first > cur->_value.first)
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
						swap(cur,parent);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		//根的颜色始终是黑的
		_header->_color = BLACK;
		//更新_header->_left,_header->_right
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
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
			subL->_parent = nullptr;
			_header->_parent = subL;
		}
		parent->_parent = subL;
	}
	void RotateL(pNode parent)
	{
		if(parent==nullptr)
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
			subR->_parent = nullptr;

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
				cout << "<"<<top->_value.first <<"----->"<<top->_value.second<< "> ";
				cur = top->_right;
			}
		}
		cout << endl;
	}
private:
	pNode _header;//头结点
};
void test()
{
	RBTree<int, int> rbt;
	rbt.insert(make_pair(1, 1));
	rbt.insert(make_pair(10, 1));
	rbt.insert(make_pair(-1, 1));
	rbt.insert(make_pair(-2, 1));
	rbt.insert(make_pair(100, 1));
	rbt.insert(make_pair(19, 1));
	rbt.insert(make_pair(21, 1));
	rbt.inOrder();
}
int main()
{
	test();
	return 0;
}
