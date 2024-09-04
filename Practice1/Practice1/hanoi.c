#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int hanoi(int n, char a, char b, char c)
{
	static int count = 0;
	if (n==1)
	{
		printf("%c-->%c\n", a, c);
		
	}
	else
	{
		hanoi(n - 1, a, c, b);
		printf("%c-->%c\n", a, c);
		hanoi(n - 1, b, a, c);
	}
	count++;
	return count;
}
int main()
{
	int n,m;
	printf("输入要移动的盘子数：");
	scanf("%d", &n);
	m=hanoi(n, 'A','B','C');
	printf("移动总次数为：%d\n", m);
	return 0;
}