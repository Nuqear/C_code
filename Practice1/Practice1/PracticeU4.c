#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//5��
//#include <math.h>
//int main()
//{
//	double a;
//	int sign=0,b;
//
//	do
//	{
//		printf("�������֣�");
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
//9��
//�����Ҫ�����������ô����һ������������ã�����Ͳ���
//int main()
//{
//	int a,b,i=0,n=0;
//	int arr[5];
//	printf("�������֣�");
//	scanf("%d", &a);
//	while ((a < 0) || (a >= 100000))
//	{
//		printf("������Ҫ������֣����������룺");
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
//	printf("����һ��%dλ��\n", n);
//	//�����ǰ��������
//	//for(i = n - 1; i >=0; i--)
//	//	printf("%d\n", arr[i]);
//	return 0;
//}
//ϰ��11
//�޸�����ĿҪ�󣬴Ӽ���������������ֽ�������
int main() {
	void selectionSort(int arr[], int n);
	void printArray(int arr[], int n);
	int arr[4] = { 8,35,6,1 };
	selectionSort(arr, 4);
	printArray(arr, 4);
}
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}
		if (minIndex != i) {
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
		}
	}
}
void printArray(int arr[],int n ) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}