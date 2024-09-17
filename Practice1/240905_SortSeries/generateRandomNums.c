#include "sort.h"
int* generateRandomNums(int maxNum, int maxSize,int* resSize) {
	srand(time(NULL));
	int sz;
	//int sz = (int)maxSize * (rand() / (RAND_MAX + 1.0));//����[0,1)��С�����ٲ���[0,maxSize)������
	//������ֱ����ȡģ�ķ���rand()%maxSize������������maxSize̫���˾Ͳ�����
	//�Ľ�����ķ���
	if (maxSize > RAND_MAX) {
		sz = (int)(maxSize * (rand() / (RAND_MAX + 1.0))+1);
	}
	else {
		sz = rand() % maxSize+1;
	}
	int* nums = (int*)malloc(sz*sizeof(int));
	if (nums == NULL) {
		printf("�����������ʱ��չ�ڴ�ʧ�ܣ�");
		exit(1);
	}
	for (int i = 0; i < sz; i++) {
		//srand(time(NULL));
		nums[i] = (int)maxNum * (rand() / (RAND_MAX + 1.0));
	}
	*resSize = sz;
	return nums;
}