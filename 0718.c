#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main() {
	//打开文件操作
	FILE* f = fopen("C:/Users/王咯咯/.text.c.txt","w");
	if (f == NULL) {
		/*printf("打开失败  %d\n",errno);*/
		//使用strerror函数可以翻译errno其中的错误原因
		/*printf("文件打开失败 %s\n", strerror(errno));*/
		//perror函数也可以打印出打开文件失败的原因，与strerror函数用法类似
		perror("打开文件失败");
		return 0;
	}
	printf("打开文件成功 %p\n", f);
	//打开文件成功后就可以使用fread进行读取文件
	//char* p = (char* )calloc(1,1024);
	//if (p == NULL) {
	//	return;
	//}
	////fread函数中的第一个参数是将磁盘中的内容加载到内存中相对应的内存地址
	////第二个参数是指一个元素所占字节，第三个参数是元素个数，第四个参数就是路径对应地址
	//size_t len = fread(p, 1, 20, f);
	//printf("%d\n", len);
	//printf("%s\n", p);
	
	//打开文件成功后就可以进行写入文件操作
	//写文件就是把内存中的内容写入到磁盘中
	char* p = (char*)malloc(11);
	if (p == NULL) {
		return;
	}
	strcpy(p, "helloworld");
	size_t len = fread(p, 1,strlen(p), f);
	printf("%d\n", len);
	system("pause");
	return 0;
}