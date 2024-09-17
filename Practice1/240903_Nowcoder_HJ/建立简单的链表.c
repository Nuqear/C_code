#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct STUDENT
{
	char name[21];
	int id;
	struct STUDENT* next;
};
typedef struct STUDENT STU;
int main()
{
	STU* p, * head, * tail;
	int n = 3, i;
	p = (struct STUDENT*)malloc(sizeof(struct STUDENT));
	head = p;
	tail = p;
	head->next = NULL;

	for (i = 0; i < n; i++)
	{
		p = (struct STUDENT*)malloc(sizeof(struct STUDENT));
		printf("请输入姓名：");
		scanf("%s", &p->name);
		printf("请输入学号：");
		scanf("%d", &p->id);
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	p = head->next;
	while (p != NULL)
	{
		printf("姓名：%s 学号：%d\n", p->name, p->id);
		p = p->next;

	}
	return 1;
}