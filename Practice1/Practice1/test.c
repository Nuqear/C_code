#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��2��ϰ��4.5
//int main()
//{
//	int a;
//	printf("���������֣�");
//	scanf("%d", &a);
//	if (a % 15==0)
//		printf("%d����ͬʱ��3��5����", a);
//	else
//		printf("%d����ͬʱ��3��5����", a);
//	return 0;
//}
//ϰ��4.6
//�����ǵ�һ��
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
//�����ǵڶ���
//Ҫ�㣺��Ϊһ������ʹ����������������������Ҳ���ض��ģ����Բ�����
//n % i ��= 0 ���жϣ�ֻ����n % i == 0������
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
//ϰ��4.7
//շת�����
//int main()
//{
//	int a, b,r=1;
//	printf("����������������");
//	scanf("%d��%d", &a, &b);
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
//ϰ��8��������
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