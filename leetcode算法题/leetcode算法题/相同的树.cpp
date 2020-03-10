/*
题目信息：
给定两个二叉树，编写一个函数来检验它们是否相同。如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1:
输入:   1         1
          / \       / \
         2   3     2   3
        [1,2,3],   [1,2,3]
输出: true
示例 2:
输入:   1         1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:
输入:    1         1
          / \       / \
         2   1     1   2
        [1,2,1],   [1,1,2]
输出: false
*/
struct TreeNode
{
    int _val;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode(int value = 0)
        :_val(value)
        , _left(nullptr)
        , _right(nullptr)
    {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr)
        {
            return false;
        }
        if (q == nullptr)
        {
            return false;
        }
        if (p->_val != q->_val)
        {
            return false;
        }
        return isSameTree(p->_left, q->_left) && isSameTree(p->_right, q->_right);
    }
};







