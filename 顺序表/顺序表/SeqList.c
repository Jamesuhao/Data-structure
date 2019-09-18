#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"SeqList.h"
#include<assert.h>
#include<malloc.h>

//��ʼ��
void SeqListInit(SeqList* psl)
{
	assert(psl);//����sql�Ƿ�Ϊ��
	psl->array = NULL;//��ǰ��ַ��Ϊ��
	psl->size = 0;//˳���ǰ����Ϊ0
	psl->capacity = 0;//˳���ǰ����Ϊ0
}
//�ݻ�˳���
void SeqListDestory(SeqList *psl)
{
	assert(psl);//����psl�Ƿ�Ϊ��
	if (psl->array)
	{
		free(psl->array);//�ͷ�psl�ռ�
		psl->array = NULL;//��ǰ��ַ��Ϊ��
		psl->capacity = 0;//����������Ϊ0
		psl->size = 0;//����ʵ�ʳ�����Ϊ0
	}
}
//�������
void SeqListCheckCapacity(SeqList *psl)
{
	assert(psl);//����psl�Ƿ�Ϊ��;
	if (psl->size == psl->capacity)
	{
		size_t newCapacity = (psl->capacity == 0 ? 5 : 2 * psl->capacity);//����������
		//malloc: 
		SLDataType newspace = (SLDataType*)malloc(newCapacity*sizeof(SLDataType));//����ռ�
		assert(psl->array);//����Ƿ����ɹ�
		memcpy(newspace, psl, newCapacity*sizeof(SLDataType));//�������ݵ��¿ռ�
		free(psl);//�ͷſռ�
		psl=newspace;
		assert(psl->array);//����Ƿ����ɹ�

		psl->capacity = newCapacity;//��������
	}
}
//β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);//����sql�Ƿ�Ϊ��
	SeqListCheckCapacity(psl);
	psl->array[psl->size] = x;//Ϊβ��������Ҫ�����ֵ
	psl->size++;//˳���ǰ���ȼ�һ
}
//βɾ
void SeqListPopBack(SeqList *psl)
{
	assert(psl);//����sql�Ƿ�Ϊ��
	if (psl->size == 0)//�ж�˳����Ƿ�Ϊ��
	{
		printf("SeqList has been empty\n");
		return;
	}
	psl->size--;//˳���Ϊ��ʱ��˳����ȼ�һ
}
//ͷ��
void SeqListPushFront(SeqList *psl, SLDataType x)
{
	size_t end = 0;
	assert(psl);//����sql�Ƿ�Ϊ��
	SeqListCheckCapacity(psl);//�������
	for (end = psl->size; end > 0; end--)
	{
		psl->array[end] = psl->array[end - 1];//����ǰ˳�������������һλ
	}
	psl->array[0] = x;//Ϊͷ������Ҫ�����ֵ
	psl->size++;//��ǰ˳����ȼ�1
}
//ͷɾ
void SeqListPopFront(SeqList *psl)
{
	size_t start = 0;
	assert(psl);//����psl�Ƿ�Ϊ��
	if (psl->size == 0)//�ж�˳����Ƿ�Ϊ��
	{
		printf("SeqList has been empty!\n");
		return;
	}
	for (start = 0; start < psl->size - 1; start++)
	{
		psl->array[start] = psl->array[start + 1];//����ǰ˳�������������һλ
	}
	psl->size--;//��ǰ˳����ȼ�һ
}
//��posλ��������
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x)
{
	//pos==0-->ͷ��
	//pso==szie-->β��
	size_t end = 0;
	assert(psl && (pos >= 0) && (pos <= psl->size));//���psl�Ƿ�Ϊ�ղ��жϲ���λ�õĺϷ���
	SeqListCheckCapacity(psl);
	for (end = psl->size; end > pos; end--)
	{
		psl->array[end] = psl->array[end - 1];//����ǰ˳���posλ�Ժ�����������һλ
	}
	psl->array[pos] = x;//����posλ����Ϊx
	psl->size++;//��ǰ˳����ȼ�1
}
//ɾ����posλ����
void SeqListErase(SeqList *psl, size_t pos)
{
	size_t start = 0;
	assert(psl && (pos >= 0) && (pos <= psl->size));//���psl�Ƿ�Ϊ�ղ��жϲ���λ�õĺϷ���
	if (psl->size == 0)//�ж�˳����Ƿ�Ϊ��
	{
		printf("SeqList has been empty\n");
		return;
	}
	for (start = pos; start < psl->size - 1; start++)
	{
		psl->array[start] = psl->array[start + 1];//����posλ���������ǰ��һλ
	}
	psl->size--;//˳���ǰ���ȼ�һ
}
//��������
int SeqListFind(SeqList *psl, SLDataType x)
{
	size_t i = 0;
	assert(psl);//����psl�Ƿ�Ϊ��
	if (psl->size == 0)//�ж�˳����Ƿ�Ϊ��
	{
		printf("SeqList has been empty\n");
		return -1;
	}
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)//����˳����������
		{
			return i;//�ҵ������±�
		}
	}
	return -1;//δ�ҵ�����-1
}

