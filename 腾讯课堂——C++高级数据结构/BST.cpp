#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
//使用函数对象：less，比较的是小于关系，使得代码更加灵活
template<typename T,typename compare=less<T>>
class BSTree
{
public:
	BSTree()
		:_root(nullptr)
	{}
	~BSTree()
	{

	}

	//非递归-插入操作
	void insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_data==val)
			{
				//不能插入相同的元素
				return;
			}
			else if (_comp(cur->_data, val))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				parent = cur;
				cur = cur->_left;
			}
		}
		if (_comp(val,parent->_data))
		{
			parent->_left = new Node(val);
		}
		else
		{
			parent->_right = new Node(val);
		}
	}
	//递归-插入操作
	void insert_i(const T& val)
	{
		_root = insert_i(_root, val);
	}
	//非递归-删除操作
	void remove(const T& val)
	{
		//判断是否为空树
		if (_root == nullptr)
		{
			return;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//搜索待删除节点
		while (cur)
		{
			if (cur->_data==val)
			{
				break;
			}
			else if (_comp(cur->_data, val))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				parent = cur;
				cur = cur->_left;
			}
		}
		//出循环有两种情况
		//1.cur为空，待删除节点不存在
		if (cur == nullptr)
		{
			return;
		}
		//2.break出来，找到待删除节点
		//情况3：删除前驱节点(归结成情况1或者2)
		if (cur->_left != nullptr && cur->_right != nullptr)
		{
			parent = cur;
			Node* pre = cur->_left;//pre寻找前驱节点
			while (pre->_right)
			{
				parent = pre;
				pre = pre->_right;
			}
			cur->_data = pre->_data;
			cur = pre;//让cur指向前驱节点，转换成情况1或者情况2
		}
		//cur指向待删除节点，parent指向父节点，统一处理情况1和情况2
		//巧妙处理：情况1或者情况2中，其孩子域要么都为nullptr,要么其中一个为空
		Node* child = cur->_left;//先指向左孩子，如果左孩子为空，则指向右孩子，那么右孩子要么为空，要么不为空
		if (child == nullptr)//最后都是要连接在待删除节点的父节点上去
		{
			child = cur->_right;
		}
		//特殊情况：如果父节点为空，说明待删除节点为根节点，需要更新根节点
		if (parent == nullptr)
		{
			_root = child;
		}
		//如果父节点不为空，则判断将孩子节点连接在父节点的那边
		else
		{
			if (parent->_left == cur)
			{
				parent->_left = child;
			}
			else
			{
				parent->_right = child;
			}
		}
		//删除节点
		delete cur;
		cur = nullptr;
	}
	//递归-删除操作
	void remove_r(const T& val)
	{
		_root = remove_r(_root, val);
	}
	//非递归-查询操作
	bool query(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data == val)
			{
				return true;
			}
			else if (_comp(cur->_data, val))
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		return false;
	}
	//递归-查询操作
	bool query_q(const T & val)
	{
		return nullptr != query_q(_root, val);
	}

	//递归前序遍历操作
	void preOrder()
	{
		cout << "[递归]前序遍历：";
		preOrder(_root);
		cout << endl;
	}
	//非递归前序遍历操作
	void n_preOrder()
	{
		cout << "[非递归]前序遍历：";
		if (_root == nullptr)
		{
			return;
		}
		stack<Node*>s;
		s.push(_root);
		while (!s.empty())
		{
			Node* top = s.top();
			s.pop();
			cout << top->_data << " ";
			if (top->_right != nullptr)
			{
				s.push(top->_right);
			}
			if (top->_left != nullptr)
			{
				s.push(top->_left);
			}
		}
		cout << endl;
	}
	//递归中序遍历操作
	void inOrder()
	{
		cout << "[递归]中序遍历：";
		inOrder(_root);
		cout << endl;
	}
	//非递归中序遍历操作
	void n_inOrder()
	{
		cout << "[非递归]中序遍历：";
		if (_root == nullptr)
		{
			return;
		}
		stack<Node*>s;
		Node* cur = _root;
		while (!s.empty() || cur != nullptr)
		{
			if (cur != nullptr)
			{
				s.push(cur);
				cur = cur->_left;
			}
			else
			{
				Node* top = s.top();
				s.pop();
				cout << top->_data << " ";
				cur = top->_right;
			}
		}
		cout << endl;
	}
	//递归后序遍历操作
	void postOrder()
	{
		cout << "[递归]后序遍历：";
		postOrder(_root);
		cout << endl;
	}
	//非递归后序遍历操作
	void n_postOrder()
	{
		cout << "[非递归]后序遍历：";
		if (_root == nullptr)
		{
			return;
		}
		stack<Node*>s1;
		stack<Node*>s2;
		s1.push(_root);
		while (!s1.empty())
		{
			Node* top = s1.top();//V
			s1.pop();
			s2.push(top);
			if (top->_left != nullptr)//L
			{
				s1.push(top->_left);
			}
			if (top->_right != nullptr)//R
			{
				s1.push(top->_right);
			}
		}
		while (!s2.empty())
		{
			cout << s2.top()->_data << " ";
			s2.pop();
		}
		cout << endl;
	}
	//递归层序遍历操作。有多少层，就进行多少次递归遍历，所以要控制一个层数
	void levelOrder()
	{
		cout << "[递归]层序遍历：";
		int h = high();
		for (int i = 0; i < h; ++i)
		{
			levelOrder(_root, i);//递归调用树的层数次
		}
		cout << endl;
	}
	//非递归层序遍历操作。有多少层，就进行多少次递归遍历，所以要控制一个层数
	void n_levelOrder()
	{
		cout << "[非递归]层序遍历：";
		if (_root == nullptr)
		{
			return;
		}
		queue<Node*>que;
		que.push(_root);
		while (!que.empty())
		{
			Node* front = que.front();
			que.pop();
			cout << front->_data << " ";
			if (front->_left != nullptr)
			{
				que.push(front->_left);
			}
			if (front->_right != nullptr)
			{
				que.push(front->_right);
			}
		}
		cout << endl;
	}

	//递归求二叉树层数
	int high()
	{
		return high(_root);
	}
	//递归求二叉树节点个数
	int number()
	{
		return number(_root);
	}

	//求满足区间元素的值[i,j]
	void findValues(vector<T>& vec, int i, int j)
	{
		findValues(_root, vec, i, j);
		for (const auto& v : vec)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	//判断一棵二叉树是否是BST树
	bool isBSTree()
	{
		Node* pre = nullptr;
		return isBSTree(_root, pre);
	}
	//判断子树问题
	bool isChildTree(BSTree<T, compare>& child)
	{
		if (child._root == nullptr)
		{
			return true;
		}
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_data == child._root->_data)
			{
				break;
			}
			else if (_comp(cur->_data, child._root->_data))
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		if (cur == nullptr)
		{
			return false;
		}
		return isChildTree(cur, child._root);
	}

