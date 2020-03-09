/*
题目信息：
二叉搜索树中的两个节点被错误地交换，请在不改变其结构的情况下，恢复这棵树。
示例 1:
输入: [1, 3, null, null, 2]
        1
      /
    3
      \
        2
输出: [3, 1, null, null, 2]
        3
       /
     1
        \
         2
示例 2:
输入: [3, 1, 4, null, null, 2]
          3
        /  \
      1     4
    /
  2
输出: [2, 1, 4, null, null, 3]
         2
       /  \
     1     4
    /
  3
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* pre;
    TreeNode* node1;
    TreeNode* node2;
    bool flag;
    Solution()
        :pre(nullptr)
        , node1(nullptr)
        , node2(nullptr)
        , flag(false)
    { }
    void recoverTree(TreeNode* root)
    {
        inOrder(root);
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
    }
    void inOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left);//L
        if (pre != nullptr)
        {
            if (node1 == nullptr && pre->val > root->val)
            {
                node1 = pre;
            }
            if (!flag && node1 != nullptr && root->val > node1->val)
            {
                flag = true;
                node2 = pre;
            }
            if (!flag)
            {
                node2 = root;
            }
        }
        pre = root;
        inOrder(root->right);
    }
};