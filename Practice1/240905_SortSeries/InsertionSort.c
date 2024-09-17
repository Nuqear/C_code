#include "sort.h"
int InsertionSort(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 2) {
		return 0;
	}
	for (int i = 0; i < numsSize; i++) {//从左往右不断扩展区域
		for (int j = i - 1; j >= 0; j--) {//区域内部比较，做到有序
			if (nums[j] > nums[j+1]) {//这里不能偷懒写i，必须是j+1
				swap(nums, j, j+1);
			}
		}
	}
	return 1;
}