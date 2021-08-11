#ifndef _SEQL_LIST_H_
#define _CRT_SECURE_NO_WARNINGS
#define _SEQ_LIST_H_
#include"Common.h"
#include <corecrt_wstdio.h>
#define ElemType int
#define INC_SIZE 3
//数据结构的定义
typedef struct SeqList {
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;
//函数声明
bool_inc(SeqList* pst);
bool_Isfull(SeqList* pst);
bool_IsEmpty(SeqList* pst);
//------------------------------------------------
void SeqListInit(SeqList* pst, size_t capacity);
void SeqListPushBack(SeqList* pst, ElemType v);//v表示尾插的值
void SeqListPushFront(SeqList* pst, ElemType v);
void SeqListPopBack(SeqList* pst);//尾删
void SeqListPopFront(SeqList* pst);//头删
void SeqListEraseByPos(SeqList* pst,int pos);//按位置删除
void SeqListEraseByVal(SeqList* pst,ElemType v);
void SeqListInsertByPos(SeqList* pst, int pos,ElemType v);//按位置插入
void SeqListInsertByVal(SeqList* pst, ElemType v);
size_t SeqListCapacity(SeqList* pst);
size_t SeqListLength(SeqList* pst);
ElemType SeqListFindByPos(SeqList* pst);//按位置查找对应值
int SeqListFindByVal(SeqList* pst, ElemType key);//按数值查找对应位置
void SeqListSort(SeqList* pst);//对数组内元素排序
void SeqListReverse(SeqList* pst);//对数组内元素进行逆置
void SeqListClear(SeqList* pst);//清除数组中所有元素
void SeqListDestroy(SeqList* pst);//摧毁，即释放内存
void SeqListShow(SeqList* pst);
//函数实现
bool_inc(SeqList* pst) {
	pst->base = (ElemType*)realloc(pst->base,
	sizeof(ElemType) * (pst->capacity + INC_SIZE));
	//判读扩容是否成功
	if (pst->base == NULL) {
		return false;
	}
}
bool_IsFull(SeqList* pst) {
	return pst->size >= pst->capacity;
}
bool_IsEmpty(SeqList* pst) {
	return pst->size == 0;
}
void SeqListInit(SeqList* pst, size_t capacity) {
	pst->capacity = capacity;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * pst->capacity);
	pst->size = 0;
}
void SeqListPushBack(SeqList* pst, ElemType v) {
	//检查容量
	if (pst->size >= pst->capacity) {
		printf("顺序表容量不足，%d不能插入.\n", v);
		return;
	}
	pst->base[pst->size++] = v;
}
void SeqListPushFront(SeqList* pst, ElemType v) {
	//检查容量
	if (pst->size >= pst->capacity) {
		printf("顺序表容量不足，%d不能插入.\n", v);
		return;
	}
	//移动数据
	for (int i = pst->size; i > 0; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	//插入数据
	pst->base[0] = v;
	pst->size++;
}
void SeqListPopBack(SeqList* pst) {
	if (pst->size == 0) {
		printf("顺序表已空，删除失败\n");
		return;
	}
	//删除数据
	pst->size--;
}
void SeqListPopFront(SeqList* pst) {
	if (pst->size == 0) {
		printf("顺序表已空，删除失败\n");
		return;
	}
	//将每一个元素向后移一位
	for (int i = 0; i < pst->size - 1; i++) {
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void SeqListEraseByPos(SeqList* pst, int pos) {
	//检查输入位置的的合法性
	if (pos < 0 || pos >= pst->size) {
		printf("删除的位置非法，删除失败\n");
		return;
	}
	//删除数据
	for (int i = pos; i < pst->size - 1; i++) {
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void SeqListEraseByVal(SeqList* pst, ElemType key) {
	//首先我们必须确保此数组中元素有序
	//查找关键值
	int pos = SeqListFindByVal(pst, key);
	if (pos == -1) {
		printf("要删除的数据不存在\n");
		return;
	}
	//若存在，删除数据
	SeqListEraseByPos(pst, pos);
}
void SeqListInsertByPos(SeqList* pst, int pos, ElemType v) {
	//检查容量
	if (pst->size >= pst->capacity) {
		printf("顺序表容量不足，%d不能插入\n", v);
		return;
	}
	//检查位置
	if (pos<0 || pos>pst->size) {
		printf("插入的位置非法,%d不能插入\n", v);
		return;
	}
	//插入数据
	for (int i = pst->size; i > pos; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = v;
	pst->size++;
}
void SeqListInsertByVal(SeqList* pst, ElemType v) {
	//检查容量
	if (pst->size >= pst->capacity) {
		printf("顺序表容量不足，%d不能插入\n", v);
		return;
	}
	//寻找插入的位置
	int pos = 0;
	while (pos<pst->size && v>pst->base[pos]) {
		pos++;
	}
	//插入数据
	SeqListInsertByPos(pst, pos, v);
}
size_t SeqListCapacity(SeqList* pst) {
	return pst->capacity;
}
size_t SeqListLength(SeqList* pst) {
	return pst->size;
}
ElemType SeqListFindByPos(SeqList* pst, int pos) {
	//检查位置
	assert(pos >= 0 && pos < pst->size);
	return pst->base[pos];
}
int SeqListFindByVal(SeqList* pst, ElemType key) {
	for (int i = 0; i < pst->size; i++) {
		if (key == pst->base[i]) {
			return i;
		}
	}
	return -1;
}
void SeqListSort(SeqList* pst) {
	for (int i = 0; i < pst->size - 1; i++) {
		bool is_swap = false;
		for (int j = 0; j < pst->size - i - 1; j++) {
			if (pst->base[j] > pst->base[j + 1]) {
				Swap(&(pst->base[j]), &(pst->base[j + 1]));
				is_swap = true;
			}
		}
		if (!is_swap) {
			//若此函数返回值为假，即没有执行排序功能，则表明排序正常
			break;
		}
	}
}
void SeqListReverse(SeqList* pst) {
	int left = 0;
	int right = pst->size - 1;
	while (left <= right) {
		Swap(&(pst->base[left]), &(pst->base[right]));
		left++;
		right--;
	}
}
void SeqListClear(SeqList* pst) {
	pst->size = 0;
}
void SeqListDestroy(SeqList* pst) {
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}
void SeqListShow(SeqList* pst) {
	for (int i = 0; i < pst->size; i++) {
		printf("%d ", pst->base[i]);
	}
	if (pst->base[0] == NULL) {
		printf("此表为空");
	}
	printf("\n");
}
#endif/*_SEQ_LIST_H_*/