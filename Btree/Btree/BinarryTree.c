//#include"BinarryTree.h"
#include"Stack.h"
#include"QueueNode.h"
#include<assert.h>
#include<malloc.h>

//通过前序遍历数组"ABD##E#H##CF##G##"构建二叉树 
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
 //通过中序遍历的数组"#D#B#E#H#A#F#C#G#"构建二叉树 
//BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
//{
//	if (a[*pi] != '#')
//	{
//		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//		root->_left = BinaryTreeCreate(a, pi);
//		root->_data = a[*pi];
//		++(*pi);
//		root->_right = BinaryTreeCreate(a, pi);
//		//++(*pi);
//		return root;
//	}
//	else
//	{
//		return NULL;
//	}
//}
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
	if (root->_left == NULL && root->_right == NULL)
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
	//else
	//{
	//	printf("# ");
	//}
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
	//else
	//{
	//	printf("# ");
	//}
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
	//else
	//{
	//	printf("# ");
	//}
}
//层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	//根元素入队
//	if (root)
//		QueuePush(&q,root);
//	while (QueueEmpty(&q) == 0)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//遍历
//		printf("%c ", front->_data);
//		//孩子入队
//		if (front->_left)
//			QueuePush(&q, front->_left);
//		if (front->_right)
//			QueuePush(&q, front->_right);
//	}
//	printf("\n");
//}
//// 判断二叉树是否是完全二叉树 
//int BinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//	while (QueueEmpty(&q) == 0)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//判断是否为空
//		if (front)
//		{
//			QueuePush(&q, front->_left);
//			QueuePush(&q, front->_right);
//		}
//		else
//			break;
//	}
//	while (QueueEmpty(&q) == 0)
//	{
//		BTNode* front = QueueFront(&q);
//		//判断是否为空，非空，说明不连续
//		if (front)
//		{
//			QueueDestory(&q);
//			return -1;
//		}
//		QueuePop(&q);
//	}
//	return 1;
//}
//非递归前序遍历
void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* top;
	BTNode* cur = root;
	Stack st;
	StackInit(&st);
	while (cur||StackEmpty(&st)==0)
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//最后一棵子树的右子树
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* top;
	BTNode* cur = root;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		printf("%c ", top->_data);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}
//非递归后序遍历
void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode* prev=NULL;
	BTNode* top;
	BTNode* cur = root;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//最后一棵子树的右子树
		top = StackTop(&st);
		//判断是否存在右子树,不存在，那就访问根，出栈，如果存在，要先访问右子树,如果右子树已经访问完，可以访问根
		if(top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		//存在右子树，且没有访问，先访问右子数
		else
		{
			cur = top->_right;
		}
	}
	printf("\n");
}

void TestBinarryTree()
{   //ABD##E#H##CF##G##
	//#D#B#E#H#A#F#C#G#
	int i = 0;
	char a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	BTNode* root = BinaryTreeCreate(a, &i);
	//递归前序遍历
	BinaryTreePrevOrder(root);
	printf("\n");
	//非递归前序遍历
	BinaryTreePrevOrderNonR(root);
	//递归中序遍历
	BinaryTreeInOrder(root);
	printf("\n");
	//非递归中序遍历
	BinaryTreeInOrderNonR(root);
	//递归后序遍历
	BinaryTreePostOrder(root);
	printf("\n");
	//非递归后序遍历
	BinaryTreePostOrderNonR(root);
	//i = BinaryTreeLeafSize(root);
	//printf("%d\n",i);
	//i = BinaryTreeSize(root);
	//printf("%d\n", i);
}
//void TestBinarryTree()
//{   //ABD##E#H##CF##G##
//	//#D#B#E#H#A#F#C#G#
//	//int i = 0;
//	//char a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
//	//BTNode* root = BinaryTreeCreate(a, &i);
//	//BinaryTreePrevOrder(root);
//	//printf("\n");
//	//BinaryTreeLevelOrder(root);
//	int i = 0;
//	int ret1 = 0;
//	int ret2 = 0;
//	//非平衡二叉树
//	char a1[] = { 'A','B','D','G','#','#','H','#','#','#','C','E','#','I','#','#','F','#','#' };
//	//平衡二叉树
//	char a2[] = { 'A','B','D','G','#','#','H','#','#','Z','#','#','C','E','#','#','F','#','#' };
//	BTNode* root1 = BinaryTreeCreate(a1, &i);
//	i = 0;
//	BTNode* root2 = BinaryTreeCreate(a2, &i);
//	BinaryTreeLevelOrder(root1);
//	BinaryTreeLevelOrder(root2);
//	ret1 = BinaryTreeComplete(root1);
//	ret2 = BinaryTreeComplete(root2);
//	printf("ret1=%d ret2=%d\n", ret1, ret2);
//}
int main()
{
	TestBinarryTree();
	return 0;
}