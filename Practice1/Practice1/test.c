#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//第2章习题4.5
//int main()
//{
//	int a;
//	printf("请输入数字：");
//	scanf("%d", &a);
//	if (a % 15==0)
//		printf("%d可以同时被3和5整除", a);
//	else
//		printf("%d不可同时被3和5整除", a);
//	return 0;
//}
//习题4.6
//下面是第一版
//#include <math.h>
//int main()
//{
//	int n;
//	int issushu(int n);
//	for (n = 100; n < 201; n++)
//	{
//		int j = 0;
//		if (j = issushu(n))
//			printf("%d\n", n);
//	}
//
//	return 0;
//}
//int issushu(int n)
//{
//	for (int i = 2;i <= sqrt(n); i++)
//		if (n%i == 0) return 0;
//	return 1;
//}
//下面是第二版
//要点：因为一个数即使不是素数，但是它的因数也是特定的，所以不能用
//n % i ！= 0 来判断，只能用n % i == 0来过滤
//#include <math.h>
//int main()
//{
//	int i, n;
//	for (n = 101; n < 201; n = n + 2)
//	{
//		for (i = 2; i <= sqrt(n); i++)
//			if (n % i == 0) break;
//		printf("%d\n", n);
//	}
//	return 0;
//}
//习题4.7
//辗转相除法
//int main()
//{
//	int a, b,r=1;
//	printf("请输入两个整数：");
//	scanf("%d，%d", &a, &b);
//	while(r != 0) 
//	{
//		r = a % b;
//		a = b;
//		b = r;
//
//	}
//	printf("%d", a);
//	return 0;
//}
//习题8，求闰年
int main()
{
	int n;
	for (n = 1900; n < 2001; n++)
	{
		if((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
		printf("%d\n", n);
	}
	return 0;
}