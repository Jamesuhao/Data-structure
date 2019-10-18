#include"ListNode.h"
#include<assert.h>
#include<malloc.h>
//��ʼ����ͷ�����ѭ������
void SListInit(SList* plist)
{
	assert(plist);
	plist->head = NULL;
}
//�ݻ���ͷ�����ѭ������
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->head;
	while (cur)
	{
		SListNode* _next = cur->next;
		free(cur);
		cur = _next;
	}
	plist->head = NULL;
}
//������
SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//β��
void SListPushBack(SList* plist, SLDataType x)
{
	assert(plist);
	//����ǵ�һ���ڵ�
	if (plist->head == NULL)
	{
		plist->head = BuySListNode(x);
	}
	//������ǵ�һ���ڵ�
	else
	{
		SListNode* cur = plist->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur = BuySListNode(x);
	}
}
//βɾ
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* prev = NULL;
	SListNode* cur = plist->head;
	if (cur == NULL)
	{
		return;
	}
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	cur = NULL;
	if (prev == NULL)
	{
		plist->head = NULL;
	}
	else
	{
		prev->next = NULL;
	}
}
//ͷ��
void SListPushFront(SList* plist, SLDataType x)
{
	assert(plist);
	if (plist->head == NULL)
	{
		plist->head = BuySListNode(x);
	}
	else
	{
		SListNode* cur = plist->head;
		SListNode* newNode = BuySListNode(x);
		newNode->next = cur;
		plist->head = newNode;
	}
}
//ͷɾ
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->head == NULL)
	{
		return;
	}
	SListNode* cur = plist->head;
	SListNode* _next = plist->head->next;
	free(cur);
	cur = NULL;
	plist->head = _next;
}
//����
SListNode* SListFind(SList* plist, SLDataType x)
{
	assert(plist);
	if (plist->head == NULL)
	{
		return NULL;
	}
	SListNode* cur = plist->head;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//��posλ�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos);
	SListNode* cur = BuySListNode(x);
	cur->next = pos->next;
	pos->next=cur;
}
//��posλ�ĺ���ɾ��
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* cur = pos->next;
	if (cur == NULL)
	{
		return;
	}
	SListNode* next = cur->next;
	pos->next = next;
	free(cur);
	cur = NULL;
}
//ɾ��ĳ��Ԫ��
void SListRemove(SList* plist, SLDataType x)
{
	assert(plist);
	if (plist->head == NULL)
	{
		return;
	}
	SListNode* cur = plist->head;
	SListNode* prev = NULL;
	while (cur)
	{
		if (cur->data == x)
		{
			if (prev == NULL)
			{
				plist->head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void SListPrint(SList* plist)
{
	assert(plist);
	if (plist->head == NULL)
	{
		printf("������Ϊ��\n");
	}
	else
	{
		SListNode* cur = plist->head;
		while (cur)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
	}
}