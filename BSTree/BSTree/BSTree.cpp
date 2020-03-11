/*
二叉搜索树(BST树，也称为二叉排序树)的性质：
1.如果左子树存在，那么左子树的值一定小于根节点的值
2.如果右子树存在，那么右子树的值一定大于根节点的值
3.它的左右子树也是一颗二叉搜索数
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
	//查找接口：时间复杂度(log(N))
	bool find(const T& value)
	{
		//从根节点开始查找
		pNode cur = _root;
		while (cur)
		{
			//如果当前节点的值等于所要查找的值，则输出当前节点的值
			if (cur->_value == value)
			{
				cout << cur << ":" << cur->_value << endl;
				return true;
			}
			//如果当前节点的值大于所要查找的值，则向当前节点的左边继续查找
			else if (cur->_value > value)
				cur = cur->_left;
			//如果当前节点的值小于所要查找的值，则向当前节点的右边继续查找
			else
				cur = cur->_right;
		}
		//如果查找元素不存在，则返回false
		cout << "不存在该节点" << endl;
		return false;
	}
	//插入接口：先遍历搜索数，查找待插入元素，如果已存在待插入元素，则表示插入失败。
	//新插入的节点一般都会在左右孩子未满的节点上
	bool insert(const T& value)
	{
		//空树：创建根节点
		if (_root == nullptr)
		{
			_root = new Node(value);
			return true;
		}
		//遍历搜索数：如果该节点存在，则返回fasle，插入失败；
		//如果该节点不存在，则找到该节点插入的位置
		pNode cur = _root;
		pNode parent = _root;//保存待插入节点的父亲节点
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
		//创建新节点
		cur = new Node(value);
		//与父亲节点作比较
		//父亲节点的值大于待插入节点的值，则插在父节点的左边
		if (parent->_value > value)
			parent->_left = cur;
		//父亲节点的值小于待插入节点的值，则插在父亲节点的右边
		else
			parent->_right = cur;
		return true;
	}
	//删除接口：
	/*
	待删除节点为：
	1.叶子节点：直接释放待删除节点的空间，并将父节点对应位置置空
	2.非叶子节点：(1)该结点没有左孩子、(2)该结点没有右孩子
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
		//判断节点是否存在
		if (cur == nullptr)
			return false;
		//cur->_left==nullptr：1.cur为叶子节点 2.只有右子树的非叶子节点
		if (cur->_left == nullptr)
		{
			//待删除节点不是根节点
			if (cur != _root)
			{
				//更新父节点和孩子的链接
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			//删除的是根节点
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
		待删除节点的左右孩子都存在：
		左子树的最右节点：大于所有左子树的节点，小于右子树的所有节点
		右子树的最左节点：大于所有左子树的节点，小于右子树的所有节点
		删除方法：
		1.找到左子树的最右节点或者右子树的最左节点
		2.被删除节点与第一步找到的值进行交换
		3.删除第1步所找到的节点
		*/
		else
		{
			//左右孩子都在
			//1.找左子树的最右节点/右子树的最左节点
			pNode pNext = cur->_left;
			pNode parent = cur;
			while (pNext->_right)
			{
				parent = pNext;
				pNext = pNext->_right;
			}
			//交换
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
	//中序遍历：一定是一个递增的序列，输出该搜索树
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