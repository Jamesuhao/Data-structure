/*
题目信息：给定一颗二叉树，判断其是否是一个有效的二叉搜索树
假设一个二叉搜索树具有如下功能：
节点的左子树只包含小于当前节点的数
节点的右子树只包含大于当前节点的数
所有左子树和右子树自身也必须二叉搜索树
示例1：
输入：
	   2
	 /   \
   1	   3
输出：true
示例2：
		5
	  /   \
	1	   4
		 /   \
	   3      6
输出：false
*/
struct TreeNode
{
	int val;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode(int x)
		:val(x)
		, _left(nullptr)
		, _right(nullptr)
	{}
};
class Solution
{
public:
	TreeNode* pre;
	Solution()
		:pre(nullptr)
	{}
	bool isValidBST(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		if(!isValidBST(root->_left));//L
		{
			return false;
		}
		//V  升序的元素序列
		if (pre != nullptr)
		{
			if (pre->val >= root->val)
			{
				return false;
			}
		}
		pre = root;
		return isValidBST(root->_right);//R
	}
};