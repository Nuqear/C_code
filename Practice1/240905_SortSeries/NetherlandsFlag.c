#include "sort.h"
int NetherlandsFlag(int* nums, int numsSize,int num) {
	int i = 0;
	int less = -1;
	while(i < numsSize) {
		if (nums[i] <= num) {
			swap(nums, ++less, i++);
		}
		else
		{
			i++;
		}
		//nums[i]<=num?swap(nums,less++,i++):i++;
	}
	return 1;
	
}