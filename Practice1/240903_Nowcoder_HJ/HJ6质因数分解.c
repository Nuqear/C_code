#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
//难点：质因数——假定所有i<=n都是因数，再通过条件判断（1）是因数（2）是质数
// 所有质因数——找到后剔除
// 重复输出因数——while(n%i==0)
// 改进：在这个特定的质因子分解问题中，我们其实不需要显式地检查每个因子是否
// 为质数，因为当我们从2开始递增地检查n的因子时，能够整除n的数自动就是n的质
// 因子或质因子的乘积。
// 函数声明，用于判断是否为质数
// 扩展：重复质因数输出一次——把所有质因数求出后再去重，由于数组已经按大小
// 排列，所以直接选择之前的去重方法。

int isPrime(int num);

int main() {
    int n, i;
    scanf("%d", &n);

    // 遍历从2到n
    for (i = 2; i <= n; i++) {
        // 如果i是n的因子，并且是质数  
        while (n % i == 0 && isPrime(i)) {
            printf("%d ", i);
            n = n / i; // 移除这个质因子，继续寻找下一个  
        }
        // 如果n已经变为1，则不需要继续循环  
        if (n == 1) break;
    }


    return 0;
}

// 判断是否为质数的函数  
int isPrime(int num) {
    if (num <= 1) return 0; // 小于等于1的数不是质数  
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // 如果能被除了1和它本身以外的数整除，则不是质数  
    }
    return 1; // 是质数  
}
////改进代码
//// 函数声明，用于输出n的所有质因子（包括重复的）  
//void printPrimeFactors(int n);
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    // 输出n的所有质因子  
//    printPrimeFactors(n);
//
//    return 0;
//}
//
//// 输出n的所有质因子的函数  
//void printPrimeFactors(int n) {
//
//    // 遍历从2到sqrt(n)的整数  
//    for (int i = 2; i <= sqrt(n); i++) {
//        // 如果i是n的因子  
//        while (n % i == 0) {
//            printf("%d ", i); // 输出质因子i  
//            n = n / i; // 移除这个质因子，继续寻找下一个  
//        }
//    }
//
//    // 如果n此时大于1，说明n是一个质数  
//    if (n > 1) {
//        printf("%d ", n); // 输出最后的质因子（n自身）  
//    }
//}