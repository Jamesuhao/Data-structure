#include"BTree.h"
#include<stack>
#include<queue>
//�ݹ�ǰ�����
void PreOrder(vector<int>& vec, TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	vec.push_back(root->val);
	PreOrder(vec, root->left);
	PreOrder(vec, root->right);
}
vector<int> preorderTraversal(TreeNode* root)
{
	vector<int>vec;
	PreOrder(vec, root);
	return vec;
}
//�ǵݹ�ǰ�����
vector<int> PreorderTraversal(TreeNode* root)
{
	stack<TreeNode*>s;
	vector<int>vec;
	s.push(root);
	TreeNode* cur = root;
	while (cur || !s.empty())
	{
		while (cur)
		{
			vec.push_back(cur->val);
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* top = s.top();
		s.pop();
		cur = top->right;
	}
	return vec;
}
//�ݹ��������
void Inorder(vector<int>& vec, TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	Inorder(vec, root->left);
	vec.push_back(root->val);
	Inorder(vec, root->right);
}
vector<int>inorderTraversal(TreeNode* root)
{
	vector<int>vec;
	Inorder(vec, root);
	return vec;
}
//�ǵݹ��������
vector<int>InorderTraversal(TreeNode* root)
{
	stack<TreeNode*>s;
	vector<int>vec;
	if (root == nullptr)
	{
		return vec;
	}
	TreeNode* cur = root;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* top = s.top();
		vec.push_back(top->val);
		s.pop();
		cur = top->right;
	}
}
//�ݹ�������
void postorder(vector<int>& vec, TreeNode* root)
{
	if (root == nullptr)
		return;
	postorder(vec, root->left);
	postorder(vec, root->right);
	vec.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int>vec;
	postorder(vec, root);
	return vec;
}
//�ǵݹ�������
vector<int> PostorderTraversal(TreeNode* root)
{
	vector<int>vec;
	stack<TreeNode*>s;
	TreeNode* cur = root;
	TreeNode* prev = nullptr;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* top = s.top();
		if (top->right == nullptr || top->right == prev)
		{
			vec.push_back(top->val);
			s.pop();
			prev = top;
		}
		else
		{
			cur = top->right;
		}
	}
}
//�ǵݹ�������������ֵΪ��ά����汾
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>>res;
	vector<int>vec;
	queue<TreeNode*>que;
	if (root)
	{
		que.push(root);
		que.push(nullptr);
	}
	while (!que.empty())
	{
		while (que.front())
		{
			TreeNode* front = que.front();
			if (front->left)
				que.push(front->left);
			if (front->right)
				que.push(front->right);
			vec.push_back(front->val);
			que.pop();
		}
		que.pop();
		if (!vec.empty())
		{
			res.push_back(vec);
			que.push(nullptr);
			vec.clear();
		}
	}
	return res;
}
//�ǵݹ�������������ֵΪһά����汾
vector<int>LevelOrder(TreeNode* root)
{
	vector<int>vec;
	queue<TreeNode*>que;
	if (root)
		que.push(root);
	while (!que.empty())
	{
		TreeNode* front = que.front();
		vec.push_back(front->val);
		que.pop();
		if (front->left)
			que.push(front->left);
		if (front->right)
			que.push(front->right);
	}
	return vec;
}