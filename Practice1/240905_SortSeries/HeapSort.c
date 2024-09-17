#include "sort.h"
void heapInsert(int* nums, int index) {
	while (nums[index] > nums[(index - 1) / 2]) {
		swap(nums, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void heapify(int* nums, int index,int heapsize) {
	int left = 2 * index + 1;//�ȼ�����Ϊ���ж���û��Խ��
	while (left < heapsize) {
		int largest = left + 1 < heapsize && nums[left + 1] > nums[left] ? left + 1 : left;//�����ҽڵ����������ϸ�
		largest = nums[index] > nums[largest] ? index : largest;
		if (largest==index)
		{
			break;
		}
		swap(nums, index, largest);
		index = largest;
		left= 2 * index + 1;//��Ҫ���˼�����ڵ�
	}
}
int HeapSort(int* nums, int numsSize) {
	if (numsSize<=0)
	{
		return 0;
	}
	//for (int i = 0; i < numsSize; i++) {
	//	heapInsert(nums, i);//������0��ʼһ������������
	//}
	for (int i = numsSize / 2; i >= 0; i--) {
		heapify(nums, i, numsSize);//����ķ�ʽ
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