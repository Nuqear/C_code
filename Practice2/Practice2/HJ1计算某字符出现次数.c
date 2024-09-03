#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//int main() {
//    char str[1000];
//    char a;
//    int i, num=0;
//    gets(str);
//    a = getchar();
//    for (i = 0; i < strlen(str); i++) {
//        if ((a == str[i]) || (a >= 'a' && a <= 'z' && a == str[i] + 32) || (a >= 'A' && a <= 'Z' && a == str[i] - 32)) {
//            num++;
//        }
//    }
//    printf("%d", num);
//    return 0;
//}

#include <stdio.h>  
#include <string.h>  
#include <ctype.h> // 用于tolower函数  

int main() {
    char str[1001]; // 根据题目数据范围，字符串长度最大为1000，加1为了存放字符串结束符'\0'  
    char ch;
    int count = 0;
    int i;

    // 读取字符串  
    fgets(str, sizeof(str), stdin);
    // fgets会读取换行符，如果字符串末尾有换行符，则去除  
    str[strcspn(str, "\n")] = 0;
    // strcspn()检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符。
    // 返回 str1 开头连续都不含字符串 str2 中字符的字符数
    // 读取一个字符  
    scanf(" %c", &ch); // 注意%c前的空格，用于跳过任何之前的换行符  

    // 遍历字符串，计算字符出现次数  
    for (i = 0; str[i] != '\0'; i++) {
        // 使用tolower函数忽略大小写  
        if (tolower(str[i]) == tolower(ch)) {
            count++;
        }
    }

    // 输出结果  
    printf("%d\n", count);

    return 0;
}