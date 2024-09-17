#include "sort.h"
int* generateRandomNums(int maxNum, int maxSize,int* resSize) {
	srand(time(NULL));
	int sz;
	//int sz = (int)maxSize * (rand() / (RAND_MAX + 1.0));//产生[0,1)的小数，再产生[0,maxSize)的整数
	//还可以直接用取模的方法rand()%maxSize，不过如果这个maxSize太大了就不行了
	//改进上面的方法
	if (maxSize > RAND_MAX) {
		sz = (int)(maxSize * (rand() / (RAND_MAX + 1.0))+1);
	}
	else {
		sz = rand() % maxSize+1;
	}
	int* nums = (int*)malloc(sz*sizeof(int));
	if (nums == NULL) {
		printf("产生随机数组时扩展内存失败！");
		exit(1);
	}
	for (int i = 0; i < sz; i++) {
		//srand(time(NULL));
		nums[i] = (int)maxNum * (rand() / (RAND_MAX + 1.0));
	}
	*resSize = sz;
	return nums;
}