#pragma once
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
vector<int> preorderTraversal(TreeNode* root);//�ݹ�ǰ�����
vector<int> PreorderTraversal(TreeNode* root);//�ǵݹ�ǰ�����
vector<int>inorderTraversal(TreeNode* root);//�ݹ��������
vector<int>InorderTraversal(TreeNode* root);//�ǵݹ��������
vector<int> postorderTraversal(TreeNode* root);//�ݹ�������
vector<int> PostorderTraversal(TreeNode* root);//�ǵݹ�������
vector<vector<int>>levelOrder(TreeNode* root);//�ǵݹ�������������ֵΪ��ά����汾
vector<int>LevelOrder(TreeNode* root);//�ǵݹ�������������ֵΪһά����汾