/*
��Ŀ��Ϣ������һ�Ŷ��������ж����Ƿ���һ����Ч�Ķ���������
����һ�������������������¹��ܣ�
�ڵ��������ֻ����С�ڵ�ǰ�ڵ����
�ڵ��������ֻ�������ڵ�ǰ�ڵ����
����������������������Ҳ�������������
ʾ��1��
���룺
	   2
	 /   \
   1	   3
�����true
ʾ��2��
		5
	  /   \
	1	   4
		 /   \
	   3      6
�����false
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
		//V  �����Ԫ������
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