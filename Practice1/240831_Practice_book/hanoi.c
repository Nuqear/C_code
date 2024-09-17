#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int hanoi(int n, char a, char b, char c)
{
	static int count = 0;
	if (n==1)
	{
		printf("%c-->%c\t", a, c);
		
	}
	else
	{
		hanoi(n - 1, a, c, b);
		printf("%c-->%c\t", a, c);
		hanoi(n - 1, b, a, c);
	}
	count++;
	if (count%10==0)
	{
		printf("\n");
	}
	return count;
}
int main()
{
	int n,m;
	printf("����Ҫ�ƶ�����������");
	scanf("%d", &n);
	m=hanoi(n, 'A','B','C');
	printf("�ƶ��ܴ���Ϊ��%d\n", m);
	return 0;
}