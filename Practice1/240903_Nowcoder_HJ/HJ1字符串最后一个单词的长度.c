#define _CRT_SECURE_NO_WARNINGS 1
// �ѵ㣺1.����󡱡���ͨ��scanf("%s",str)!=EOF�ж�
//2.һ�����ʡ���ͨ��%s�Զ��ָ�����֤�����ʡ�����ͬһ�������洢����֤һ��
#include <stdio.h>
#include <string.h>
int main() {
	char str[5000];
	int num=0;

	while (scanf("%s", str) != EOF)
		num = strlen(str);
	printf("%d\n", num);
	return 0;
}