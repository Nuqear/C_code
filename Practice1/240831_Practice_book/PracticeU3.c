#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//第三章习题2
//#include <math.h>
//int main()
//{
//	int p0 = 1000; double r1 = 0.015, r2 = 0.021,
//		r3 = 0.0275, r5 = 0.03, rh = 0.0035, p;
//	p = p0 * (1 + 5 * r5);
//	printf("一次存5年期的本息和为%lf\n", p);
//	p = p0 * (1 + 2 * r2);
//	p = p * (1 + 3 * r3);
//	printf("先2年后3年的本息和为%lf\n", p);
//	p = p0 * (1 + 3 * r3);
//	p = p * (1 + 2 * r2);
//	printf("先3年后2年的本息和为%lf\n", p);
//	p = p0 * pow((1 + r1), 5);
//	printf("连续存5年的本息和为%lf\n", p);
//	p = p0 * pow((1 + rh / 4), 20);
//	printf("存5年活期的本息和为%lf\n", p);
//	return 0;
//}
//习题6 更改题目要求，任意5个字母用后面第四个代替，如果超出则从头计算（圈密码）
//int main()
//{
//	char arr[4];
//	int i;
//	printf("请输入四个字母：");
//	for (i = 0; i < 4; i++)
//		scanf("%c", &arr[i]);
//
//	for (i = 0; i < 4; i++)
//	{
//		if ((arr[i]<=90)&&(arr[i] + 4 > 90) || (arr[i] + 4 > 122))
//			arr[i] = arr[i] + 4 - 26;
//		else
//			arr[i] = arr[i] + 4;
//		printf("%c", arr[i]);
//	}
//	return 0;
//}
//后记：注意小写字母始终大于大写字母，所以判断大写字母是否超出时，需要先判断是不是大写字母
