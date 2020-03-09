#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
//ʹ�ú�������less���Ƚϵ���С�ڹ�ϵ��ʹ�ô���������
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

	//�ǵݹ�-�������
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
				//���ܲ�����ͬ��Ԫ��
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
	//�ݹ�-�������
	void insert_i(const T& val)
	{
		_root = insert_i(_root, val);
	}
	//�ǵݹ�-ɾ������
	void remove(const T& val)
	{
		//�ж��Ƿ�Ϊ����
		if (_root == nullptr)
		{
			return;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//������ɾ���ڵ�
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
		//��ѭ�����������
		//1.curΪ�գ���ɾ���ڵ㲻����
		if (cur == nullptr)
		{
			return;
		}
		//2.break�������ҵ���ɾ���ڵ�
		//���3��ɾ��ǰ���ڵ�(�������1����2)
		if (cur->_left != nullptr && cur->_right != nullptr)
		{
			parent = cur;
			Node* pre = cur->_left;//preѰ��ǰ���ڵ�
			while (pre->_right)
			{
				parent = pre;
				pre = pre->_right;
			}
			cur->_data = pre->_data;
			cur = pre;//��curָ��ǰ���ڵ㣬ת�������1�������2
		}
		//curָ���ɾ���ڵ㣬parentָ�򸸽ڵ㣬ͳһ�������1�����2
		//��������1�������2�У��亢����Ҫô��Ϊnullptr,Ҫô����һ��Ϊ��
		Node* child = cur->_left;//��ָ�����ӣ��������Ϊ�գ���ָ���Һ��ӣ���ô�Һ���ҪôΪ�գ�Ҫô��Ϊ��
		if (child == nullptr)//�����Ҫ�����ڴ�ɾ���ڵ�ĸ��ڵ���ȥ
		{
			child = cur->_right;
		}
		//���������������ڵ�Ϊ�գ�˵����ɾ���ڵ�Ϊ���ڵ㣬��Ҫ���¸��ڵ�
		if (parent == nullptr)
		{
			_root = child;
		}
		//������ڵ㲻Ϊ�գ����жϽ����ӽڵ������ڸ��ڵ���Ǳ�
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
		//ɾ���ڵ�
		delete cur;
		cur = nullptr;
	}
	//�ݹ�-ɾ������
	void remove_r(const T& val)
	{
		_root = remove_r(_root, val);
	}
	//�ǵݹ�-��ѯ����
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
	//�ݹ�-��ѯ����
	bool query_q(const T & val)
	{
		return nullptr != query_q(_root, val);
	}

	//�ݹ�ǰ���������
	void preOrder()
	{
		cout << "[�ݹ�]ǰ�������";
		preOrder(_root);
		cout << endl;
	}
	//�ǵݹ�ǰ���������
	void n_preOrder()
	{
		cout << "[�ǵݹ�]ǰ�������";
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
	//�ݹ������������
	void inOrder()
	{
		cout << "[�ݹ�]���������";
		inOrder(_root);
		cout << endl;
	}
	//�ǵݹ������������
	void n_inOrder()
	{
		cout << "[�ǵݹ�]���������";
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
	//�ݹ�����������
	void postOrder()
	{
		cout << "[�ݹ�]���������";
		postOrder(_root);
		cout << endl;
	}
	//�ǵݹ�����������
	void n_postOrder()
	{
		cout << "[�ǵݹ�]���������";
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
	//�ݹ��������������ж��ٲ㣬�ͽ��ж��ٴεݹ����������Ҫ����һ������
	void levelOrder()
	{
		cout << "[�ݹ�]���������";
		int h = high();
		for (int i = 0; i < h; ++i)
		{
			levelOrder(_root, i);//�ݹ�������Ĳ�����
		}
		cout << endl;
	}
	//�ǵݹ��������������ж��ٲ㣬�ͽ��ж��ٴεݹ����������Ҫ����һ������
	void n_levelOrder()
	{
		cout << "[�ǵݹ�]���������";
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

	//�ݹ������������
	int high()
	{
		return high(_root);
	}
	//�ݹ���������ڵ����
	int number()
	{
		return number(_root);
	}

	//����������Ԫ�ص�ֵ[i,j]
	void findValues(vector<T>& vec, int i, int j)
	{
		findValues(_root, vec, i, j);
		for (const auto& v : vec)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	//�ж�һ�ö������Ƿ���BST��
	bool isBSTree()
	{
		Node* pre = nullptr;
		return isBSTree(_root, pre);
	}
	//�ж���������
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
	//�ݹ�ǰ�������ʵ��
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->_data << " ";//������ǰ�ڵ�V
			preOrder(node->_left);//����L
			preOrder(node->_right);//����R
		}
	}
	//�ݹ����������ʵ��
	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->_left);//L
			cout << node->_data << " ";//V
			inOrder(node->_right);//R
		}
	}
	//�ݹ���������ʵ��
	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->_left);//L
			postOrder(node->_right);//R
			cout << node->_data << " ";//V
		}
	}
	//�ݹ���������ʵ��
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
	//�ݹ�ʵ�������������,����nodeΪ���ڵ�������ĸ߶�
	//�����ظ߶�ֵ
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
	//�ݹ���������ڵ������ʵ��
	//����nodeΪ���ڵ�����Ľڵ�������������
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
	//�ݹ�-�������ʵ��
	Node* insert_i(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			//�ݹ�������ҵ�����val��λ�ã����������ɽڵ�ĵ�ַ
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
	//�ݹ�-��ѯ����ʵ��
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
	//�ݹ�-ɾ������ʵ��
	Node* remove_r(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (node->_data == val)//�ҵ���ɾ���ڵ�
		{
			//���3
			if (node->_left != nullptr && node->_right != nullptr)
			{
				//��ǰ���ڵ�
				Node* pre = node->_left;
				while (pre->_right != nullptr)
				{
					pre = pre->_right;
				}
				//��ǰ���ڵ��ֵ���Ǵ�ɾ���ڵ��ֵ
				node->_data = pre->_data;
				//ͨ���ݹ�ֱ��ɾ��ǰ���ڵ�
				node->_left = remove_r(node->_left, pre->_data);
			}
			//���һ�������2
			else
			{
				if (node->_left != nullptr)
				{
					//ɾ���ڵ��Ժ󣬰ѷǿյ����ӷ��أ�����ʱ�����丸�ڵ�ĵ�ַ��
					Node* left = node->_left;
					delete node;
					node = nullptr;
					return left;
				}
				else if (node->_right != nullptr)
				{
					//ɾ���ڵ��Ժ󣬰ѷǿյ��Һ��ӷ��أ�����ʱ�����丸�ڵ�ĵ�ַ��
					Node* right = node->_right;
					delete node;
					node = nullptr;
					return right;
				}
				else//ɾ������Ҷ�ӽڵ�
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
		return node;//�ѵ�ǰ�ڵ㷵�ظ����ڵ㣬���¸��ڵ���Ӧ�ĵ�ַ��
	}
	//BST��������������[i,j]ʵ��
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
	//�ж�һ�����Ƿ���BST����ʵ��
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
		����ʽ�������Ǿֲ�����BST�������ʣ�����ȫ�ֲ�������
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
	//�ж���������ʵ��
	bool isChildTree(Node* father, Node* child)
	{
		if (father == nullptr && child == nullptr)
		{
			return true;
		}
		if (father == nullptr)//���������еĽڵ㣬��������û��
		{
			return false;
		}
		if (child == nullptr)
		{
			return true;
		}
		//�ж�ֵ����ͬ
		if (child->_data != father->_data)//V
		{
			return false;
		}
		return isChildTree(father->_left, child->_left) && isChildTree(father->_right, child->_right);//L��R
	}
};
//���ڲ����Ƿ�BST��
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
//���ڲ��������ж�����
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