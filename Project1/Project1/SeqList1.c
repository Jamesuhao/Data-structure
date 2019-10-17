//#include<malloc.h>
//#include<assert.h>
//#include"SeqList.h"
//��ʼ��
//void SeqListInit(SeqList* psl)
//{
//	assert(psl);
//	psl->array = NULL;
//	psl->capacity = 0;
//	psl->size = 0;
//}
//����
//void SeqListDestory(SeqList* psl)
//{
//	assert(psl);
//	if (psl->array)
//	{
//		psl->array = NULL;
//		psl->capacity = 0;
//		psl->size = 0;
//		free(psl);
//	}
//}
//�������
//void CheckCapacity(SeqList* psl)
//{
//	assert(psl);
//	�������
//	if (psl->size == psl->capacity)
//	{
//		����������
//		size_t newcapacity = psl->capacity == 0 ? 5 : 2 * psl->capacity;
//		����ռ�
//		psl->array = (SLDataType*)realloc(psl->array, newcapacity * sizeof(SLDataType));
//		����Ƿ����ɹ�
//		assert(psl->array);
//		��������
//		psl->capacity = newcapacity;
//	}
//}
//
//��ɾ�Ĳ�
//β��
//void SeqListPushBack(SeqList* psl, SLDataType x)
//{
//	assert(psl);
//	�������
//	CheckCapacity(psl);
//	����β��
//	psl->array[psl->size] = x;
//	psl->size++;
//}
//βɾ
//void SeqListPopBack(SeqList* psl)
//{
//	assert(psl);
//	if (psl->size > 0)
//	{
//		psl->size--;
//	}
//}
//ͷ��
//void SeqListPushFront(SeqList* psl, SLDataType x)
//{
//	assert(psl);
//	CheckCapacity(psl);
//	size_t end = psl->size;
//	�ƶ�Ԫ�أ��Ӻ���ǰ
//	while (end > 0)
//	{
//		psl->array[end] = psl->array[end - 1];
//		end--;
//	}
//	psl->array[end] = x;
//	psl->size++;
//}
//ͷɾ
//void SeqListPopFront(SeqList* psl)
//{
//	assert(psl);
//	size_t start = 0;
//	if (psl->size > 0)
//	{
//		while (start < psl->size - 1)
//		{
//			psl->array[start] = psl->array[start + 1];
//			start++;
//		}
//		psl->size--;
//	}
//}
//�ڵ�posλ����
//void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
//{
//	assert(psl && pos >= 0 && pos <= psl->size);
//	CheckCapacity(psl);
//	if (psl->size > 0)
//	{
//		size_t end = psl->size;
//		while (end > pos)
//		{
//			psl->array[end] = psl->array[end - 1];
//			end--;
//		}
//		psl->array[pos] = x;
//		psl->size++;
//	}
//}
//ɾ����posλ������
//void SeqListErase(SeqList* psl, size_t pos)
//{
//	size_t start = pos;
//	assert(psl && pos >= 0 && pos < psl->size);
//	if (psl->size > 0)
//	{
//		while (start < psl->size - 1)
//		{
//			psl->array[start] = psl->array[start + 1];
//			start++;
//		}
//		psl->size--;
//	}
//}
//ɾ������x
//void SeqListRemoveAll(SeqList* psl, SLDataType x)
//{
//	size_t i = 0;
//	size_t index = 0;
//	assert(psl);
//	if (psl->size > 0)
//	{
//		for (i = 0; i < psl->size; i++)
//		{
//			if (psl->array[i] != x)
//			{
//				psl->array[index] = psl->array[i];
//				index++;
//			}
//		}
//		psl->size = index;
//	}
//}
//�޸ĵ�posλ����
//void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
//{
//	assert(psl && pos >= 0 && pos < psl->size);
//	if (psl->size > 0)
//	{
//		psl->array[pos] = x;
//	}
//}
//����
//int SeqListFind(SeqList* psl, SLDataType x)
//{
//	assert(psl);
//	size_t i = 0;
//	if (psl->size == 0)
//	{
//		return -1;
//	}
//	for (i = 0; i < psl->size; i++)
//	{
//		if (psl->array[i] == x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//��ӡ˳���
//void SeqListPrint(SeqList* psl)
//{
//	assert(psl && psl->size > 0);
//	size_t i = 0;
//	for (i = 0; i < psl->size; i++)
//	{
//		printf("%d ", psl->array[i]);
//	}
//	printf("\n");
//}
//˳���Ĵ�С
//int SeqListSize(SeqList* psl)
//{
//	assert(psl);
//	if (psl->size > 0)
//	{
//		return psl->size;
//	}
//	return 0;
//}
//ð������
//void SeqListBubbleSort(SeqList* psl)
//{
//	size_t i = 1;
//	assert(psl);
//	if (psl->size == 0)
//	{
//		return;
//	}
//	size_t end = psl->size;
//	while (end > 1)
//	{
//		size_t flag = 0;
//		for (i = 1; i < end; i++)
//		{
//			if (psl->array[i] < psl->array[i - 1])
//			{
//				flag = 1;
//				(psl->array[i]) ^= (psl->array[i - 1]);
//				(psl->array[i - 1]) ^= (psl->array[i]);
//				(psl->array[i]) ^= (psl->array[i - 1]);
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//		end--;
//	}
//}
////˳�����ֲ���
//int SeqListBinaryFind(SeqList* psl, SLDataType x)
//{
//	assert(psl);
//	if (psl->size > 0)
//	{
//		size_t start = 0;
//		size_t end = psl->size - 1;
//		while (start <= end)
//		{
//			size_t mid = start + (end - start) / 2;
//			if (psl->array[mid] < x)
//			{
//				start = mid+1;
//			}
//			else if (psl->array[mid] > x)
//			{
//				end = mid-1;
//			}
//			else
//			{
//				return mid;
//			}
//		}
//	}
//	return -1;
//}
////����
//void TestSeqList()
//{
//	SeqList sl;
//	SeqListInit(&sl);
//	SeqListPushBack(&sl, 3);
//	SeqListPushBack(&sl, 8);
//	SeqListPushBack(&sl, 7);
//	SeqListPushBack(&sl, 6);
//	SeqListPushBack(&sl, 0);
//	SeqListPushBack(&sl, 5);
//	SeqListPushBack(&sl, 2);
//	SeqListPrint(&sl);
//	SeqListBubbleSort(&sl);
//	//SeqListErase(&sl, 3);
//	//SeqListInsert(&sl, 2, 7);
//	//SeqListPopBack(&sl);
//	//int a = SeqListFind(&sl,3);
//	//printf("%d\n", a);
//	//SeqListPushFront(&sl, 1);
//	SeqListPrint(&sl);
//	int a = SeqListBinaryFind(&sl, 7);
//	printf("%d\n", a);
//}
//int main()
//{
//	TestSeqList();
//	return 0;
//}