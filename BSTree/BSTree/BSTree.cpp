/*
����������(BST����Ҳ��Ϊ����������)�����ʣ�
1.������������ڣ���ô��������ֵһ��С�ڸ��ڵ��ֵ
2.������������ڣ���ô��������ֵһ�����ڸ��ڵ��ֵ
3.������������Ҳ��һ�Ŷ���������
*/
#include<iostream>
using namespace std;
template<typename T>
struct BSTNode
{
	BSTNode* _left;
	BSTNode* _right;
	T _value;
	BSTNode(const T& value = T())
		:_left(nullptr)
		,_right(nullptr)
		,_value(value)
	{}
};
template<typename T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;
	//���ҽӿڣ�ʱ�临�Ӷ�(log(N))
	bool find(const T& value)
	{
		//�Ӹ��ڵ㿪ʼ����
		pNode cur = _root;
		while (cur)
		{
			//�����ǰ�ڵ��ֵ������Ҫ���ҵ�ֵ���������ǰ�ڵ��ֵ
			if (cur->_value == value)
			{
				cout << cur << ":" << cur->_value << endl;
				return true;
			}
			//�����ǰ�ڵ��ֵ������Ҫ���ҵ�ֵ������ǰ�ڵ����߼�������
			else if (cur->_value > value)
				cur = cur->_left;
			//�����ǰ�ڵ��ֵС����Ҫ���ҵ�ֵ������ǰ�ڵ���ұ߼�������
			else
				cur = cur->_right;
		}
		//�������Ԫ�ز����ڣ��򷵻�false
		cout << "�����ڸýڵ�" << endl;
		return false;
	}
	//����ӿڣ��ȱ��������������Ҵ�����Ԫ�أ�����Ѵ��ڴ�����Ԫ�أ����ʾ����ʧ�ܡ�
	//�²���Ľڵ�һ�㶼�������Һ���δ���Ľڵ���
	bool insert(const T& value)
	{
		//�������������ڵ�
		if (_root == nullptr)
		{
			_root = new Node(value);
			return true;
		}
		//����������������ýڵ���ڣ��򷵻�fasle������ʧ�ܣ�
		//����ýڵ㲻���ڣ����ҵ��ýڵ�����λ��
		pNode cur = _root;
		pNode parent = _root;//���������ڵ�ĸ��׽ڵ�
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
		//�����½ڵ�
		cur = new Node(value);
		//�븸�׽ڵ����Ƚ�
		//���׽ڵ��ֵ���ڴ�����ڵ��ֵ������ڸ��ڵ�����
		if (parent->_value > value)
			parent->_left = cur;
		//���׽ڵ��ֵС�ڴ�����ڵ��ֵ������ڸ��׽ڵ���ұ�
		else
			parent->_right = cur;
		return true;
	}
	//ɾ���ӿڣ�
	/*
	��ɾ���ڵ�Ϊ��
	1.Ҷ�ӽڵ㣺ֱ���ͷŴ�ɾ���ڵ�Ŀռ䣬�������ڵ��Ӧλ���ÿ�
	2.��Ҷ�ӽڵ㣺(1)�ý��û�����ӡ�(2)�ý��û���Һ���
	*/
	bool erase(const T& value)
	{
		if (_root == nullptr)
			return false;
		pNode cur = _root;
		pNode parent = _root;
		while (cur)
		{
			if (cur->_value == value)
				break;
			else if (cur->_value > value)
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
		//�жϽڵ��Ƿ����
		if (cur == nullptr)
			return false;
		//cur->_left==nullptr��1.curΪҶ�ӽڵ� 2.ֻ���������ķ�Ҷ�ӽڵ�
		if (cur->_left == nullptr)
		{
			//��ɾ���ڵ㲻�Ǹ��ڵ�
			if (cur != _root)
			{
				//���¸��ڵ�ͺ��ӵ�����
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			//ɾ�����Ǹ��ڵ�
			else
				_root = cur->_right;
			delete cur;
			cur = nullptr;
		}
		else if (cur->_right == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			else
				_root = cur->_left;
			delete cur;
			cur = nullptr;
		}
		/*
		��ɾ���ڵ�����Һ��Ӷ����ڣ�
		�����������ҽڵ㣺���������������Ľڵ㣬С�������������нڵ�
		������������ڵ㣺���������������Ľڵ㣬С�������������нڵ�
		ɾ��������
		1.�ҵ������������ҽڵ����������������ڵ�
		2.��ɾ���ڵ����һ���ҵ���ֵ���н���
		3.ɾ����1�����ҵ��Ľڵ�
		*/
		else
		{
			//���Һ��Ӷ���
			//1.�������������ҽڵ�/������������ڵ�
			pNode pNext = cur->_left;
			pNode parent = cur;
			while (pNext->_right)
			{
				parent = pNext;
				pNext = pNext->_right;
			}
			//����
			cur->_value = pNext->_value;
			if (parent->_left == pNext)
				parent->_left = pNext->_left;
			else
				parent->_right = pNext->_left;
			delete pNext;
			pNext = nullptr;
		}
		return true;
	}
	//���������һ����һ�����������У������������
	void _inOrder(pNode root)
	{ 
		if (root)
		{
			_inOrder(root->_left);
			cout << root->_value << " ";
			_inOrder(root->_right);
		}
	}
	void inOrder()
	{
		_inOrder(_root);
		cout << endl;
	}
private:
	pNode _root = nullptr;
};

void testBSTree()
{
	BSTree<int>bst;
	cout << bst.insert(5) << endl;
	cout << bst.insert(3) << endl;
	cout << bst.insert(1) << endl;
	cout << bst.insert(0) << endl;
	cout << bst.insert(2) << endl;
	cout << bst.insert(7) << endl;
	cout << bst.insert(6) << endl;
	cout << bst.insert(8) << endl;
	cout << bst.insert(9) << endl;
	//cout << bst.insert(102) << endl;
	//cout << bst.insert(300) << endl;
	//cout << bst.insert(180) << endl;
	//cout << bst.insert(1) << endl;
	//bst.find(2);
	bst.inOrder();//0,1,2,3,5,6,7,8,9
	bst.erase(0);
	bst.inOrder();//1,2,3,5,6,7,8,9
	bst.erase(3);
	bst.inOrder();//1,2,5,6,7,8,9
	bst.erase(8);
	bst.inOrder();//1,2,5,6,7,9
	bst.erase(5);
	bst.inOrder();
	bst.erase(2);
	bst.inOrder();
	bst.erase(1);
	bst.inOrder();
	bst.erase(6);
	bst.inOrder();
}
int main0()
{
	testBSTree();
	return 0;
}