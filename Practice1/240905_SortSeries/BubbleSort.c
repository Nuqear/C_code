#include "sort.h"

int BubbleSort(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 2) {
		return 0;
	}
	for (int i = 0; i < numsSize; i++) {
		for (int j = 0; j < numsSize-1 -i; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums, j,  j+ 1);
			}
		}
	}
	return 1;
}