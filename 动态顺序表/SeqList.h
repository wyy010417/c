#ifndef _SEQL_LIST_H_
#define _CRT_SECURE_NO_WARNINGS
#define _SEQ_LIST_H_
#include"Common.h"
#include <corecrt_wstdio.h>
#define ElemType int
#define INC_SIZE 3
//���ݽṹ�Ķ���
typedef struct SeqList {
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;
//��������
bool_inc(SeqList* pst);
bool_Isfull(SeqList* pst);
bool_IsEmpty(SeqList* pst);
//------------------------------------------------
void SeqListInit(SeqList* pst, size_t capacity);
void SeqListPushBack(SeqList* pst, ElemType v);//v��ʾβ���ֵ
void SeqListPushFront(SeqList* pst, ElemType v);
void SeqListPopBack(SeqList* pst);//βɾ
void SeqListPopFront(SeqList* pst);//ͷɾ
void SeqListEraseByPos(SeqList* pst,int pos);//��λ��ɾ��
void SeqListEraseByVal(SeqList* pst,ElemType v);
void SeqListInsertByPos(SeqList* pst, int pos,ElemType v);//��λ�ò���
void SeqListInsertByVal(SeqList* pst, ElemType v);
size_t SeqListCapacity(SeqList* pst);
size_t SeqListLength(SeqList* pst);
ElemType SeqListFindByPos(SeqList* pst);//��λ�ò��Ҷ�Ӧֵ
int SeqListFindByVal(SeqList* pst, ElemType key);//����ֵ���Ҷ�Ӧλ��
void SeqListSort(SeqList* pst);//��������Ԫ������
void SeqListReverse(SeqList* pst);//��������Ԫ�ؽ�������
void SeqListClear(SeqList* pst);//�������������Ԫ��
void SeqListDestroy(SeqList* pst);//�ݻ٣����ͷ��ڴ�
void SeqListShow(SeqList* pst);
//����ʵ��
bool_inc(SeqList* pst) {
	pst->base = (ElemType*)realloc(pst->base,
	sizeof(ElemType) * (pst->capacity + INC_SIZE));
	//�ж������Ƿ�ɹ�
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
	//�������
	if (pst->size >= pst->capacity) {
		printf("˳����������㣬%d���ܲ���.\n", v);
		return;
	}
	pst->base[pst->size++] = v;
}
void SeqListPushFront(SeqList* pst, ElemType v) {
	//�������
	if (pst->size >= pst->capacity) {
		printf("˳����������㣬%d���ܲ���.\n", v);
		return;
	}
	//�ƶ�����
	for (int i = pst->size; i > 0; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	//��������
	pst->base[0] = v;
	pst->size++;
}
void SeqListPopBack(SeqList* pst) {
	if (pst->size == 0) {
		printf("˳����ѿգ�ɾ��ʧ��\n");
		return;
	}
	//ɾ������
	pst->size--;
}
void SeqListPopFront(SeqList* pst) {
	if (pst->size == 0) {
		printf("˳����ѿգ�ɾ��ʧ��\n");
		return;
	}
	//��ÿһ��Ԫ�������һλ
	for (int i = 0; i < pst->size - 1; i++) {
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void SeqListEraseByPos(SeqList* pst, int pos) {
	//�������λ�õĵĺϷ���
	if (pos < 0 || pos >= pst->size) {
		printf("ɾ����λ�÷Ƿ���ɾ��ʧ��\n");
		return;
	}
	//ɾ������
	for (int i = pos; i < pst->size - 1; i++) {
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void SeqListEraseByVal(SeqList* pst, ElemType key) {
	//�������Ǳ���ȷ����������Ԫ������
	//���ҹؼ�ֵ
	int pos = SeqListFindByVal(pst, key);
	if (pos == -1) {
		printf("Ҫɾ�������ݲ�����\n");
		return;
	}
	//�����ڣ�ɾ������
	SeqListEraseByPos(pst, pos);
}
void SeqListInsertByPos(SeqList* pst, int pos, ElemType v) {
	//�������
	if (pst->size >= pst->capacity) {
		printf("˳����������㣬%d���ܲ���\n", v);
		return;
	}
	//���λ��
	if (pos<0 || pos>pst->size) {
		printf("�����λ�÷Ƿ�,%d���ܲ���\n", v);
		return;
	}
	//��������
	for (int i = pst->size; i > pos; i--) {
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = v;
	pst->size++;
}
void SeqListInsertByVal(SeqList* pst, ElemType v) {
	//�������
	if (pst->size >= pst->capacity) {
		printf("˳����������㣬%d���ܲ���\n", v);
		return;
	}
	//Ѱ�Ҳ����λ��
	int pos = 0;
	while (pos<pst->size && v>pst->base[pos]) {
		pos++;
	}
	//��������
	SeqListInsertByPos(pst, pos, v);
}
size_t SeqListCapacity(SeqList* pst) {
	return pst->capacity;
}
size_t SeqListLength(SeqList* pst) {
	return pst->size;
}
ElemType SeqListFindByPos(SeqList* pst, int pos) {
	//���λ��
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
			//���˺�������ֵΪ�٣���û��ִ�������ܣ��������������
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
		printf("�˱�Ϊ��");
	}
	printf("\n");
}
#endif/*_SEQ_LIST_H_*/