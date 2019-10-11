//#include"BinarryTree.h"
#include"Stack.h"
#include"QueueNode.h"
#include<assert.h>
#include<malloc.h>

//ͨ��ǰ���������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreate(a, pi);
		//��Ҫ������������ʱ����++
		(*pi)++;
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
	{
		return NULL;
	}
}
 //ͨ���������������"#D#B#E#H#A#F#C#G#"���������� 
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
//��Ч�ڵ����
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
//Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) 
{
	if (root == NULL)
	{
		return 0;
	}
	//rootΪҶ�ӽڵ�
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//��K��ڵ����
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
//����
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
//����

//ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	//�ݹ飺
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
//�������
void BinaryTreeInOrder(BTNode* root)
{
	//�ݹ飺
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
//�������
void BinaryTreePostOrder(BTNode* root)
{
	//�ݹ飺
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
//�������
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	//��Ԫ�����
//	if (root)
//		QueuePush(&q,root);
//	while (QueueEmpty(&q) == 0)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//����
//		printf("%c ", front->_data);
//		//�������
//		if (front->_left)
//			QueuePush(&q, front->_left);
//		if (front->_right)
//			QueuePush(&q, front->_right);
//	}
//	printf("\n");
//}
//// �ж϶������Ƿ�����ȫ������ 
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
//		//�ж��Ƿ�Ϊ��
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
//		//�ж��Ƿ�Ϊ�գ��ǿգ�˵��������
//		if (front)
//		{
//			QueueDestory(&q);
//			return -1;
//		}
//		QueuePop(&q);
//	}
//	return 1;
//}
//�ǵݹ�ǰ�����
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
		//���һ��������������
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
//�ǵݹ�������
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
		//���һ��������������
		top = StackTop(&st);
		//�ж��Ƿ����������,�����ڣ��Ǿͷ��ʸ�����ջ��������ڣ�Ҫ�ȷ���������,����������Ѿ������꣬���Է��ʸ�
		if(top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		//��������������û�з��ʣ��ȷ���������
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
	//�ݹ�ǰ�����
	BinaryTreePrevOrder(root);
	printf("\n");
	//�ǵݹ�ǰ�����
	BinaryTreePrevOrderNonR(root);
	//�ݹ��������
	BinaryTreeInOrder(root);
	printf("\n");
	//�ǵݹ��������
	BinaryTreeInOrderNonR(root);
	//�ݹ�������
	BinaryTreePostOrder(root);
	printf("\n");
	//�ǵݹ�������
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
//	//��ƽ�������
//	char a1[] = { 'A','B','D','G','#','#','H','#','#','#','C','E','#','I','#','#','F','#','#' };
//	//ƽ�������
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