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
//	//����һ��blackָ��ָ��str1
//	const char* black = str1;
//	//���ѭ������black���ĸ�λ�ÿ�ʼ���Ӵ�
//	while (*black) {
//		const char* red = black;
//		const char* sub = str2;
//		//�ڲ�ѭ�����Ǵ�black��ʼ���ж�����Ӵ���str2�Ƿ����
//		while (*black && *sub && *red==*sub) {
//			red++;
//			sub++;
//		}
//		//����ѭ�����������ֿ���
//		//1)*red=='\0' û���ҵ���Ӧ�Ӵ�
//		//2)*sub=='\0' �ҵ��˶�Ӧ�Ӵ�
//		//3)*red!=*sub ��ʱҪ����black++��������һ��ѭ��
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
//strtok��Ӧ�ã��ַ����ָ
//strtok �ڲ�ʹ�þ�̬������¼�ϴε��õ�λ��
int main() {
	char str[] = "aa bb cc dd";
	//��һ�ε��ô�str��ʼ���ҿո��ҵ�֮�󽫿ո��Ϊ\0,Ȼ�󷵻���ʼλ��
	char* pch = strtok(str," ");
	while (pch !=NULL) {
		printf("%s\n",pch);
	//�ڶ��ε��ã��ӵ�һ���зֽ���λ�ÿ�ʼ���ҿո��ҵ��󽫿ո��Ϊ\0
	//�󼸴�ͬ��
		pch = strtok(NULL," ");
	}
	system("pause");
	return 0;
}
//ģ��ʵ��memcpy
//void* myMemcpy(void* dest, const void* src,size_t num) {
//	//��У�����
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	//ǿ������ת��
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
//ģ��ʵ��memmove(���ص��ڴ�����Ŀ�����
//void* myMemmove (void* dest, const void* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	char* cdest = (char*)dest;
//	const char* csrc = (const char*)src;
//	if (csrc<=cdest&&cdest<=csrc+num) {
//		//���ڴ��ص��͵��ſ���
//		for (size_t i = num; i > 0; i--) {
//			cdest[i - 1] = csrc[i - 1];
//		}
//		return dest;
//	}
//	else {
//		//������ص������ſ���
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
//ģ��ʵ��memcmp
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
//ģ��ʵ��memset
//�˺���������Ϊ���ڴ�ռ���һ�θ�Ϊĳ��value����
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