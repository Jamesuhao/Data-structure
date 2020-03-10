/*
��Ŀ��Ϣ��
������������������дһ�����������������Ƿ���ͬ������������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
ʾ�� 1:
����:   1         1
          / \       / \
         2   3     2   3
        [1,2,3],   [1,2,3]
���: true
ʾ�� 2:
����:   1         1
          /           \
         2             2

        [1,2],     [1,null,2]

���: false
ʾ�� 3:
����:    1         1
          / \       / \
         2   1     1   2
        [1,2,1],   [1,1,2]
���: false
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







