#include<stdio.h>
#include<stdlib.h>
//���Ԥ����ָ��������ǽ��ڴ������Ĭ�ϸ�Ϊ2
#pragma pack(2)
struct A {
	char a;//a�Ķ�����Ϊ1
	int b;//b�Ķ�����Ϊ2��bռ4���ֽڣ�ȡ2��4 ֮��Ľ�Сֵ
	char c;//c�Ķ�����Ϊ1
};
//��ԭ�ڴ������ΪĬ��ֵ8
#pragma pack()
//ö��
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
//��ʱ��SEX��WEEK�������Ӧ���ǻ�����ɵ�
//������c�����У����Ƕ�����Ϊint������ǿ��Ի���ʹ�õ�
union UN {
	//���������У���Ա�ڲ��ǹ���ͬһ���ڴ������
	char i;
	int a;
};
union IPaddress {
	//����������͵���һ������������
	unsigned int data;
	//���˿��Ϳ��Խ����Ϊ�ĸ�����
	struct IP {
		unsigned char a;
		unsigned char b;
		unsigned char c;
		unsigned char d;       
	}ip;
};
//����һ��
//int isBigEnd() {
//	int num = 0x11223344;
//	int* p = &num;
//	char* p2 = (char*)p;
//	if (*p2 == 0x11) {
//		//����1Ϊ���
//		return 1;
//	}
//	//����0ΪС��
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
	//дһ���������������Ǵ�˻���С��
	//union UN u;
	//u.i = 10;
	//u.a = 0;
	////����ڸı�����һ��������ֵʱ��Ӱ��������Աֵ�ñ仯
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