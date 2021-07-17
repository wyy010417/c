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
//	//找数字时我们从数组的左上角开始
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
//		printf("找到了\n");
//	}
//	else {
//		printf("没找到\n");
//	}
//	system("pause");
//	return 0;
//}
//int main() {
//	char acHello[] = "hello\0world";
//	char acNew[15] = { 0 };
// strcpy函数在复制字符串时遇到\0就结束
//	strcpy(acNew, acHello);
//	printf("%s", acNew);
//	system("pause");
//	return 0;
//}
//模拟实现atoi
//atoi的规则是：跳过不可见字符，碰到负号或者数字开始转换，转换到非数字字符为止
//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>
//#include<assert.h>
////VALLD 表示结果合法
////INVALLD 表示结果不合法
////利用枚举列举出两种情况
//enum State {
//	VALLD,//0
//	INVALLD  //1
//};
////默认结果可能非法，当正确转换后再改为合法
//enum State state = INVALLD;
//int myAtoi(char* str) {
//	int flag = 1;
//	long long ret = 0;
//	assert(str);
//	state = INVALLD;
//	//跳过空白字符
//	//isspace函数的作用是检查空白字符
//	while (isspace(*str)) {
//		str++;
//	}
//	if (*str == '\0') {
//		return 0;
//	}
//	//跳过正负号
//	if (*str == '+') {
//		str++;
//	}
//	else if (*str == '-') {
//		flag = -1;
//		str++;
//	}
//	//开始转换数字字符直到非数字字符
//	//isdigit 函数的作用是检查是否为十进制数字
//	while (isdigit(*str)) {
//		ret = ret * 10 + flag * (*str - '0');
//		if ((ret > INT_MAX) || (ret < INT_MIN)){
//			return 0;
//		}
//		str++;
//    }
//	//正常停止
//	if (*str == '\0') {
//		state = VALLD;
//		return(int)ret;
//	}
//	else {
//		//遇到非数字字符
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
	int sum = 0;//用来存放数组遍历异或后的结果
	int differ = 0;//保存两个数第一个不同的二进制位
	for (int i = 0; i < size; i++) {
		sum ^= arr[i];
	}
	for (int i = 0; i < 32; i++) {
		//找出两个只出现一次的数第一次出现的不同二进制位
		if (sum >> i) {
			differ = i;//保存两个数第一个不同的二进制位
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