#ifndef _COMMON_H_
//预防头文件的重复引用
//#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#define ElemType int
void Swap(ElemType* a, ElemType* b) {
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif/*_COMMON_H_*/