/*
��������ʣ�
1.���ڵ��Ǻ�ɫ�ġ�
2.���һ���ڵ��Ǻ�ɫ�ģ��������������ӽڵ��Ǻ�ɫ�ġ�--->��ɫ�ڵ��ǲ�������
3. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ���������ͬ��Ŀ�ĺ�ɫ���
*/
#include<iostream>
#include<stack>
#include <utility>
using namespace std;
//ö�ٽ����ڵ���ɫ
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
	//��ɫ
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
		//����һ���յĺ����
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}
	bool insert(const pair<K, V>& value)
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
			return true;
		}
		//��ͷ��ʼ����
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		while (cur)
		{
			//����keyֵȷ��λ��,key�����ظ�
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
		//�ҵ�����λ�ã������½ڵ㣬���в���
		cur = new Node(value);
		//����½ڵ�С�ڸ��ڵ㣬��������
		if (parent->_value.first > cur->_value.first)
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
						swap(cur,parent);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		//������ɫʼ���Ǻڵ�
		_header->_color = BLACK;
		//����_header->_left,_header->_right
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
	pNode _header;//ͷ���
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
