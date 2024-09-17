#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>

//int main() {
//    char str[21];
//    scanf("%s", str);
//    int len = strlen(str);
//    int cou[255] = { 0 };
//    //统计所有字符串的出现次数
//    for (int i = 0; i < len; i++) {
//        cou[(int)str[i]]++;
//    }
//    int min = 20;
//    //先假设最小次数为20，在找出最小出现次数
//    for (int i = 0; i < 255; i++) {
//        if (cou[i] < min && cou[i]>0) {
//            min = cou[i];
//        }
//    }
//    //如果不为最小次数，复制到目标数组
//    char res[21] = { 0 };
//    int resIndex = 0;
//    for (int i = 0; i < len; i++) {
//        if (cou[str[i]] != min) {
//            res[resIndex++] = str[i];
//        }
//    }
//    //res[resIndex] = '\0';//末尾加上0，虽然这里似乎不需要
//    printf("%s", res);
//    return 0;
//}
/*test(char* strh)
{
	char des[10]="hahah";
	for (int i = 0; i < 10; i++)
	{
		strh[i] = des[i];
	}

}
int main()
{
	char str[10],des[10];
	gets(str);
	test(str);
	printf("%s", str);
	return 0;
}*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1.由于非英文字母保持原来位置，显然需要另一个数组来记录这个位置索引
//最简单的做法是直接复制一份。
//2.先将所有非英文字符拿出来，然后记录字母出现次数
//3.将次数大于1的字母输出到另一个字符数组
//4.将所有字母从小到大排列
//5.调整次数大于1的字母的顺序
//6.插入非字母字符
#define LEN 10001
char* CutNotAlpha(char* str)
{
    int len = strlen(str);
    char des[LEN] = { 0 };
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (!(str[i] >= 'a' || str[i] <= 'z' || str[i] >= 'A' || str[i] <= 'Z')) {
            des[index++] = str[i];
        }
    }
    for (int i = 0; i < len; i++) {
        str[i] = des[i];
    }
    return str;
}
int CountAlpha(char* str, int* num)
{

    while (*str) {
        num[*str]++;
        str++;
    }
}
void PutAlphaPlus(char* str, char* des, int* num)
{
    int index = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (num[(int)str[i]] > 1) {
            des[index++] = str[i];
        }
    }

}
void ResetAlphaPlus(char* des, char* src)
{
    for (int j = 0; j < strlen(des); j++) {
        for (int i = 0; i < strlen(src); i++) {
            while (tolower(des[j]) == tolower(src[i])) {
                des[j] = src[i];
                des++;
                src++;
            }

        }
    }
}
void InsertNotAlpha(char* des, char* src)
{
    for (int j = 0; j < strlen(des); j++) {
        for (int i = 0; i < strlen(src); i++) {
            if (tolower(*src) >= 'a' && tolower(*src) <= 'z') {
                src[i] = des[j];
                i++;
                j++;
            }
        }
    }
}
int compare(const void* a, const void* b)
{
    int s = tolower(*(char*)a) - tolower(*(char*)b);
    return s;
}
int main() {
    char str[LEN];
    char notalpha[LEN], AlphaPlus[LEN] = { 0 };

    int num[256];
    gets(str);
    strcpy(notalpha, str);
    CutNotAlpha(str);
    CountAlpha(str, num);
    PutAlphaPlus(str, AlphaPlus, num);
    int len = strlen(str);
    qsort(str, len, sizeof(char), compare);
    ResetAlphaPlus(str, AlphaPlus);
    InsertNotAlpha(str, notalpha);
    while (*str != '\0') {
        printf("%c", (*str)++);
    }
    printf("\n");
    return 0;
}