/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(nullptr)
		, right(nullptr)
	{ }
};
void _Convert(TreeNode* root, TreeNode** prev)
{
	if (root == nullptr)
		return;
	_Convert(root->left, prev);
	root->left = *prev;
	if (*prev)
		(*prev)->right = root;
	*prev = root;
	_Convert(root->right, prev);
}
TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* prev = nullptr;
	_Convert(pRootOfTree, &prev);
	TreeNode* pListHead = prev;
	while (prev != nullptr && prev->left != nullptr)
	{
		pListHead = prev->left;
		prev = prev->left;
	}
	return pListHead;
}