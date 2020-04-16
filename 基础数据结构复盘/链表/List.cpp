#include"List.h"

void SListInit(SList* plist)
{
	if (plist)
	{
		plist->_head = nullptr;
	}
}
void SListDestory(SList* plist)
{
	if (plist)
	{
		SListNode* cur = plist->_head;
		while (cur)
		{
			SListNode* next = cur->_next;
			free(cur);
			cur = next;
		}
		plist->_head = nullptr;
	}
}
SListNode* BuyListNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->_data = x;
	newNode->_next = nullptr;
	return newNode;
}
void SListPushFront(SList* plist, SLDataType x)
{
	if (plist)
	{
		SListNode* newNode = BuyListNode(x);
		SListNode* cur = plist->_head;
		newNode->_next = cur;
		plist->_head = newNode;
	}
}
void SListPopFront(SList* plist)
{
	if (plist)
	{
		if (plist->_head == nullptr)
		{
			return;
		}
		SListNode* cur = plist->_head;
		SListNode* next = plist->_head->_next;
		free(cur);
		cur = nullptr;
		plist->_head = next;
	}
}
void SListPushBack(SList* plist, SLDataType x)
{
	if (plist)
	{
		if (plist->_head == nullptr)
		{
			plist->_head = BuyListNode(x);
		}
		else
		{
			SListNode* cur = plist->_head;
			while (cur->_next)
			{
				cur = cur->_next;
			}
			cur->_next = BuyListNode(x);
		}
	}
}
void SListPopBack(SList* plist)
{
	if (plist)
	{
		SListNode* cur = plist->_head;
		SListNode* prev = nullptr;
		while (cur->_next)
		{
			prev = cur;
			cur = cur->_next;
		}
		free(cur);
		cur = nullptr;
		if (prev == nullptr)
		{
			plist->_head = nullptr;
		}
		else
		{
			prev->_next = nullptr;
		}
	}
}
SListNode* SListFind(SList* plist, SLDataType x)
{
	if (plist)
	{
		SListNode* cur = plist->_head;
		while (cur)
		{
			if (cur->_data == x)
			{
				return cur;
			}
			else
			{
				cur = cur->_next;
			}
		}
		return nullptr;
	}
}

void SListInsertAfter(SList* plist, SListNode* pos, SLDataType x)
{
	if (plist)
	{
		SListNode* newNode = BuyListNode(x);
		SListNode* next = pos->_next;
		pos->_next = newNode;
		newNode->_next = next;
	}
}
void SListEraseAfter(SList* plist, SListNode* pos)
{
	if (plist)
	{
		SListNode* next = pos->_next;
		if (next != nullptr)
		{
			pos->_next = next->_next;
			free(next);
			next = nullptr;
		}
	}
}