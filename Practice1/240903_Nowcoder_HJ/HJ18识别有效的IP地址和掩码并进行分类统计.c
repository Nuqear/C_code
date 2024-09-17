#define _CRT_SECURE_NO_WARNINGS 1

//1.检查是不是合法IP&&检查是不是合法掩码
//2.拆分IP地址（这一版没有）
//3.检查ip地址类别
//4.检查ip是不是私人
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <ctype.h>
int isIP(char* str)
{
    //首先判断第一个字符是不是数字字符
    if (isdigit(str[0]) == 0) {
        return 0;

    }
    //判断首个字符串
    char* p = NULL;
    p = strtok(str, ".");
    char* pend;
    //字符串转换为数字
    int num = strtol(p, &pend, 10);
    if (num == 0 || num == 127 || num > 255 || num < 0 || *pend != '\0') {
        return 0;
    }
    int count = 0;
    //防止连续小数点的跳过
    while ((p=strtok(NULL, "."))!=NULL) {
        
        count++;
        num = strtol(p, &pend, 10);
        if (num < 0 || num>255 || *pend != '\0') {
            return 0;
        }
    }
    if (count != 3) {
        return 0;
    }
    else {
        return 1;
    }
}

void CountType(char* str, int* a, int* b, int* c, int* d, int* e)
{
    char* p = strtok(str, ".");
    char* pend;
    int num = strtol(p, &pend, 10);
    if (num <= 126) {
        *a += 1;
    }
    else if (num <= 191) {
        *b += 1;
    }
    else if (num <= 223) {
        *c += 1;
    }
    else if (num <= 239) {
        *d += 1;
    }
    else if (num <= 255) {

        *e += 1;
    }
}
int isPrivate(char* str)
{
    char* p = strtok(str, ".");
    char* pend;
    int num = strtol(p, &pend, 10);
    if (num == 10) {
        return 1;
    }
    else if (num == 172) {
        p = strtok(NULL, ".");
        num = strtol(p, &pend, 10);
        if (num >= 16 && num <= 31) {
            return 1;
        }
    }
    else if (num == 192) {
        p = strtok(NULL, ".");
        num = strtol(p, &pend, 10);
        if (num == 168) {
            return 1;
        }
    }
    else {
        return 0;
    }

}
int isMask(char* str)
{
    int count=0;
    for (char* p = strtok(str, "."); p != NULL; p = strtok(NULL, ".")) 
    {
        char* pend;
        int num = strtol(p, &pend, 10);
        if (num == 255 && *pend == '\0')
        {
            count++;
        }
        else if (num == 0 && *pend == '\0')
        {
            count--;
        }
        else 
        {
            return 0;
        }
        
    }
    if (count == 4 || count == -4) {
        return 0;
    }
    else {
        return 1;
    }

}
int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, pri = 0;
    /*scanf("%s",input);*/
    char input[100];
    while (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        char tmp[100],tmpm[100];
        char* ret = strtok(input, "~");
        strcpy(tmp, ret);
        //printf("%s", tmp);
        char* retm = strtok(NULL, "~");
        strcpy(tmpm, retm);
        if (isIP(tmp) && isMask(tmpm)) {
            strcpy(tmp, ret);
            CountType(tmp, &a, &b, &c, &d, &e);
            strcpy(tmp, ret);
            if (isPrivate(tmp)) {
                pri++;
            }
        }
        else {
            err++;
        }
       /* int i, j;
        i = isIP(tmp);
        j = isMask(tmpm);
        printf("%d %d", i, j);*/
    }
    printf("%d %d %d %d %d %d %d", a, b, c, d, e,err,pri);
    return 0;
}
//下面是调试的时候用的
//int main()
//{
//    char input[100] = "192.168.0.2~255.255.255.0";
//    char tmp[100] = { 0 };
//    char* p = strtok(input, "~");
//    strcpy(tmp, p);
//    char* tmpm = strtok(NULL, "~");
//    //printf("%s\n", tmp);
//    int i=isIP(tmp);
//    printf("%d\n", i);
//    strcpy(tmp, input);
//    i = isPrivate(tmp);
//    printf("%d\n", i);
//    printf("%s\n", tmpm);
//    i=isMask(tmpm);
//    printf("%d\n", i);
//    int a = 0, b = 0, c = 0, d = 0, e = 0;
//    strcpy(tmp, input);
//    printf("%s\n", tmp);
//    CountType(tmp, &a, &b, &c, &d, &e);
//    printf("%d %d %d %d %d", a, b, c, d, e);
//    return 0;
//}