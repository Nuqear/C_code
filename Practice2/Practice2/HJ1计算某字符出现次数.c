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
#include <ctype.h> // ����tolower����  

int main() {
    char str[1001]; // ������Ŀ���ݷ�Χ���ַ����������Ϊ1000����1Ϊ�˴���ַ���������'\0'  
    char ch;
    int count = 0;
    int i;

    // ��ȡ�ַ���  
    fgets(str, sizeof(str), stdin);
    // fgets���ȡ���з�������ַ���ĩβ�л��з�����ȥ��  
    str[strcspn(str, "\n")] = 0;
    // strcspn()�����ַ��� str1 ��ͷ�����м����ַ��������ַ��� str2 �е��ַ���
    // ���� str1 ��ͷ�����������ַ��� str2 ���ַ����ַ���
    // ��ȡһ���ַ�  
    scanf(" %c", &ch); // ע��%cǰ�Ŀո����������κ�֮ǰ�Ļ��з�  

    // �����ַ����������ַ����ִ���  
    for (i = 0; str[i] != '\0'; i++) {
        // ʹ��tolower�������Դ�Сд  
        if (tolower(str[i]) == tolower(ch)) {
            count++;
        }
    }

    // ������  
    printf("%d\n", count);

    return 0;
}