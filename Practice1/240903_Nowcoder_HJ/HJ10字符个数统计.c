#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
    char input[501]={0};
    int str[128] = { 0 };
    int i;
    gets_s(input);
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        str[input[i]] = 1;
    }
    int count=0;
    for (i = 0; i < 128; i++) {
        if (str[i])count++;
    }
    printf("%d", count);
	return 0;
}