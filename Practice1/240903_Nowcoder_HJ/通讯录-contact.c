#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1.ͨѶ¼���ܹ����1000���˵���Ϣ
// ÿ���˵���Ϣ��
// ���� + ���� + �Ա� + �绰 + ��ַ
// 2.�����˵���Ϣ
// 3��ɾ��ָ���˵���Ϣ
// 4���޸�ָ���˵���Ϣ 
// 5������ָ���˵���Ϣ 
// 6������ͨѶ¼����Ϣ
// contact.h
// ���Ͷ���
// ��������
// contact.c
// ������ʵ��
// ����Ϊ�˷��㣬�����еĶ�����һ��

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_DATA 10
//���ȶ���һ���ṹ�壬����һ���˵���Ϣ
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
	int sz;//���ڴ����ϵ�˸���
}Contact;
//��ӡ�˵�
void menu()
{
	printf("*******************************\n");
	printf("***** 1.add      2.delet  *****\n");
	printf("***** 3.search   4.modify *****\n");
	printf("***** 5.sort     6.print  *****\n");
	printf("**********  0.exit  ***********\n");
	printf("*******************************\n");

}
//����һ��ö���壬������ѡ��
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
//��ʼ��ͨѶ¼
void InitContact(Contact* pc) {
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
//��ӹ��ܺ���
void AddContact(Contact* pc) {
	if (pc->sz == MAX_DATA) {
		printf("ͨѶ¼�������޷���ӣ�\n");
		
	}
	else {
		printf("������������");
		scanf("%s", pc->data[pc->sz].name);//ע���������һ���м�������洢��szΪ0ʱ��ֱ�����±�Ϊ0�����
		printf("���������䣺");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("�������Ա�");
		scanf("%s", pc->data[pc->sz].sex);
		printf("������绰��");
		scanf("%s", pc->data[pc->sz].tele);
		printf("�������ַ��");
		scanf("%s", pc->data[pc->sz].addr);
		printf("��ӳɹ���\n");
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
//		if (strcmp(pc->data[i].tele, tele) == 0) {//�ַ����Ƚ����������
//			return i;
//		}
//	}
//	return -1;
//}
//int FindbyAddr(Contact* pc, char addr[]) {
//	int i;
//	for (i = 0; i < pc->sz; i++) {
//		if (strcmp(pc->data[i].addr, addr) == 0) {//�ַ����Ƚ����������
//			return i;
//		}
//	}
//	return -1;
//}
// �������޸�ǰ�ģ��������Ż����
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
		printf("����������Ч��");
		return 0;
	}
	int i;
	int j = 0;
	for (i = 0; i < pc->sz; i++) {
		if (memcmp(pt, data, len) == 0) {//ͨ���ڴ�Ƚ���ʵ�ֲ�ͬ�������͵�һ�αȽ�
			res[j++] = i;
		}
		pt++;
	}
	if (j == 0) {
		printf("û���ҵ�������ݣ�\n");
		/**res = -1;*/
		return 0;
	}
	return j;
}
//ɾ��ͨѶ¼��ϵ��
void DeletContact(Contact* pc) {
	if (pc->sz == 0) {
		printf("ͨѶ¼�ѿգ��޷�ɾ����\n");
	}
	else {
		printf("������Ҫɾ�������֣�");
		char name[MAX_NAME] = { 0 };
		scanf("%s", name);
		int pos[2];
		int res=Find(pc,NAME, name,pos);
		if (res==0) {
			printf("δ�ҵ�Ҫɾ�������֣��������������������ѯ��\n");
		}
		else {
			for (int i = pos[0]; i < pc->sz - 1; i++) {
				pc->data[i] = pc->data[i + 1];//ͬ���ͽṹ�����ֱ�Ӹ�ֵ
			}//�ų����һ�����Ѻ������ǰŲ
			pc->sz--;//��Ϊ���������������ǰ�����û�а����һ��ֵ�ı�
			printf("ɾ���ɹ���");
		}
	}
}
int SearchContact(Contact* pc) {
	if (pc->sz==0)
	{
		printf("ͨѶ¼Ϊ�գ���ѡ����ӻ��˳���\n");
	}
	else {
		void PrintContact(Contact * pc, int start, int len);//��������
		void PrintTitle();
		int input;
		int pos;
		char* data;
		int len;
		printf("������Ҫ��ѯ��ѡ�1��������2�����䣻3���绰��4����ַ\n");
		scanf("%d", &input);
		switch (input)
		{	
		case NAME:
			printf("������Ҫ��ѯ��������");
			len = MAX_NAME;
			break;
		case AGE:
			printf("������Ҫ��ѯ�����䣺");
			len = sizeof(int);
			
			break;
		case TELE:
			printf("������Ҫ��ѯ�ĵ绰��");
			len = MAX_TELE;
			
			break;
		case ADDR:
			printf("������Ҫ��ѯ�ĵ�ַ��");
			len = MAX_ADDR;
			break;
		default:
			printf("��ѯѡ���������\n");
			return -1;
		}
		//���ٶ�̬�ռ䣬ͬʱ��ָ��һ���ڴ�
		data = (char*)malloc(len);
		if (data == NULL) {
			perror("SearchContact");
			exit(1);
		}
		memset(data, 0, len);//��ʼ��
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
		printf("ͨѶ¼Ϊ�գ��޷��޸ģ���ѡ����ӹ��ܡ�\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		int res[10] ;
		int i = 0;
		memset(res, -1, 40);
		printf("������Ҫ�޸ĵ���ϵ��������");
		scanf("%s", name);
		if (Find(pc, NAME, name, res)) {
			while (res[i] != -1) {
			PrintTitle();
			PrintContact(pc, res[i], 1);
			printf("������������");
			memset(pc->data[res[i]], 0, sizeof(PeoInfo));//�����
			scanf("%s", pc->data[res[i]].name);//ע���������һ���м�������洢��szΪ0ʱ��ֱ�����±�Ϊ0�����
			printf("���������䣺");
			scanf("%d", &(pc->data[res[i]].age));
			printf("�������Ա�");
			scanf("%s", pc->data[res[i]].sex);
			printf("������绰��");
			scanf("%s", pc->data[res[i]].tele);
			printf("�������ַ��");
			scanf("%s", pc->data[pc->sz].addr);
			}
			printf("�޸ĳɹ���\n");
			
		}
	}
}
//��ӡ����
void PrintTitle() {
	printf("%-20s\t%-5s\t%-3s\t%-15s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");//���ⵥ����ӡ
}
//��ӡͨѶ¼
void PrintContact(Contact* pc,int start,int len) {
	if (pc->sz == 0) {
		printf("ͨѶ¼Ϊ�գ�\n");
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
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		//��ӡһ��ѡ��˵�
		menu();
		//��ʾ�������
		printf("�������������ִ��ţ�");
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
				printf("ͨѶ¼Ϊ�գ�\n");
			}
			break;
		case EXIT:
			printf("�˳��ɹ���\n");
			break;
		default:
			printf("��������������������룡\n");
		}
	} while (input);
	return 0;
}