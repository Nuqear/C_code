#include "sort.h"
void heapInsert(int* nums, int index) {
	while (nums[index] > nums[(index - 1) / 2]) {
		swap(nums, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void heapify(int* nums, int index,int heapsize) {
	int left = 2 * index + 1;//先计算是为了判断有没有越界
	while (left < heapsize) {
		int largest = left + 1 < heapsize && nums[left + 1] > nums[left] ? left + 1 : left;//等于右节点的情况限制严格
		largest = nums[index] > nums[largest] ? index : largest;
		if (largest==index)
		{
			break;
		}
		swap(nums, index, largest);
		index = largest;
		left= 2 * index + 1;//不要忘了计算左节点
	}
}
int HeapSort(int* nums, int numsSize) {
	if (numsSize<=0)
	{
		return 0;
	}
	//for (int i = 0; i < numsSize; i++) {
	//	heapInsert(nums, i);//视作从0开始一个个加入数字
	//}
	for (int i = numsSize / 2; i >= 0; i--) {
		heapify(nums, i, numsSize);//更快的方式
	}
	int heapsize = numsSize;
	while (heapsize > 0) {
		swap(nums, 0, --heapsize);
		heapify(nums,0,heapsize);
	}
	return 1;
}

void SortArrayDistanceLessK(int* nums, int numsSize, int k) {
	if (numsSize <= 0) {
		return;
	}
	int heapsize = k + 1 < numsSize ? k + 1 : numsSize;
	for (int j = 0; j < numsSize-heapsize; j++)
	{
		for (int i = 0; i < heapsize; i++) {
			heapInsert(nums, j+i);
		}
	}
	
}