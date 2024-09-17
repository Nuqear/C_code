#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1.通讯录中能够存放1000个人的信息
// 每个人的信息：
// 名字 + 年龄 + 性别 + 电话 + 地址
// 2.增加人的信息
// 3，删除指定人的信息
// 4，修改指定人的信息 
// 5，查找指定人的信息 
// 6，排序通讯录的信息
// contact.h
// 类型定义
// 函数声明
// contact.c
// 函数的实现
// 这里为了方便，把所有的都放在一起

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_DATA 10
//首先定义一个结构体，包含一个人的信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
typedef struct Contact
{
	PeoInfo data[MAX_DATA];
	int sz;//用于存放联系人个数
}Contact;
//打印菜单
void menu()
{
	printf("*******************************\n");
	printf("***** 1.add      2.delet  *****\n");
	printf("***** 3.search   4.modify *****\n");
	printf("***** 5.sort     6.print  *****\n");
	printf("**********  0.exit  ***********\n");
	printf("*******************************\n");

}
//定义一个枚举体，清晰化选项
enum function
{
	EXIT,
	ADD,
	DELET,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
//初始化通讯录
void InitContact(Contact* pc) {
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
//添加功能函数
void AddContact(Contact* pc) {
	if (pc->sz == MAX_DATA) {
		printf("通讯录已满，无法添加！\n");
		
	}
	else {
		printf("请输入姓名：");
		scanf("%s", pc->data[pc->sz].name);//注意无需另加一个中间变量来存储；sz为0时，直接向下标为0的添加
		printf("请输入年龄：");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入性别：");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话：");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址：");
		scanf("%s", pc->data[pc->sz].addr);
		printf("添加成功！\n");
		pc->sz++;
	}
}
enum FindType
{
	ERROR,
	NAME,
	AGE,
	TELE,
	ADDR
};

//int FindbyAge(Contact* pc, int age) {
//	int i;
//	for (i = 0; i < pc->sz; i++) {
//		if (pc->data[i].age == age) {
//			return i;
//		}
//	}
//	return -1;
//}
//int FindbyTele(Contact* pc, char tele[]) {
//	int i;
//	for (i = 0; i < pc->sz; i++) {
//		if (strcmp(pc->data[i].tele, tele) == 0) {//字符串比较用这个函数
//			return i;
//		}
//	}
//	return -1;
//}
//int FindbyAddr(Contact* pc, char addr[]) {
//	int i;
//	for (i = 0; i < pc->sz; i++) {
//		if (strcmp(pc->data[i].addr, addr) == 0) {//字符串比较用这个函数
//			return i;
//		}
//	}
//	return -1;
//}
// 上面是修改前的，下面是优化后的
int Find(Contact* pc, int type, char* data, int* res) {
	int len = 0;
	if (type == 0) {
		//res[0] = -1;
		return 0;
	}
	PeoInfo* pt = NULL;
	switch (type)
	{
	case NAME:
		len = MAX_NAME;
		pt = (PeoInfo*)pc->data[0].name;
		break;
	case AGE:
		len = sizeof(int);
		pt = (PeoInfo*)&(pc->data[0].age);
		break;
	case TELE:
		len = MAX_TELE;
		pt = (PeoInfo*)pc->data[0].tele;
		break;
	case ADDR:
		pt = (PeoInfo*)pc->data[0].addr;
		len = MAX_ADDR;
		break;
	default:
		printf("输入类型无效！");
		return 0;
	}
	int i;
	int j = 0;
	for (i = 0; i < pc->sz; i++) {
		if (memcmp(pt, data, len) == 0) {//通过内存比较来实现不同数据类型的一次比较
			res[j++] = i;
		}
		pt++;
	}
	if (j == 0) {
		printf("没有找到相关数据！\n");
		/**res = -1;*/
		return 0;
	}
	return j;
}
//删除通讯录联系人
void DeletContact(Contact* pc) {
	if (pc->sz == 0) {
		printf("通讯录已空，无法删除！\n");
	}
	else {
		printf("请输入要删除的名字：");
		char name[MAX_NAME] = { 0 };
		scanf("%s", name);
		int pos[2];
		int res=Find(pc,NAME, name,pos);
		if (res==0) {
			printf("未找到要删除的名字，请重新输入或者启动查询。\n");
		}
		else {
			for (int i = pos[0]; i < pc->sz - 1; i++) {
				pc->data[i] = pc->data[i + 1];//同类型结构体可以直接赋值
			}//排除最后一个，把后面的往前挪
			pc->sz--;//因为有这个操作，所以前面可以没有把最后一个值改变
			printf("删除成功！");
		}
	}
}
int SearchContact(Contact* pc) {
	if (pc->sz==0)
	{
		printf("通讯录为空，请选择添加或退出！\n");
	}
	else {
		void PrintContact(Contact * pc, int start, int len);//函数声明
		void PrintTitle();
		int input;
		int pos;
		char* data;
		int len;
		printf("请输入要查询的选项：1、姓名；2、年龄；3、电话；4、地址\n");
		scanf("%d", &input);
		switch (input)
		{	
		case NAME:
			printf("请输入要查询的姓名：");
			len = MAX_NAME;
			break;
		case AGE:
			printf("请输入要查询的年龄：");
			len = sizeof(int);
			
			break;
		case TELE:
			printf("请输入要查询的电话：");
			len = MAX_TELE;
			
			break;
		case ADDR:
			printf("请输入要查询的地址：");
			len = MAX_ADDR;
			break;
		default:
			printf("查询选项输入错误！\n");
			return -1;
		}
		//开辟动态空间，同时给指针一段内存
		data = (char*)malloc(len);
		if (data == NULL) {
			perror("SearchContact");
			exit(1);
		}
		memset(data, 0, len);//初始化
		scanf("%s", data);
		int res[MAX_DATA];
		memset(res, -1, MAX_DATA);
		if (Find(pc, input, data, res)) {
			PrintTitle();
			int j = 0;
			while (res[j] != -1) {
				PrintContact(pc, res[j], 1);
				j++;
			}
		}
		free(data);
	}
}
void ModifyContact(Contact* pc) {
	if (pc->sz == 0) {
		printf("通讯录为空，无法修改！请选择添加功能。\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		int res[10] ;
		int i = 0;
		memset(res, -1, 40);
		printf("请输入要修改的联系人姓名：");
		scanf("%s", name);
		if (Find(pc, NAME, name, res)) {
			while (res[i] != -1) {
			PrintTitle();
			PrintContact(pc, res[i], 1);
			printf("请输入姓名：");
			memset(pc->data[res[i]], 0, sizeof(PeoInfo));//先清空
			scanf("%s", pc->data[res[i]].name);//注意无需另加一个中间变量来存储；sz为0时，直接向下标为0的添加
			printf("请输入年龄：");
			scanf("%d", &(pc->data[res[i]].age));
			printf("请输入性别：");
			scanf("%s", pc->data[res[i]].sex);
			printf("请输入电话：");
			scanf("%s", pc->data[res[i]].tele);
			printf("请输入地址：");
			scanf("%s", pc->data[pc->sz].addr);
			}
			printf("修改成功！\n");
			
		}
	}
}
//打印标题
void PrintTitle() {
	printf("%-20s\t%-5s\t%-3s\t%-15s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");//标题单独打印
}
//打印通讯录
void PrintContact(Contact* pc,int start,int len) {
	if (pc->sz == 0) {
		printf("通讯录为空！\n");
	}
	else {
		for (int i = start; i < start+len; i++) {
			printf("%-20s\t%-5d\t%-3s\t%-15s\t%-30s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
		}

	}
}
int main()
{
	
	
	int input;
	Contact con;
	//初始化通讯录
	InitContact(&con);
	do
	{
		//打印一个选择菜单
		menu();
		//提示输入语句
		printf("请输入命令数字代号：");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&con);
			break;
		case DELET:
			DeletContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			break;
		case PRINT:
			if (con.sz) {
				PrintTitle();
				PrintContact(&con, 0, con.sz);
			}
			else {
				printf("通讯录为空！\n");
			}
			break;
		case EXIT:
			printf("退出成功。\n");
			break;
		default:
			printf("输入命令错误，请重新输入！\n");
		}
	} while (input);
	return 0;
}