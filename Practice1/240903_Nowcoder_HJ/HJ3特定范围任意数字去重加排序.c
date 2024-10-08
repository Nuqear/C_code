#define _CRT_SECURE_NO_WARNINGS 1
//描述：明明生成了N个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。
//数据范围： 1≤n≤1000，输入的数字大小满足 1≤val≤500
//输入描述：第一行先输入随机整数的个数 N 。 接下来的 N 行每行输入一个整数，代表明明生成的随机数。
//难点：1.去重——利用数组自带的下标记录出现次数或者bool判断
//2.排序——巧妙的方法是利用数组下标根据出现次数模拟排序，值得注意的是因为数组长度有限，所以只适合特定范围数字
//另一种方法：先排序再输出和上一个数组元素不同的元素
#include <stdio.h>  
#include <stdbool.h>  

int main() {
    int N;
    scanf("%d", &N);

    // 使用布尔数组记录数字是否出现过  
    bool seen[501] = { false };

    // 读取所有数字并标记出现过的数字  
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (num >= 1 && num <= 500) {
            seen[num] = true;
        }
    }

    // 遍历布尔数组，输出那些出现过的数字（模拟了排序的过程，因为数组下标是有序的）  
    for (int i = 1; i <= 500; i++) {
        if (seen[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
//在这段代码中，我们首先读取了整数N，并创建了一个大小为501的布尔数组seen，
// 用于记录每个数字（1到500）是否出现过。然后，我们读取了N个整数，并标记了
// 出现过的数字。最后，我们遍历seen数组，对于每一个出现过的数字（即seen[i]
// 为true的情况），我们输出这个数字。由于我们是按照数字的顺序（即数组的下标）
// 来遍历的，所以输出的数字自然就是从小到大排序的。