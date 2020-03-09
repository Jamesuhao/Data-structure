#include<iostream>
#include<vector>
#define N 5000
using namespace std;
typedef struct TreeNode
{
    int _val;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode(int value = 0)
        :_val(value)
        , _left(nullptr)
        , _right(nullptr)
    {}
}Node;
class Solution
{
public:
    bool isSameTree(TreeNode* father, TreeNode* child)
    {
        if (father == nullptr && child == nullptr)
        {
            return true;
        }
        if (father == nullptr)
        {
            return false;
        }
        if (child == nullptr)
        {
            return false;
        }
        if (father->_val != child->_val)
        {
            return false;
        }
        return isSameTree(father->_left, child->_left) && isSameTree(father->_right, child->_right);
    }
    bool isSubtree(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == nullptr)
        {
            return false;
        }
        return isSameTree(t1, t2) || isSubtree(t1->_left, t2) || isSubtree(t1->_right, t2);
    }
};