#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include"SeqList.h"
#include<assert.h>
#include<malloc.h>

//初始化
void SeqListInit(SeqList* psl)
{
	assert(psl);//检验sql是否为空
	psl->array = NULL;//将前地址置为空
	psl->size = 0;//顺序表当前长度为0
	psl->capacity = 0;//顺序表当前容量为0
}
//摧毁顺序表
void SeqListDestory(SeqList *psl)
{
	assert(psl);//检验psl是否为空
	if (psl->array)
	{
		free(psl->array);//释放psl空间
		psl->array = NULL;//将前地址置为空
		psl->capacity = 0;//将其容量置为0
		psl->size = 0;//将其实际长度置为0
	}
}
//检查容量
void SeqListCheckCapacity(SeqList *psl)
{
	assert(psl);//检验psl是否为空;
	if (psl->size == psl->capacity)
	{
		size_t newCapacity = (psl->capacity == 0 ? 5 : 2 * psl->capacity);//建立新容量
		//malloc: 
		SLDataType newspace = (SLDataType*)malloc(newCapacity*sizeof(SLDataType));//分配空间
		assert(psl->array);//检查是否分配成功
		memcpy(newspace, psl, newCapacity*sizeof(SLDataType));//拷贝内容到新空间
		free(psl);//释放空间
		psl=newspace;
		assert(psl->array);//检查是否分配成功

		psl->capacity = newCapacity;//更新容量
	}
}
//尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);//检验sql是否为空
	SeqListCheckCapacity(psl);
	psl->array[psl->size] = x;//为尾部插入需要插入的值
	psl->size++;//顺序表当前长度加一
}
//尾删
void SeqListPopBack(SeqList *psl)
{
	assert(psl);//检验sql是否为空
	if (psl->size == 0)//判断顺序表是否为空
	{
		printf("SeqList has been empty\n");
		return;
	}
	psl->size--;//顺序表不为空时，顺序表长度减一
}
//头插
void SeqListPushFront(SeqList *psl, SLDataType x)
{
	size_t end = 0;
	assert(psl);//检验sql是否为空
	SeqListCheckCapacity(psl);//检查容量
	for (end = psl->size; end > 0; end--)
	{
		psl->array[end] = psl->array[end - 1];//将当前顺序表的数据向后移一位
	}
	psl->array[0] = x;//为头部插入要插入的值
	psl->size++;//当前顺序表长度加1
}
//头删
void SeqListPopFront(SeqList *psl)
{
	size_t start = 0;
	assert(psl);//检验psl是否为空
	if (psl->size == 0)//判断顺序表是否为空
	{
		printf("SeqList has been empty!\n");
		return;
	}
	for (start = 0; start < psl->size - 1; start++)
	{
		psl->array[start] = psl->array[start + 1];//将当前顺序表的数据向后移一位
	}
	psl->size--;//当前顺序表长度减一
}
//第pos位插入数据
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x)
{
	//pos==0-->头插
	//pso==szie-->尾插
	size_t end = 0;
	assert(psl && (pos >= 0) && (pos <= psl->size));//检查psl是否为空并判断插入位置的合法性
	SeqListCheckCapacity(psl);
	for (end = psl->size; end > pos; end--)
	{
		psl->array[end] = psl->array[end - 1];//将当前顺序表pos位以后的数据向后移一位
	}
	psl->array[pos] = x;//将第pos位更新为x
	psl->size++;//当前顺序表长度加1
}
//删除第pos位数据
void SeqListErase(SeqList *psl, size_t pos)
{
	size_t start = 0;
	assert(psl && (pos >= 0) && (pos <= psl->size));//检查psl是否为空并判断插入位置的合法性
	if (psl->size == 0)//判断顺序表是否为空
	{
		printf("SeqList has been empty\n");
		return;
	}
	for (start = pos; start < psl->size - 1; start++)
	{
		psl->array[start] = psl->array[start + 1];//将第pos位后的数据向前移一位
	}
	psl->size--;//顺序表当前长度减一
}
//查找数据
int SeqListFind(SeqList *psl, SLDataType x)
{
	size_t i = 0;
	assert(psl);//检验psl是否为空
	if (psl->size == 0)//判断顺序表是否为空
	{
		printf("SeqList has been empty\n");
		return -1;
	}
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)//遍历顺序表查找数据
		{
			return i;//找到返回下标
		}
	}
	return -1;//未找到返回-1
}

//修改第pos位数据
void SeqListModify(SeqList *psl, size_t pos, SLDataType x)
{
	assert(psl && (pos >= 0) && (pos <= psl->size));//检查psl是否为空并判断修改位置的合法性
	if (psl->size == 0)//判断顺序表是否为空
	{
		printf("SeqList has been empty\n");
		return;
	}
	psl->array[pos] = x;//修改pos位的数据
}
//打印顺序表
void SeqListPrint(SeqList *psl)
{
	size_t i = 0;
	assert(psl);//检查psl是否为空
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);//打印
	}
	printf("\n");
}
//顺序表的长度
size_t SeqListSize(SeqList *psl)
{
	assert(psl);//检查psl是否为空
	return psl->size;//返回长度
}
//按内容全部删除
void SeqListRemoveAll(SeqList *psl, SLDataType x)
{
	size_t i = 0;
	size_t index = 0;
	assert(psl);//检验psl是否为空
	if (psl->size == 0)//判断顺序表是否为空
	{
		printf("SeqList has been empty\n");
		return;
	}
	for (i = 0; i < psl->size; i++)
	{
		//正常思维
		//if (psl->array[i] == x)//找到数据
		//{
		//psl->size--;//当前长度减一
		//	for (index=i; index < psl->size ; index++)
		//	{
		//		psl->array[index] = psl->array[index + 1];//删除数据，将该数据后的数据向前移一位
		//	}
		//	return;
		//}
		//逆向思维：不相等时保存，相等时跳过
		if (psl->array[i] != x)//当前数据不等于x时
		{
			psl->array[index] = psl->array[i];//将其保存
			index++;
		}
	}
	if (index < psl->size)//新长度小于原长度时，删除成功
	{
		psl->size = index;//将新长度赋给顺序表的长度
		return;
	}
	printf("SeqList does not the data\n");//未找到该数据
}
//冒泡法对顺序表排序
void SeqListBubbleSort(SeqList *psl)
{
	assert(psl);
	//升序
	size_t end = psl->size;
	while (end > 1)
	{
		//单趟冒泡排序
		int flag = 0;
		for (size_t i = 0; i < end; i++)
		{
			if (psl->array[i - 1]>psl->array[i])
			{
				flag = 1;
				//交换
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
//顺序表二分查找
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