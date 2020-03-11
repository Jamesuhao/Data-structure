/*
#include<iostream>
#include<assert.h>
#include<stack>
#include<time.h>
using namespace std;
template<typename T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _value;
	//ƽ������
	int _bf;

	AVLNode(const T& value = T())
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_value(value)
		,_bf(0)
	{}
};
template<typename T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;
	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;
		//1.
		subL->_right = parent;
		//2.
		parent->_left = subLR;
		//3.
		if(subLR)
			subLR->_parent = parent;

		//subL<--------->parent->_parent
		//4,5
		pNode gParent = parent->_parent;
		if (parent != _root)
		{
			subL->_parent = gParent;
			if (gParent->_left == parent)
				gParent->_left = subL;
			else
				gParent->_right = subL;
		}
		else
		{
			//���¸��ڵ�
			_root = subL;
			subL->_parent = nullptr;
		}
		//6.
		parent->_parent = subL;

		//����ƽ������
		subL->_bf = parent->_bf = 0;
	}
	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;
		//1.
		subR->_left = parent;
		//2.
		parent->_right = subRL;
		//3.
		if (subRL)
			subRL->_parent = parent;
		//4,5
		//subR<----->parent->_parent
		pNode gParent = parent->_parent;
		if (parent != _root)
		{
			subR->_parent = gParent;
			if (gParent->_left == parent)
				gParent->_left = subR;
			else
				gParent->_right = subR;
		}
		else
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		//6.
		parent->_parent = subR;

		//����ƽ�����ӵ�ֵ
		subR->_bf = parent->_bf = 0;
	}
	bool insert(const T& value)
	{
		//�Ƿ�Ϊ����
		if (_root == nullptr)
		{
			_root = new Node(value);
			return false;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_value == value)
				return false;
			else if (cur->_value > value)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(value);
		if (parent->_value > value)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;
		//����ƽ�����ӣ��п�����Ҫ����
		while (parent)
		{
			//����ƽ������
			//�����������ߣ���ߵĸ߶�����
			if (parent->_left == cur)
				--parent->_bf;
			//����������ұߣ��ұߵĸ߶�����
			else
				++parent->_bf;
			if (parent->_bf == 0)
				break;
			else if (abs(parent->_bf) == 1)
			{
				//�������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//��ת
				//�ұ߸ߣ���Ҫ����
				if (parent->_bf == 2 && cur->_bf == 1)
					RotateL(parent);
				//��߸ߣ���Ҫ����
				else if (parent->_bf == -2 && cur->_bf == -1)
					RotateR(parent);
				//�������
				//�ұߵ���߸�
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					pNode subR = parent->_right;
					pNode subRL = subR->_left;
					int bf = subRL->_bf;
					//����˫��
					RotateR(cur);
					RotateL(parent);
					//����ƽ������
					if (bf == 1)
					{
						//�½ڵ����ұ�
						parent->_bf = -1;
						subR->_bf = 0;
					}
					else if (bf == -1)
					{
						//�½ڵ������
						parent->_bf = 0;
						subR->_bf = 1;
					}
				}
				//��ߵ��ұ߸�
				else
				{
					pNode subL = parent->_left;
					pNode subLR = subL->_right;
					int bf = subLR->_bf;
					//����˫��
					RotateL(cur);
					RotateR(parent);
					//����ƽ������
					if (bf == 1)
					{
						//��subLR���ұ߲�����һ���ڵ�
						parent->_bf = 0;
						subL->_bf = -1;
					}
					else if (bf == -1)
					{
						//��sublr���ұ߲�����һ���ڵ�
						parent->_bf = 1;
						subL->_bf = 0;
					}
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
	void inOrder()
	{
		cout << "[�ǵݹ�]���������";
		if (_root == nullptr)
		{
			return;
		}
		pNode cur = _root;
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
				cout << top->_value << " ";
				cur = top->_right;
			}
		}
		cout << endl;
	}
	int high(pNode root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = high(root->_left);
		int right = high(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	bool isAVLTree()
	{
		return _isAVLTree(_root);
	}

private:
	pNode _root = nullptr;
	bool _isAVLTree(pNode root)
	{
		//1.ƽ�����Ӿ���ֵС��2
		//2.ƽ�����Ӻ����������ĸ߶Ȳ�Ҫһ��
		if (root == nullptr)
		{
			return true;
		}
		int left = high(root->_left);
		int right = high(root->_right);
		if (right - left != root->_bf)
		{
			cout << "�ڵ㣺" << root->_value << "ƽ�������쳣" << endl;
			return false;
		}
		return abs(root->_bf) < 2 && _isAVLTree(root->_left) && _isAVLTree(root->_right);
	}
};
void test()
{
	AVLTree<int>* avl = new AVLTree<int>;
	int arr[] = { 16,3,7,11,9,26,18,14,15 };
	int arr2[] = { 4,2,6,1,3,5,15,7,16,14 };
	for (const auto& v : arr2)
	{
		avl->insert(v);
	}
	for (const auto& v : arr2)
	{
		cout << v << " ";
	}
	cout << endl;
	avl->inOrder();
	cout << avl->isAVLTree() << endl;
}
void test2()
{
	srand(time(nullptr));
	int n;
	cin >> n;
	AVLTree<int>* avl = new AVLTree<int>;
	for (int i = 0; i < n; ++i)
	{
		avl->insert(rand()%100);
	}
	avl->inOrder();
	cout << avl->isAVLTree() << endl;
}
int main1()
{
	test2();
	return 0;
}
*/