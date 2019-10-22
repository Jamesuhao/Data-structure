#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	assert(a);
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		if (root == NULL)
			return NULL;
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreate(a, pi);
		(*pi)++;
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	} 
	else
		return NULL;
}
//���ٶ�����
void BinaryTreeDestory(BTNode** root)
{
	BTNode* cur = *root;
	if (cur)
	{
		BinaryTreeDestory(&cur->_left);
		BinaryTreeDestory(&cur->_right);
		free(cur);
		cur = NULL;
	}
}
//��Ч�Ľ�����
int BinaryTreeSize(BTNode* root)
{
	if (root)
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
	return 0;
}
//Ҷ�ӽ�����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//��k��Ľ�����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
//����
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* cur;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	cur = BinaryTreeFind(root->_left, x);
	if (cur->_data == x)
		return cur;
	cur = BinaryTreeFind(root->_right, x);
	if (cur->_data == x)
		return cur;
	return NULL;
}
//����
//ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
//�������
void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
//�������
void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}
//�������
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue st;
//	QueueInit(&st);
//	if (root)
//		QueuePush(&st, root);
//	while (QueueEmpty(&st) == 0)
//	{
//		BTNode* front = QueueFront(&st);
//		QueuePop(&st);
//		printf("%c ", front->_data);
//		if (front->_left)
//			QueuePush(&st, front->_left);
//		if (front->_right)
//			QueuePush(&st, front->_right);
//	}
//}
// �ж϶������Ƿ�����ȫ������ 
//int BinaryTreeComplete(BTNode* root)
//{
//	Queue st;
//	QueueInit(&st);
//	if (root != NULL)
//		QueuePush(&st, root);
//	while (QueueEmpty(&st) == 0)
//	{
//		BTNode* front = QueueFront(&st);
//		QueuePop(&st);
//		if (front)
//		{
//			QueuePush(&st, front->_left);
//			QueuePush(&st, front->_right);
//		}
//		else
//			break;
//	}
//	while (QueueEmpty(&st) == 0)
//	{
//		BTNode* front = QueueFront(&st);
//		if (front)
//		{
//			QueueDestory(&st);
//			return - 1;
//		}
//		QueuePop(&st);
//	}
//	return 1;
//}
//�ǵݹ�ʵ��ǰ�����
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	while (cur != NULL || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
}
//�ǵݹ�ʵ���������
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		printf("%c ", top->_data);
		StackPop(&st);
		cur = top->_right;
	}
}
//�ǵݹ�ʵ�ֺ������
void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* prev = NULL;
	BTNode* cur = root;
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		else
			cur = top->_right;
	}
}
void TestBinary()
{
	int i = 0;
	char a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	//BinaryTreeLevelOrder(root);
	//printf("\n");
	BinaryTreePrevOrderNonR(root);
	printf("\n");
	BinaryTreeInOrderNonR(root);
	printf("\n");
	BinaryTreePostOrderNonR(root);
	printf("\n");
	//int i = 0;
	//int ret1 = 0;
	//int ret2 = 0;
	//��ƽ�������
	//char a1[] = { 'A','B','D','G','#','#','H','#','#','#','C','E','#','I','#','#','F','#','#' };
	//ƽ�������
	//char a2[] = { 'A','B','D','G','#','#','H','#','#','Z','#','#','C','E','#','#','F','#','#' };
	//BTNode* root1 = BinaryTreeCreate(a1, &i);
	//i = 0;
	//BTNode* root2 = BinaryTreeCreate(a2, &i);
	//BinaryTreeLevelOrder(root1);
	//printf("\n");
	//BinaryTreeLevelOrder(root2);
	//printf("\n");  
	//ret1 = BinaryTreeComplete(root1);
	//ret2 = BinaryTreeComplete(root2);
	//printf("ret1=%d ret2=%d\n", ret1, ret2);
}
int main()
{
	TestBinary();
	return 0;
}