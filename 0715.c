#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//写一个程序来实现通讯录功能
//1.首先需要一个通讯录指令界面
//2.管理一些联系人信息，姓名电话等
//3.实现对若干联系人的增删改查工作
//此结构体包含了一个联系人的信息
typedef struct PersonInfo {
	char name[1024];

	char phone[1024];
}PersonInfo;
#define MAX_PERSONINFO_SIZE 1000
//此结构体包含了所有联系人的信息
typedef struct AddressBook {
	PersonInfo persons[MAX_PERSONINFO_SIZE];
	//通过size来表示数组中的有效元素个数
	//（0,size）就表示有效元素范围
	int size;
}AddressBook;
void init(AddressBook* addressBook) {
	memset(addressBook->persons, 0, sizeof(addressBook->persons));
	addressBook->size = 0;
}
//创建一个菜单
int menu() {
	printf("------------------------\n");
	printf("欢迎使用通讯录程序\n");
	printf("0.退出程序\n");
	printf("1.查看所有联系人\n");
	printf("2.新增联系人\n");
	printf("3.根据姓名查找联系人\n");
	printf("4.删除联系人\n");
	printf("5.修改联系人信息\n");
	printf("------------------------\n");
	printf("请输入你的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void showPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	//只需要把每个联系人的信息打印出来
	printf("查找所有联系人...\n");
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		printf("[%d] %s\t%s\n",i,p->name,p->phone);
	}
	printf("共显示了%d条数据\n", addressBook->size);
}
void addPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
 	printf("新增联系人...\n\n");
	//联系人已经满了
	if (addressBook->size > MAX_PERSONINFO_SIZE) {
		printf("新增失败，联系人已满");
		return;
	}
	//把新增联系人的信息放在下标为size的位置上
	PersonInfo* p = &addressBook->persons[addressBook->size];
	printf("请输入联系人的姓名：");
	scanf("%s",p->name);
	printf("请输入联系人的电话：");
	scanf("%s", p->phone);
	addressBook->size++;
	printf("新增联系人成功\n");
}
void findPersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	int count = 0;
	//根据姓名找到对应的电话
	printf("根据姓名查找联系人\n\n");
	printf("请输入要查找的姓名：");
	char name[1024] = { 0 };
	scanf("%s", name);
	//遍历数组中的每一个元素
	for (int i = 0; i < addressBook->size; i++) {
		PersonInfo* p = &addressBook->persons[i];
		if (strcmp(p->name,name) == 0) {
			//如果遇到通讯录有重名的情况下就把这些都打印出来
			printf("[%d] %s\t%s\n", i, p->name, p->phone);
			count++;
		}
	}
	printf("查找完毕,共查找到了%d条结果\n",count);
}
void deletePersonInfo(AddressBook* addressBook) {
	//此时的删除联系人我们可以用最后一个元素替换待删除联系人信息
	assert(addressBook != NULL);
	printf("删除联系人\n\n");
	printf("请输入待删除联系人的序号：");
	int id = 0;
	scanf("%d", &id);
	//判断序号合法性
	if (id<0 || id>addressBook->size) {
		printf("您的输入有误，删除联系人失败\n");
		return;
	}
	if (id == addressBook->size - 1) {
		//此时的待删除元素恰好为最后一个元素
		addressBook->size--;
		return;
		printf("删除成功\n\n");
	}
	//待删除元素为中间元素时，把最后元素拷贝到中间元素位置
	addressBook->persons[id]= addressBook->persons[addressBook->size - 1];
	addressBook->size--;
	printf("\n删除成功\n");
}
void updatePersonInfo(AddressBook* addressBook) {
	assert(addressBook != NULL);
	printf("修改联系人信息...\n\n\n");
	printf("请输入待修改联系人的id:");
	int id = 0;
	scanf("%d", &id);
	//判断序号的合法性
	if (id<0 || id>addressBook->size) {
		printf("您的输入有误，修改联系人失败\n");
		return;
	}
	//先取出联系人结构体变量
	PersonInfo* p = &addressBook->persons[id];
	//若只需修改姓名或者电话时，不修改元素时输入*
	printf("请输入待修改联系人新的姓名：");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name,"*") != 0) {
		//表示此时输入的姓名有效
		strcpy(p->name, name);
	}
	printf("请输入待修改联系人新的电话：");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone,"*")!=0) {
		//表示此时输入的电话有效
		strcpy(p->phone, phone);
	}
	printf("修改联系人完成\n\n");
}
//退出程序的一种方法：
//void quit(AddressBook* addressBook) {
//	printf("Goodbye!\n");
//	system("pause");
//	//退出程序(相当于main函数中的return 0)本质上属于结束进程
//	exit(0);
//}
//根据刚才的函数操作提取出函数指针类型
typedef void(*Func)(AddressBook*);
AddressBook addressBook;
int main() {
	//先在main函数中创建出结构体变量来
	
	//针对这个结构体变量进行初始化
	init(&addressBook);
	//创建一个函数数组
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
			printf("非法的choice\n");
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