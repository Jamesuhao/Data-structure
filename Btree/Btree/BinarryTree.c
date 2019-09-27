#include"BinarryTree.h"
#include<assert.h>
#include<malloc.h>
 //通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreate(a, pi);
		//需要访问其右子树时索引++
		(*pi)++;
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreeDestory(BTNode** root)
{
	BTNode* curRoot = *root;
	if (curRoot)
	{
		BinaryTreeDestory(&curRoot->_left);
		BinaryTreeDestory(&curRoot->_right);
		free(curRoot);
		curRoot = NULL;
	}
}
//有效节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root)
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
	else
	{
		return 0;
	}
}
//叶子节点个数
int BinaryTreeLeafSize(BTNode* root) 
{
	if (root == NULL)
	{
		return 0;
	}
	//root为叶子节点
	if (root->_left == NULL || root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
//查找
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}
//遍历

//前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	//递归：
	if (root != NULL)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	else
	{
		printf("# ");
	}
}
//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	//递归：
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	else
	{
		printf("# ");
	}
}
//后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	//递归：
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	else
	{
		printf("# ");
	}
}
void TestBinarryTree()
{   //ABD##E#H##CF##G##
	int i = 0;
	char a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	i = BinaryTreeLeafSize(root);
	printf("%d\n",i);
	i = BinaryTreeSize(root);
	printf("%d\n", i);
}
int main()
{
	TestBinarryTree();
	return 0;
}