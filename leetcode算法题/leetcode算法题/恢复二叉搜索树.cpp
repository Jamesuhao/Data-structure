/*
��Ŀ��Ϣ��
�����������е������ڵ㱻����ؽ��������ڲ��ı���ṹ������£��ָ��������
ʾ�� 1:
����: [1, 3, null, null, 2]
        1
      /
    3
      \
        2
���: [3, 1, null, null, 2]
        3
       /
     1
        \
         2
ʾ�� 2:
����: [3, 1, 4, null, null, 2]
          3
        /  \
      1     4
    /
  2
���: [2, 1, 4, null, null, 3]
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