//�޸ĵ�posλ����
void SeqListModify(SeqList *psl, size_t pos, SLDataType x)
{
	assert(psl && (pos >= 0) && (pos <= psl->size));//���psl�Ƿ�Ϊ�ղ��ж��޸�λ�õĺϷ���
	if (psl->size == 0)//�ж�˳����Ƿ�Ϊ��
	{
		printf("SeqList has been empty\n");
		return;
	}
	psl->array[pos] = x;//�޸�posλ������
}
//��ӡ˳���
void SeqListPrint(SeqList *psl)
{
	size_t i = 0;
	assert(psl);//���psl�Ƿ�Ϊ��
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);//��ӡ
	}
	printf("\n");
}
//˳���ĳ���
size_t SeqListSize(SeqList *psl)
{
	assert(psl);//���psl�Ƿ�Ϊ��
	return psl->size;//���س���
}
//������ȫ��ɾ��
void SeqListRemoveAll(SeqList *psl, SLDataType x)
{
	size_t i = 0;
	size_t index = 0;
	assert(psl);//����psl�Ƿ�Ϊ��
	if (psl->size == 0)//�ж�˳����Ƿ�Ϊ��
	{
		printf("SeqList has been empty\n");
		return;
	}
	for (i = 0; i < psl->size; i++)
	{
		//����˼ά
		//if (psl->array[i] == x)//�ҵ�����
		//{
		//psl->size--;//��ǰ���ȼ�һ
		//	for (index=i; index < psl->size ; index++)
		//	{
		//		psl->array[index] = psl->array[index + 1];//ɾ�����ݣ��������ݺ��������ǰ��һλ
		//	}
		//	return;
		//}
		//����˼ά�������ʱ���棬���ʱ����
		if (psl->array[i] != x)//��ǰ���ݲ�����xʱ
		{
			psl->array[index] = psl->array[i];//���䱣��
			index++;
		}
	}
	if (index < psl->size)//�³���С��ԭ����ʱ��ɾ���ɹ�
	{
		psl->size = index;//���³��ȸ���˳���ĳ���
		return;
	}
	printf("SeqList does not the data\n");//δ�ҵ�������
}
//ð�ݷ���˳�������
void SeqListBubbleSort(SeqList *psl)
{
	assert(psl);
	//����
	size_t end = psl->size;
	while (end > 1)
	{
		//����ð������
		int flag = 0;
		for (size_t i = 0; i < end; i++)
		{
			if (psl->array[i - 1]>psl->array[i])
			{
				flag = 1;
				//����
				(psl->array[i - 1]) ^= (psl->array[i]);
				(psl->array[i]) ^= (psl->array[i - 1]);
				(psl->array[i - 1]) ^= (psl->array[i]);
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}
//˳�����ֲ���
int SeqListBinaryFind(SeqList *psl, SLDataType x)
{
	assert(psl);
	if (psl->size == 0)
	{
		printf("SeqList has been empt\n");
		return -1;
	}
	size_t start = 0;
	size_t end = psl->size - 1;
	while (start <= end)
	{
		size_t mid = start + (start + end) / 2;
		if (psl->array[mid] == x)
		{
			return mid;
		}
		else if (psl->array[mid] > x)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}