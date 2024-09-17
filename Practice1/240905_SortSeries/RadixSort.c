#include "sort.h"
//��ȡ����Ԫ��λ�����ֵ
int GetHighestDigit(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		return;
	}
	int max = nums[0];
	int count=0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	do
	{
		max = max / 10;
		count++;
	} while (max);
	return count;
}

void RadixSort(int* nums, int left, int right, int digit) {
	if (left >= right) {
		return;
	}
	
	int* help = (int*)malloc((right - left + 1) * sizeof(int));
	int i, j;
	for (i = 0; i < digit; i++) {
		int count[RADIX] = { 0 };
		int last;
		for (j = left; j < right + 1; j++) {//��Ƶͳ��
			last = (nums[j]/(int)pow(10,i)) % RADIX;
			count[last]++;
		}
		for (j = 1; j < RADIX; j++)//ǰ׺��
		{
			count[j] = count[j] + count[j - 1];
		}
		for (j = right; j >= left; j--) {//�����������
			last = (nums[j] / (int)pow(10, i)) % RADIX;
			help[--count[last]] = nums[j];
		}
		memcpy(nums, help, (right - left + 1) * sizeof(int));
	}
	free(help);
}
int BucketSort(int* nums, int left,int right) {
	int d = GetHighestDigit(nums, (right-left+1));
	RadixSort(nums, left, right, d);
}

