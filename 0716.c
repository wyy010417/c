//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 }, * q[4], k;
//	for (k = 0; k < 4; k++) {
//		q[k] = &a[k * 3];
//	}
//	printf("%d\n", q[3][1]);
//	system("pause");
//	return 0;
//}
//int main(){
//	int i, j, a = 0;
//	for (i = 0; i < 2; i++){
//		for (j = 0; j < 4; j++){
//			if (j % 2) {
//				break;
//			}
//		a++;
//		}
//	a++;
//	} 
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}
//int findNum(int a[][3], int x, int y, int num) {
//	int i = 0, j = x - 1;
//	//������ʱ���Ǵ���������Ͻǿ�ʼ
//	while (j >= 0 && i < y) {
//		if (a[i][j] < num) {
//			i++;
//		}
//		else if (a[i][j] > num) {
//			j--;
//		}
//		else {
//			return 1;
//		}
//	}
//	return 0;
//}
//int main() {
//	int a[][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	if (findNum(a, 3, 3, 10)) {
//		printf("�ҵ���\n");
//	}
//	else {
//		printf("û�ҵ�\n");
//	}
//	system("pause");
//	return 0;
//}
//int main() {
//	char acHello[] = "hello\0world";
//	char acNew[15] = { 0 };
// strcpy�����ڸ����ַ���ʱ����\0�ͽ���
//	strcpy(acNew, acHello);
//	printf("%s", acNew);
//	system("pause");
//	return 0;
//}
//ģ��ʵ��atoi
//atoi�Ĺ����ǣ��������ɼ��ַ����������Ż������ֿ�ʼת����ת�����������ַ�Ϊֹ
//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>
//#include<assert.h>
////VALLD ��ʾ����Ϸ�
////INVALLD ��ʾ������Ϸ�
////����ö���оٳ��������
//enum State {
//	VALLD,//0
//	INVALLD  //1
//};
////Ĭ�Ͻ�����ܷǷ�������ȷת�����ٸ�Ϊ�Ϸ�
//enum State state = INVALLD;
//int myAtoi(char* str) {
//	int flag = 1;
//	long long ret = 0;
//	assert(str);
//	state = INVALLD;
//	//�����հ��ַ�
//	//isspace�����������Ǽ��հ��ַ�
//	while (isspace(*str)) {
//		str++;
//	}
//	if (*str == '\0') {
//		return 0;
//	}
//	//����������
//	if (*str == '+') {
//		str++;
//	}
//	else if (*str == '-') {
//		flag = -1;
//		str++;
//	}
//	//��ʼת�������ַ�ֱ���������ַ�
//	//isdigit �����������Ǽ���Ƿ�Ϊʮ��������
//	while (isdigit(*str)) {
//		ret = ret * 10 + flag * (*str - '0');
//		if ((ret > INT_MAX) || (ret < INT_MIN)){
//			return 0;
//		}
//		str++;
//    }
//	//����ֹͣ
//	if (*str == '\0') {
//		state = VALLD;
//		return(int)ret;
//	}
//	else {
//		//�����������ַ�
//		return(int)ret;
//	}
//}
//int main() {
//	char* p = "    145hgsk0";
//	printf("%d\n", myAtoi(p));
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
void findTwoNum(int* arr, int size, int* num1, int* num2) {
	int sum = 0;//������������������Ľ��
	int differ = 0;//������������һ����ͬ�Ķ�����λ
	for (int i = 0; i < size; i++) {
		sum ^= arr[i];
	}
	for (int i = 0; i < 32; i++) {
		//�ҳ�����ֻ����һ�ε�����һ�γ��ֵĲ�ͬ������λ
		if (sum >> i) {
			differ = i;//������������һ����ͬ�Ķ�����λ
			break;
		}
	}
	for (int i = 0; i < size; i++) {
		if ((arr[i] >> differ) & 1) {
			*num1 ^= arr[i];
		}
		else {
			*num2 ^= arr[i];
		}
	}
	
}
int main() {
	int num1 = 0;
	int num2 = 0;
	int arr[] = { 2,2,4,4,6,6,7,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	findTwoNum(arr, size, &num1, &num2);
	printf("%d %d\n", num1, num2);
	system("pause");
	return 0;
}