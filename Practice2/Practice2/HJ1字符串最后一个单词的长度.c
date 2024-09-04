#define _CRT_SECURE_NO_WARNINGS 1
// 难点：1.“最后”——通过scanf("%s",str)!=EOF判断
//2.一个单词——通过%s自动分隔来保证“单词”；向同一个变量存储来保证一个
#include <stdio.h>
#include <string.h>
int main() {
	char str[5000];
	int num;

	while (scanf("%s", str) != EOF)
		num = strlen(str);
	printf("%d\n", num);
	return 0;
}