public:
	struct Node
	{
		Node(T data = T())
			:_data(data)
			,_left(nullptr)
			,_right(nullptr)
		{}
		T _data;
		Node* _left;
		Node* _right;
	};
	Node* _root;
	compare _comp;
	//递归前序遍历的实现
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->_data << " ";//操作当前节点V
			preOrder(node->_left);//访问L
			preOrder(node->_right);//访问R
		}
	}
	//递归中序遍历的实现
	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->_left);//L
			cout << node->_data << " ";//V
			inOrder(node->_right);//R
		}
	}
	//递归后序遍历的实现
	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->_left);//L
			postOrder(node->_right);//R
			cout << node->_data << " ";//V
		}
	}
	//递归层序遍历的实现
	void levelOrder(Node* node, int i)
	{
		if (node == nullptr)
		{
			return;
		}
		if (i == 0)
		{
			cout << node->_data << " ";
			return;
		}
		levelOrder(node->_left, i - 1);
		levelOrder(node->_right, i - 1);
	}
	//递归实现求二叉树层数,求以node为根节点的子树的高度
	//并返回高度值
	int high(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = high(node->_left);
		int right = high(node->_right);
		return left > right ? left + 1 : right + 1;
	}
	//递归求二叉树节点个数的实现
	//求以node为根节点的树的节点总数，并返回
	int number(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = number(node->_left);
		int right = number(node->_right);
		return left + right + 1;
	}
	//递归-插入操作实现
	Node* insert_i(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			//递归结束，找到插入val的位置，返回新生成节点的地址
			return new Node(val);
		}
		if (node->_data == val)
		{
			return node;
		}
		else if (_comp(node->_data, val))
		{
			node->_right = insert_i(node->_right, val);
		}
		else
		{
			node->_left = insert_i(node->_left, val);
		}
		return node;
	}	
	//递归-查询操作实现
	Node* query_q(Node * node, const T & val)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (node->_data == val)
		{
			return node;
		}
		else if (_comp(node->_data, val))
		{
			return query_q(node->_right, val);
		}
		else
		{
			return query_q(node->_left, val);
		}
	}
	//递归-删除操作实现
	Node* remove_r(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (node->_data == val)//找到待删除节点
		{
			//情况3
			if (node->_left != nullptr && node->_right != nullptr)
			{
				//找前驱节点
				Node* pre = node->_left;
				while (pre->_right != nullptr)
				{
					pre = pre->_right;
				}
				//用前驱节点的值覆盖待删除节点的值
				node->_data = pre->_data;
				//通过递归直接删除前驱节点
				node->_left = remove_r(node->_left, pre->_data);
			}
			//情况一或者情况2
			else
			{
				if (node->_left != nullptr)
				{
					//删除节点以后，把非空的左孩子返回，回溯时更新其父节点的地址域
					Node* left = node->_left;
					delete node;
					node = nullptr;
					return left;
				}
				else if (node->_right != nullptr)
				{
					//删除节点以后，把非空的右孩子返回，回溯时更新其父节点的地址域
					Node* right = node->_right;
					delete node;
					node = nullptr;
					return right;
				}
				else//删除的是叶子节点
				{
					delete node;
					node = nullptr;
					return nullptr;
				}
			}
		}
		else if (_comp(node->_data, val))
		{
			node->_right = remove_r(node->_right, val);
		}
		else
		{
			node->_left = remove_r(node->_left, val);
		}
		return node;//把当前节点返回给父节点，更新父节点相应的地址域
	}
	//BST树区间搜索问题[i,j]实现
	void findValues(Node* node, vector<T>& vec, int i, int j)
	{
		if (node != nullptr)
		{
			if (node->_data > i)
			{
				findValues(node->_left, vec, i, j);
			}
			if (node->_data >= i && node->_data <= j)
			{
				vec.push_back(node->_data);
			}
			if (node->_data < j)
			{
				findValues(node->_right, vec, i, j);
			}
		}
	}
	//判断一棵树是否是BST树的实现
	bool isBSTree(Node* node,Node* &pre)
	{
		if (node == nullptr)
		{
			return true;
		}
		if (!isBSTree(node->_left, pre))
		{
			return false;
		}
		if (pre != nullptr)
		{
			if (_comp(node->_data, pre->_data))
			{
				return false;
			}
		}
		pre = node;
		return isBSTree(node->_right, pre);
		/*
		错误方式：仅考虑局部满足BST树的性质，但是全局并不满足
		if (node->_left != nullptr && _comp(node->_data, node->_left->_data))
		{
			return false;
		}
		if (node->_right != nullptr && _comp(node->_right->_data, node->_data))
		{
			return false;
		}
		if (!isBSTree(node->_left))
		{
			return false;
		}
		return isBSTree(node->_right);
		*/
	}
	//判断子树问题实现
	bool isChildTree(Node* father, Node* child)
	{
		if (father == nullptr && child == nullptr)
		{
			return true;
		}
		if (father == nullptr)//子树里面有的节点，主树里面没有
		{
			return false;
		}
		if (child == nullptr)
		{
			return true;
		}
		//判断值不相同
		if (child->_data != father->_data)//V
		{
			return false;
		}
		return isChildTree(father->_left, child->_left) && isChildTree(father->_right, child->_right);//L、R
	}
};
//用于测试是否BST树
void test1()
{
	using Node = BSTree<int>::Node;
	BSTree<int>bst;
	bst._root = new Node(5);
	Node* node1 = new Node(1);
	Node* node2 = new Node(4);
	Node* node3 = new Node(3);
	Node* node4 = new Node(6);
	bst._root->_left = node1;
	bst._root->_right = node2;
	node2->_left = node3;
	node2->_right = node4;
	cout << bst.isBSTree() << endl;
}
//用于测试子树判断问题
void test2()
{
	int arr[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	BSTree<int>bst;
	for (int v : arr)
	{
		bst.insert(v);
	}
	using Node = BSTree<int>::Node;
	BSTree<int>bst1;
	bst1._root = new Node(67);
	Node* node1 = new Node(62);
	Node* node2 = new Node(69);
	Node* node3 = new Node(60);
	bst1._root->_left = node1;
	bst1._root->_right = node2;
	//node1->_left = node3;
	cout << bst.isChildTree(bst1) << endl;
}
int main()
{
	//bst.test1();
	test2();
	//int arr[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	//BSTree<int> bst;
	//vector<int>vec;
	//for (const auto& v : arr)
	//{
	//	//bst.insert(v);
	//	bst.insert_i(v);
	//}
	//bst.preOrder();
	//bst.inOrder();
	//bst.postOrder();
	//bst.levelOrder();
	//bst.n_preOrder();
	//bst.n_inOrder();
	//bst.n_postOrder();
	//bst.n_levelOrder();
	//bst.findValues(vec, 34, 67);
	//cout << bst.high() << endl;
	//cout << bst.number() << endl;
	//cout << bst.query_q(12) << endl;
	//bst.insert_i(12);
	//cout << bst.query_q(12) << endl;
	//bst.remove_r(12);
	//bst.remove_r(34);
	//bst.remove_r(58);
	//bst.inOrder();
	//bst.insert(12);
	//cout << bst.query(12) << endl;
	//bst.remove(12);
	//bst.remove(34);
	//bst.remove(58);
	//cout << bst.query(12) << endl;

	return 0;
}