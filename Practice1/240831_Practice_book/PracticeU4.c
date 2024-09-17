#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//5题
//#include <math.h>
//int main()
//{
//	double a;
//	int sign=0,b;
//
//	do
//	{
//		printf("输入数字：");
//		scanf("%lf", &a);
//		if ((a > 0) && (a < 1000))
//			sign = 0;
//		else
//			sign = 1;
//	} while (sign);
//	b = (int)sqrt(a);
//	printf("%d", b);
//	return 0;
//}
//9题 倒序输出一个正整数
//如果需要正序输出，那么设置一个数组变量更好，否则就不用
//int main()
//{
//	int a,b,i=0,n=0;
//	int arr[5];
//	printf("输入数字：");
//	scanf("%d", &a);
//	while ((a < 0) || (a >= 100000))
//	{
//		printf("不符合要求的数字，请重新输入：");
//		scanf("%d", &a);
//	}
//	do
//	{
//		b = a / 10;
//		arr[i] = a % 10;
//		printf("%d\n", arr[i]);
//		a = b;
//		i++;
//		n++;
//	} while (b);
//	printf("这是一个%d位数\n", n);
//	//下面是按正序输出
//	//for(i = n - 1; i >=0; i--)
//	//	printf("%d\n", arr[i]);
//	return 0;
//}
// 方法2：改用递归方法
// 顺序打印一个四位数=打印一个三位数+最后位
// 结束标志是只有一位数
void print(int x) {
	if (x>9)
	{
		print(x / 10);
	}
	printf("%d\n", x % 10);
}
int main() {
	int a;
	scanf("%d", &a);
	print(a);
	return 0;
 }
//习题11
//int main() {
//	void selectionSort(int arr[], int n);
//	void printArray(int arr[], int n);
//	int arr[4] = { 8,35,6,1 };
//	selectionSort(arr, 4);
//	printArray(arr, 4);
//}
//void selectionSort(int arr[], int n) {
//	for (int i = 0; i < n - 1; i++) {
//		int minIndex = i;
//		for (int j = i + 1; j < n; j++) {
//			if (arr[minIndex] > arr[j])
//				minIndex = j;
//		}
//		if (minIndex != i) {
//		int temp = arr[i];
//		arr[i] = arr[minIndex];
//		arr[minIndex] = temp;
//		}
//	}
//}
//void printArray(int arr[],int n ) {
//	for (int i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}