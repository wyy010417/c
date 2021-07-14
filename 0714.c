#include<stdio.h>
#include<stdlib.h>
//这个预处理指令的作用是将内存对齐数默认改为2
#pragma pack(2)
struct A {
	char a;//a的对齐数为1
	int b;//b的对齐数为2，b占4个字节，取2和4 之间的较小值
	char c;//c的对齐数为1
};
//还原内存对齐数为默认值8
#pragma pack()
//枚举
enum SEX {
	MALE,
    FEMALE,
	UNKNOWM
};
enum WEEK {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
};
//此时的SEX和WEEK这个概念应该是互不相干的
//但是在c语言中，他们都被视为int，因此是可以混淆使用的
union UN {
	//在联合体中，成员内部是公用同一个内存区域的
	char i;
	int a;
};
union IPaddress {
	//给计算机看就当做一个大整数即可
	unsigned int data;
	//给人看就可以将其分为四个部分
	struct IP {
		unsigned char a;
		unsigned char b;
		unsigned char c;
		unsigned char d;       
	}ip;
};
//方法一：
//int isBigEnd() {
//	int num = 0x11223344;
//	int* p = &num;
//	char* p2 = (char*)p;
//	if (*p2 == 0x11) {
//		//返回1为大端
//		return 1;
//	}
//	//返回0为小端
//	return 0;
//}
int isBigEnd() {
	union UN {
		int num;
		char num2;
	}u;
	u.num = 0x11223344;
	if (u.num2 == 0x11) {
		return 1;
	}
	return 0;
}
int main() {
	isBigEnd();
	printf("%d\n", isBigEnd());
	//写一个代码区分主机是大端还是小端
	//union UN u;
	//u.i = 10;
	//u.a = 0;
	////因此在改变其中一个变量的值时会影响其他成员值得变化
	//printf("%d\n", u.i);
	/*enum SEX s = MALE;
	s = MONDAY;*/
	/*struct A structA;
	printf("%p\n", &structA);
	printf("%p\n", &structA.a);
	printf("%p\n", &structA.b);
	printf("%p\n", &structA.c);
	printf("%d\n", sizeof(structA));*/
	system("pause");
	return 0;
}