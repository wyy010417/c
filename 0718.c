#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main() {
	//���ļ�����
	FILE* f = fopen("C:/Users/������/.text.c.txt","w");
	if (f == NULL) {
		/*printf("��ʧ��  %d\n",errno);*/
		//ʹ��strerror�������Է���errno���еĴ���ԭ��
		/*printf("�ļ���ʧ�� %s\n", strerror(errno));*/
		//perror����Ҳ���Դ�ӡ�����ļ�ʧ�ܵ�ԭ����strerror�����÷�����
		perror("���ļ�ʧ��");
		return 0;
	}
	printf("���ļ��ɹ� %p\n", f);
	//���ļ��ɹ���Ϳ���ʹ��fread���ж�ȡ�ļ�
	//char* p = (char* )calloc(1,1024);
	//if (p == NULL) {
	//	return;
	//}
	////fread�����еĵ�һ�������ǽ������е����ݼ��ص��ڴ������Ӧ���ڴ��ַ
	////�ڶ���������ָһ��Ԫ����ռ�ֽڣ�������������Ԫ�ظ��������ĸ���������·����Ӧ��ַ
	//size_t len = fread(p, 1, 20, f);
	//printf("%d\n", len);
	//printf("%s\n", p);
	
	//���ļ��ɹ���Ϳ��Խ���д���ļ�����
	//д�ļ����ǰ��ڴ��е�����д�뵽������
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