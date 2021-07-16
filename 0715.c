#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//дһ��������ʵ��ͨѶ¼����
//1.������Ҫһ��ͨѶ¼ָ�����
//2.����һЩ��ϵ����Ϣ�������绰��
//3.ʵ�ֶ�������ϵ�˵���ɾ�Ĳ鹤��
//�˽ṹ�������һ����ϵ�˵���Ϣ
typedef struct PersonInfo {
	char name[1024];

	char phone[1024];
}PersonInfo;
#define MAX_PERSONINFO_SIZE 1000
//�˽ṹ�������������ϵ�˵���Ϣ
typedef struct AddressBook {
	PersonInfo persons[MAX_PERSONINFO_SIZE];
	//ͨ��size����ʾ�����е���ЧԪ�ظ���
	//��0,size���ͱ�ʾ��ЧԪ�ط�Χ
	int size;
}AddressBook;
void init(AddressBook* addressBook) {
	memset(addressBook->persons, 0, sizeof(addressBook->persons));
	addressBook->size = 0;
}
//����һ���˵�
int menu() {
	printf("------------------------\n");
	printf("��ӭʹ��ͨѶ¼����\n");
	printf("0.�˳�����\n");
	printf("1.�鿴������ϵ��\n");
	printf("2.������ϵ��\n");
	printf("3.��������������ϵ��\n");
	printf("4.ɾ����ϵ��\n");
	printf("5.�޸���ϵ����Ϣ\n");
	printf("------------------------\n");
	printf("���������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void showPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	//ֻ��Ҫ��ÿ����ϵ�˵���Ϣ��ӡ����
	printf("����������ϵ��...\n");
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		printf("[%d] %s\t%s\n",i,p->name,p->phone);
	}
	printf("����ʾ��%d������\n", addressBook->size);
}
void addPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
 	printf("������ϵ��...\n\n");
	//��ϵ���Ѿ�����
	if (addressBook->size > MAX_PERSONINFO_SIZE) {
		printf("����ʧ�ܣ���ϵ������");
		return;
	}
	//��������ϵ�˵���Ϣ�����±�Ϊsize��λ����
	PersonInfo* p = &addressBook->persons[addressBook->size];
	printf("��������ϵ�˵�������");
	scanf("%s",p->name);
	printf("��������ϵ�˵ĵ绰��");
	scanf("%s", p->phone);
	addressBook->size++;
	printf("������ϵ�˳ɹ�\n");
}
void findPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	int count = 0;
	//���������ҵ���Ӧ�ĵ绰
	printf("��������������ϵ��\n\n");
	printf("������Ҫ���ҵ�������");
	char name[1024] = { 0 };
	scanf("%s", name);
	//���������е�ÿһ��Ԫ��
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		if (strcmp(p->name,name) == 0) {
			//�������ͨѶ¼������������¾Ͱ���Щ����ӡ����
			printf("[%d] %s\t%s\n", i, p->name, p->phone);
			count++;
		}
	}
	printf("�������,�����ҵ���%d�����\n",count);
}
void deletePersonInfo(AddressBook* addressBook) {
	//��ʱ��ɾ����ϵ�����ǿ��������һ��Ԫ���滻��ɾ����ϵ����Ϣ
	assert(addressBook != NULL);
	printf("ɾ����ϵ��\n\n");
	printf("�������ɾ����ϵ�˵���ţ�");
	int id = 0;
	scanf("%d", &id);
	//�ж���źϷ���
	if (id<0 || id>addressBook->size) {
		printf("������������ɾ����ϵ��ʧ��\n");
		return;
	}
	if (id == addressBook->size - 1) {
		//��ʱ�Ĵ�ɾ��Ԫ��ǡ��Ϊ���һ��Ԫ��
		addressBook->size--;
		return;
		printf("ɾ���ɹ�\n\n");
	}
	//��ɾ��Ԫ��Ϊ�м�Ԫ��ʱ�������Ԫ�ؿ������м�Ԫ��λ��
	addressBook->persons[id]= addressBook->persons[addressBook->size - 1];
	addressBook->size--;
	printf("\nɾ���ɹ�\n");
}
void updatePersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	printf("�޸���ϵ����Ϣ...\n\n\n");
	printf("��������޸���ϵ�˵�id:");
	int id = 0;
	scanf("%d", &id);
	//�ж���ŵĺϷ���
	if (id<0 || id>addressBook->size) {
		printf("�������������޸���ϵ��ʧ��\n");
		return;
	}
	//��ȡ����ϵ�˽ṹ�����
	PersonInfo* p = &addressBook->persons[id];
	//��ֻ���޸��������ߵ绰ʱ�����޸�Ԫ��ʱ����*
	printf("��������޸���ϵ���µ�������");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name,"*") != 0) {
		//��ʾ��ʱ�����������Ч
		strcpy(p->name, name);
	}
	printf("��������޸���ϵ���µĵ绰��");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone,"*")!=0) {
		//��ʾ��ʱ����ĵ绰��Ч
		strcpy(p->phone, phone);
	}
	printf("�޸���ϵ�����\n\n");
}
//�˳������һ�ַ�����
//void quit(AddressBook* addressBook) {
//	printf("Goodbye!\n");
//	system("pause");
//	//�˳�����(�൱��main�����е�return 0)���������ڽ�������
//	exit(0);
//}
//���ݸղŵĺ���������ȡ������ָ������
typedef void(*Func)(AddressBook*);
AddressBook addressBook;
int main() {
	//����main�����д������ṹ�������
	
	//�������ṹ��������г�ʼ��
	init(&addressBook);
	//����һ����������
	Func arr[] = {
		NULL,
		showPersonInfo,
		addPersonInfo,
		findPersonInfo,
		deletePersonInfo,
		updatePersonInfo
	};
	while (1) {
		int choice = menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
			printf("�Ƿ���choice\n");
			continue; 
		}
		if (choice == 0) {
			break;
		}
		arr[choice](&addressBook);
	}
	system("pause");
	return 0;
}