#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	char str[3][10];
//	int i;
//	for (i = 0; i < 3; i++) {
//		scanf("%s", str[i]);
//	}
//	for (i = 0; i < 3; i++) {
//		printf("%s", str[i]);
//	}
//	return 0;
//}
//int main()
//{
//	char str[10];
//	scanf("%s", str);
//	
//	printf("%d\n", sizeof(str));
//	for (int i = 0; i < 10; i++)
//		printf("%c\n", str[i]);
//	printf("%s\n", str);
//	return 0;
//}
#include <string.h>
//int main()
//{
//	char str[10];
//	 gets(str);
//	 printf("%d", strlen(str));
//	return 0;
//}
//int main() {
//	char str[10] = { 0 };
//	fgets(str, 10, stdin);
//	for (int i = 0; i < 10; i++)
//		if (str[i] == '\n')printf("Yes");
//	return 0;
//}
int main()
{
	char str[100];
	int i=0;
	while (scanf("%s", str))
		printf("%d\n", i++);
}