#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	char st[] = { 'b','o','y','s'};
	printf("%d", sizeof(st));
	printf("%d", strlen(st));
	return 0;
}