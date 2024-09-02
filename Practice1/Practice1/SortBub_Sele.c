#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> // 包含 malloc 和 free 的声明
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 交换 arr[i] 和 arr[minIndex]
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//int main() {
//    int n;
//
//    printf("请输入数组的大小: ");
//    scanf("%d", &n);
//
//    // 动态分配内存
//    int* arr = (int*)malloc(n * sizeof(int));
//
//    if (arr == NULL) {
//        printf("内存分配失败!\n");
//        return 1; // 返回非0表示失败
//    }
//
//    printf("请输入数组元素:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // 冒泡排序
//    printf("排序前数组 (冒泡排序): \n");
//    printArray(arr, n);
//
//    bubbleSort(arr, n);
//
//    printf("排序后数组 (冒泡排序): \n");
//    printArray(arr, n);
//
//    // 选择排序
//    // 需要重置数组
//    printf("请重新输入数组元素以进行选择排序:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    printf("排序前数组 (选择排序): \n");
//    printArray(arr, n);
//
//    selectionSort(arr, n);
//
//    printf("排序后数组 (选择排序): \n");
//    printArray(arr, n);
//
//    // 释放动态分配的内存
//    free(arr);
//
//    return 0;
//}
//怎么确定任意数字个数？1.请求用户输入元素个数
//动态内存分配：使用malloc函数来分配数组的内存。确保在程序结束后使用free释放已分配的内存，以防内存泄漏。
// 内存大小通过n*sizeof(int)来分配。每次分配后都应该检查
//内存分配检查：在分配内存后检查返回的指针是否为NULL，如果是则表示内存分配失败，程序将返回错误代码。
//2.自动确定数组大小
int main() {
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败！\n");
        return 1;//结束程序，返回非0，程序失败
    }

    int n = 0;
    printf("请输入数组元素（输入非数字结束）：\n");
    while (n<size)//因为控制输入，所以条件是这样
    {
        int input;
        if (scanf("%d", &input) != 1)//成功输入返回数据个数，也就是1；不成功返回EOF，是一个负整数
            break;//输入非数字，退出循环，取消向数组存储
        arr[n++] = input;//美妙的表达，先将input的值赋给arr[n]，再增加1
        //增加1后再判断是因为数组索引要小1
        //如果数组已满，扩展数组
        if (n == size) {
            size += 10;
            arr = (int*)realloc(arr, size * sizeof(int));
            //扩展数组后记得判断是否失败
            if (arr == NULL) {
                printf("内存扩展失败！\n");
                return 1;//结束程序，返回非0，程序失败
            }
        }
    }
    // 冒泡排序
    printf("排序前数组 (冒泡排序): \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("排序后数组 (冒泡排序): \n");
    printArray(arr, n);
    free(arr);
    return 0;
}
//###代码修改点：
//1.初始分配的数组大小设定为10，并使用`malloc分配内存。
//2.在用户输入期间，持续检查输入，直到用户输入非数字后才停止。scanf的应用
//3.动态调整数组大小，使用`realloc扩展数组以便接收更多元素。设立了一个表示数组大小的变量size
//4.提供了排序前和排序后的数组输出功能，无需在开始时询问数组大小。