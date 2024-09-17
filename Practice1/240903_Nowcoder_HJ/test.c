#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isIP(char* str) {
    char* p = strtok(str, ".");
    if (strlen(p) > 3) {
        return 0;
    }
    char* end;
    int num = strtol(p, &end, 0);
    if (*end != '\0') {
        return 0;
    }
    if (num < 0 || num>255) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        p = strtok(NULL, ".");
        num = strtol(p, &end, 0);
        if (strlen(p) > 3 || *end != '\0' || num < 0 || num>255 || p == NULL) {
            return 0;
        }
    }
    return 1;
}
int isMask(char* str) {
    if (strcmp(str, "255.0.0.0") == 0) {
        return 1;
    }
    else if (strcmp(str, "255.255.0.0") == 0) {
        return 1;
    }
    else if (strcmp(str, "255.255.255.0") == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int issamesubweb(char* mask, char* ip1, char* ip2) {
    char* p = strtok(mask, ".");
    int count = 0;
    if (strcmp(p, "255") == 0) {
        count++;
    }
    for (int i = 0; i < 3; i++) {
        p = strtok(NULL, ".");
        if (strcmp(p, "255") == 0) {
            count++;
        }
    }

    int i = 0;
    while (count) {
        if (ip1[i] != ip2[i]) {
            return 0;
        }
        if (ip1[i] == '\0') {
            count--;
        }
        i++;
    }
    return 1;

}
int main() {
    char mask[20], ip[2][20];
    scanf("%s%s%s", mask, ip[0], ip[1]);
    if (isMask(mask) && isIP(ip[0]) && isIP(ip[1])) {
        if (issamesubweb(mask, ip[0], ip[1])) {
            printf("0");
            return 0;
        }
        else {
            printf("2");
            return 0;
        }
    }
    printf("1");
    return 0;

}

////下面的代码体现了指针的类型决定了指针的运算
////#include <string.h>
////#include <stdio.h>
////typedef struct se
////{
////	char name[5];
////	int num;
////	char add[5];
////}se;
////int main()
////{
////	se data[3] = { {"haha",1,"like"},{"hehe",2,"love"} };
////	se* p = (se*)data[0].add;
////	printf("%s\n", p);
////	p++;
////	printf("%s\n", p);
////	int i = memcmp(p, "love", 5);
////	printf("%d", i);
////	return 0;
////}
