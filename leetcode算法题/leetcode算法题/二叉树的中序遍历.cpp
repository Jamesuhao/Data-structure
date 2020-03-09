/*
题目 ：给定一个二叉树，返回它的中序遍历
示例：
输入：[1,nullptr,2,3]
    1
       \
        2
       /
    3
输出：[1,3,2]
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode(int x)
        :val(x)
        , _left(nullptr)
        , _right(nullptr)
    { }
};
class Solution
{
public:
    //递归实现中序遍历
    vector<int>inorderTraversal(TreeNode* root)
    {
        vector<int>vec;
        inOrder(root, vec);
        return vec;
    }
    //递归接口，从root节点开始，以LVR的方式遍历每一个节点
    void inOrder(TreeNode* root, vector<int>& vec)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->_left, vec);//L
        vec.push_back(root->val);//V
        inOrder(root->_right, vec);//R
    }
    //非递归实现二叉树的中序遍历
    /*
    非递归中序遍历的思想：
    从根节点开始遍历，每个节点都以LVR的方式进行遍历，并将遍历到的节点入栈，如果当前节点为空，则开始出栈。
    每出栈一个元素，判断该元素的右子树是否存在，如果存在，继续遍历该右子树的左子树；
    如此循环，直至栈为空并且当前节点也为空时，遍历结束。
    */
    vector<int>inorderTraversal(TreeNode* root)
    {
        vector<int>vec;
        stack<TreeNode*>s;
        TreeNode* cur = root;
        while (!s.empty() || cur != nullptr)
        {
            if (cur != nullptr)//L
            {
                s.push(cur);
                cur = cur->_left;
            }
            else
            {
                TreeNode* top = s.top();//V
                s.pop();
                vec.push_back(top->val);
                cur = top->_right;//R
            }
        }
        return vec;
    }
};