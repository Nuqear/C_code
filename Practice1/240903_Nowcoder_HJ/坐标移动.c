#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "stdio.h"
#include "string.h"

int isValid(char* cmd, int* num)

{
    if (strlen(cmd) < 2) return 0;

    if (*cmd != 'W' && *cmd != 'S' && *cmd != 'A' && *cmd != 'D') return 0;
    int tmp = atoi(cmd + 1);
    if (tmp <= 0 || tmp > 99) return 0;
    *num = tmp;
    return 1;
}
void UpdatePos(char* cmd, int num, int* x, int* y)
{
    switch (*cmd) {
    case 'A':*x -= num; break;
    case 'D':*x += num; break;
    case 'S':*y -= num; break;
    case 'W':*y += num; break;
    }
}
int main()
{
    char input[10001];
    int x = 0, y = 0;
    gets_s(input);
    char* p = NULL;
    for (p = strtok(input, ";"); p != NULL; p = strtok(NULL, ";")) {
        int num = 0;
        if (isValid(p, &num)) {
            UpdatePos(p, num, &x, &y);
        }
    }
    printf("%d,%d", x, y);
    return 0;
}