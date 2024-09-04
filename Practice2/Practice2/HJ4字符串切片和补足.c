#define _CRT_SECURE_NO_WARNINGS 1
//难点：1.补足——可能超出且超出数目随机：分配空间
//“补”，在末尾添加——通过指针直接定位
//上述两个原因决定了流程为先分配空间，再复制原始字符串，再添加
//2.切片——%.*s
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

void split_and_pad_string(const char* input) {
    int len = strlen(input);
    int padding_needed = 8 - (len % 8);
    if (padding_needed == 8) padding_needed = 0;

    // 分配足够的内存来存储原始字符串和额外的'0'
    // 因为有可能补足后超出假定字符串数组大小 
    char* padded_str = (char*)malloc(len + padding_needed + 1);
    if (!padded_str) {
        perror("Failed to allocate memory");
        return;
    }
    // 补足是通过先复制后添加到操作
    //多一步复制的操作也是因为补足后大小不定
    strcpy(padded_str, input); // 复制原始字符串  
    // 在字符串末尾添加'0'  
    for (int i = 0; i < padding_needed; i++) {
        padded_str[len + i] = '0';
    }
    padded_str[len + padding_needed] = '\0'; // 确保字符串以null结尾  

    // 按长度为8拆分字符串并输出  
    for (int i = 0; i < len + padding_needed; i += 8) {
        printf("%.*s\n", 8, padded_str + i); // 使用%.*s来限制打印的字符数  
    }

    free(padded_str); // 释放分配的内存  
}

int main() {
    char input[101]; // 假设每个字符串最多100个字符  

    printf("Enter strings (end with an empty line):\n");
    while (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
        // 去除字符串末尾的换行符（如果有的话）  
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        split_and_pad_string(input);
    }

    return 0;
}