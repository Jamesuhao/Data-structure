/*
��Ŀ ������һ�������������������������
ʾ����
���룺[1,nullptr,2,3]
    1
       \
        2
       /
    3
�����[1,3,2]
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
    //�ݹ�ʵ���������
    vector<int>inorderTraversal(TreeNode* root)
    {
        vector<int>vec;
        inOrder(root, vec);
        return vec;
    }
    //�ݹ�ӿڣ���root�ڵ㿪ʼ����LVR�ķ�ʽ����ÿһ���ڵ�
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
    //�ǵݹ�ʵ�ֶ��������������
    /*
    �ǵݹ����������˼�룺
    �Ӹ��ڵ㿪ʼ������ÿ���ڵ㶼��LVR�ķ�ʽ���б����������������Ľڵ���ջ�������ǰ�ڵ�Ϊ�գ���ʼ��ջ��
    ÿ��ջһ��Ԫ�أ��жϸ�Ԫ�ص��������Ƿ���ڣ�������ڣ���������������������������
    ���ѭ����ֱ��ջΪ�ղ��ҵ�ǰ�ڵ�ҲΪ��ʱ������������
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