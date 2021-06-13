#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//const char* myStrstr(const char* str1, const char* str2) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	assert(*str1 != '\0');
//	assert(*str2 != '\0');
//	//创建一个black指针指向str1
//	const char* black = str1;
//	//外层循环控制black从哪个位置开始找子串
//	while (*black) {
//		const char* red = black;
//		const char* sub = str2;
//		//内层循环就是从black开始，判断这个子串和str2是否相等
//		while (*black && *sub && *red==*sub) {
//			red++;
//			sub++;
//		}
//		//以上循环结束有三种可能
//		//1)*red=='\0' 没有找到对应子串
//		//2)*sub=='\0' 找到了对应子串
//		//3)*red!=*sub 此时要进行black++，进行下一次循环
//		/*if (*red == '\0' || *sub ==*red) {
//			black++;
//			continue;
//		}*/
//		if (*sub == '\0') {
//			return black;
//		}
//		black++;
//	}
//	return NULL;
//}
//int main() {
//	char str1[] = "hello world";
//	char str2[] = "llo";
//	const char* result = myStrstr(str1, str2);
//	printf("%s\n", result);
//	system("pause");
//	return 0;
//}
//strtok的应用（字符串分割）
//strtok 内部使用静态变量记录上次调用的位置
int main() {
	char str[] = "aa bb cc dd";
	//第一次调用从str开始，找空格，找到之后将空格改为\0,然后返回起始位置
	char* pch = strtok(str," ");
	while (pch !=NULL) {
		printf("%s\n",pch);
	//第二次调用，从第一次切分结束位置开始，找空格，找到后将空格改为\0
	//后几次同理
		pch = strtok(NULL," ");
	}
	system("pause");
	return 0;
}
//模拟实现memcpy
//void* myMemcpy(void* dest, const void* src,size_t num) {
//	//先校验参数
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	//强制类型转换
//	char* cdest = (char*)dest;
//	const char* csrc = (const char*)src;
//	for (size_t i = 0; i < num; i++) {
//		cdest[i] = csrc[i];
//	}
//}
//int main() {
//	int arr1[1024] = { 0 };
//	int arr2[] = { 1,2,3,4 };
//	myMemcpy(arr1, arr2, sizeof(arr2));
//	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
//		printf("%d  ", arr1[i]);
//	}
//    system("pause");
//	return 0;
//} 
//模拟实现memmove(有重叠内存区域的拷贝）
//void* myMemmove (void* dest, const void* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	char* cdest = (char*)dest;
//	const char* csrc = (const char*)src;
//	if (csrc<=cdest&&cdest<=csrc+num) {
//		//若内存重叠就倒着拷贝
//		for (size_t i = num; i > 0; i--) {
//			cdest[i - 1] = csrc[i - 1];
//		}
//		return dest;
//	}
//	else {
//		//如果不重叠就正着拷贝
//		for (size_t i = 0; i < num; i++) {
//			cdest[i] = csrc[i];
//		}
//		return dest;
//	}
//}
//int main() { 
//	char str1[1024] = "abcd";
//	char str2[] = "bcde";
//	printf("%s\n", myMemmove(str1, str2,sizeof(str2)));
//	system("pause");
//	return 0;
//
//模拟实现memcmp
//int myMemcmp(const void* ptr1, const void* ptr2,size_t num) {
//	assert(ptr1 != NULL);
//	assert(ptr2 != NULL);
//	assert(num != 0);
//	const char* cptr1 = (const char*)ptr1;
//	const char* cptr2 = (const char*)ptr2;
//	for (size_t i = 0; i < num; i++) {
//		if (cptr1[i] < cptr2[i]) {
//			return -1;
//		}
//		else if (cptr1[i] > cptr2[i]) {
//			return 1;
//		}
//		else {
//			continue;
//		}
//	}
//	return 0;
//}
//int main() {
//
//	char str1[] = "abcd";
//	char str2[] = "bcde";
//	printf("%d\n", myMemcmp(str1, str2, sizeof(str1)));
//	system("pause");
//	return 0;
//}
//模拟实现memset
//此函数的作用为将内存空间中一段改为某个value变量
//void* myMemset(void* ptr, int value, size_t num) {
//	assert(ptr != NULL);
//	assert(num != 0);
//	char* cptr = (char*)ptr;
//	for (size_t i = 0; i < num; i++) {
//		cptr[i] = (char)value;
//	}
//	return ptr;
//}
//int main() {
//	char str[] = "giggle";
//	char value = '-';
//	printf("%s\n", myMemset(str, value,3));
//	system("pause");
//	return 0;
//}