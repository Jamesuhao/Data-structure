#pragma once
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
vector<int> preorderTraversal(TreeNode* root);//递归前序遍历
vector<int> PreorderTraversal(TreeNode* root);//非递归前序遍历
vector<int>inorderTraversal(TreeNode* root);//递归中序遍历
vector<int>InorderTraversal(TreeNode* root);//非递归中序遍历
vector<int> postorderTraversal(TreeNode* root);//递归后序遍历
vector<int> PostorderTraversal(TreeNode* root);//非递归后序遍历
vector<vector<int>>levelOrder(TreeNode* root);//非递归层序遍历：返回值为二维数组版本
vector<int>LevelOrder(TreeNode* root);//非递归层序遍历：返回值为一维数组版本