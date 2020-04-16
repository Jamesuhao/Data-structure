#include"array.h"

void SeqListInit(SeqList* sql)
{
	if (sql)
	{
		sql->array = nullptr;
		sql->size = 0;
		sql->size = 0;
	}
}
void SeqListDestory(SeqList* sql)
{
	if (sql)
	{
		if (sql->array)
		{
			free(sql->array);
			sql->size = 0;
			sql->capacity = 0;
		}
	}
}
void SeqListCheckCapacity(SeqList* sql)
{
	if (sql)
	{
		if (sql->capacity == sql->size)
		{
			size_t NewCapacity = (sql->capacity == 0) ? 10 : (sql->capacity * 2);
			//malloc�����ٸ���Ŀռ�
			//realloc�����ٸ���Ŀռ䡢�������ݵ��¿ռ䡢�ͷ�ԭ�еĿռ�
			SLDataType*  array = (SLDataType*)realloc(sql->array, NewCapacity);
			if (array != nullptr)
			{
				sql->array = array;
				sql->capacity = NewCapacity;
			}
			else
			{
				throw("�����ڴ�ʧ�ܣ�");
			}
		}
	}
}
void SeqListPsuhBack(SeqList* sql, SLDataType data)//β��
{
	if (sql)
	{
		SeqListCheckCapacity(sql);
		sql->array[sql->size] = data;
		sql->size++;
	}
}
void SeqListPopBack(SeqList* sql)//βɾ
{
	if (sql->size > 0)
	{
		--sql->size;
	}
}
void SeqListPushFront(SeqList* sql, SLDataType data)//ͷ��
{
	if (sql)
	{
		SeqListCheckCapacity(sql);
		for (int i = sql->size; i > 0; i--)
		{
			sql->array[i] = sql->array[i - 1];
		}
		sql->array[0] = data;
		sql->size++;
	}
}
void SeqListPopFront(SeqList* sql)//ͷɾ
{
	if (sql)
	{
		for (int i = 0; i < sql->size-1; ++i)
		{
			sql->array[i] = sql->array[i + 1];
		}
		sql->size--;
	}
}
int SeqListFind(SeqList* sql, SLDataType data)//��ѯ
{
	if (sql)
	{
		for (int i = 0; i < sql->size; ++i)
		{
			if (sql->array[i] == data)
			{
				return i;
			}
		}
		return -1;
	}
}
void SeqListInsert(SeqList* sql, size_t pos, SLDataType data)//ָ��λ�ò���
{
	if (sql)
	{
		SeqListCheckCapacity(sql);
		if (pos > sql->capacity)
		{
			return;
		}
		if (pos >= sql->size)
		{
			sql->array[pos] = data;
		}
		else
		{
			for (int i = sql->size; i > pos; i--)
			{
				sql->array[i] = sql->array[i - 1];
			}
			sql->array[pos] = data;
		}
		++sql->size;
	}
}
void SeqListErase(SeqList* sql, size_t pos)//ָ��λ��ɾ��
{
	if (sql)
	{
		if (pos > sql->capacity)
		{
			return;
		}
		if (pos >= sql->size)
		{
			sql->array[pos] = 0;
		}
		else
		{
			for (int i = pos; i < sql->size - 1; ++i)
			{
				sql->array[pos] = sql->array[pos + 1];
			}
		}
		sql->size--;
	}
}
void SeqListRemove(SeqList* sql, SLDataType data)//ɾ������������data
{
	if (sql)
	{
		int index = 0;
		for (int i = 0; i < sql->size; ++i)
		{
			if (sql->array[i] != data)
			{
				sql->array[index] = sql->array[i];
				++index;
			}
		}
		sql->size = index;
	}
}
void SeqListBubbleSort(SeqList* sql)//ð������
{
	if (sql)
	{
		int flag = 0;
		for (int i = sql->size; i > 1; i--)
		{
			//��������
			for (int j = 1; j < i; ++j)
			{
				if (sql->array[j] < sql->array[j - 1])
				{
					flag = 1;
					SLDataType temp = sql->array[j];
					sql->array[j] = sql->array[j - 1];
					sql->array[j - 1] = temp;
				}
			}
			if (flag == 0)
			{
				break;
			}
		}
		
	}
}
size_t SeqListBinaryFind(SeqList* sql, SLDataType data)
{
	size_t start = 0;
	size_t end = sql->size - 1;
	while (end > start)
	{
		int mid = (start + end) / 2 + start;
		if (sql->array[mid] == data)
		{
			return mid;
		}
		else if (sql->array[mid] > data)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
		return -1;
	}
}