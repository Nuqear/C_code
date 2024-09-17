#include "sort.h"
int SelectionSort(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 2) {
		return 0;
	}
	for (int i = 0; i < numsSize; i++) {
		int minIndex = i;
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[minIndex] > nums[j]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(nums, minIndex, i);
		}
	}
}