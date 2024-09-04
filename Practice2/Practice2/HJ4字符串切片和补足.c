#define _CRT_SECURE_NO_WARNINGS 1
//�ѵ㣺1.���㡪�����ܳ����ҳ�����Ŀ���������ռ�
//����������ĩβ��ӡ���ͨ��ָ��ֱ�Ӷ�λ
//��������ԭ�����������Ϊ�ȷ���ռ䣬�ٸ���ԭʼ�ַ����������
//2.��Ƭ����%.*s
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

void split_and_pad_string(const char* input) {
    int len = strlen(input);
    int padding_needed = 8 - (len % 8);
    if (padding_needed == 8) padding_needed = 0;

    // �����㹻���ڴ����洢ԭʼ�ַ����Ͷ����'0'
    // ��Ϊ�п��ܲ���󳬳��ٶ��ַ��������С 
    char* padded_str = (char*)malloc(len + padding_needed + 1);
    if (!padded_str) {
        perror("Failed to allocate memory");
        return;
    }
    // ������ͨ���ȸ��ƺ���ӵ�����
    //��һ�����ƵĲ���Ҳ����Ϊ������С����
    strcpy(padded_str, input); // ����ԭʼ�ַ���  
    // ���ַ���ĩβ���'0'  
    for (int i = 0; i < padding_needed; i++) {
        padded_str[len + i] = '0';
    }
    padded_str[len + padding_needed] = '\0'; // ȷ���ַ�����null��β  

    // ������Ϊ8����ַ��������  
    for (int i = 0; i < len + padding_needed; i += 8) {
        printf("%.*s\n", 8, padded_str + i); // ʹ��%.*s�����ƴ�ӡ���ַ���  
    }

    free(padded_str); // �ͷŷ�����ڴ�  
}

int main() {
    char input[101]; // ����ÿ���ַ������100���ַ�  

    printf("Enter strings (end with an empty line):\n");
    while (fgets(input, sizeof(input), stdin) && input[0] != '\n') {
        // ȥ���ַ���ĩβ�Ļ��з�������еĻ���  
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        split_and_pad_string(input);
    }

    return 0;
}