#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//模拟实现strlen()
unsigned int my_strlen(const char* str)
{
	assert(str != NULL);
	//下面是第一种写法，首次直接尝试的
	//unsigned int count = 0;
	//while (*str != '\0') {
	//	count++;
	//	str++;
	//}
	//第二种写法
	unsigned int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

//模拟实现strcpy()
char* my_strcpy(char* des, const char* scr)
{
	assert(des != NULL);
	assert(scr != NULL);
	char* ret = des;
	while (*des++ = *scr++) {
		;
	}
	return ret;
}
int main()
{
	char str[20] = "hello";
	char str1[] = "world";
	int m=my_strlen(str);
	printf("%d\n", m);
	return 0;
}