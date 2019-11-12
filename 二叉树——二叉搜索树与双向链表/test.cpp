/*
��Ŀ����
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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