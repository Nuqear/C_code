#include "sort.h"
int InsertionSort(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 2) {
		return 0;
	}
	for (int i = 0; i < numsSize; i++) {//�������Ҳ�����չ����
		for (int j = i - 1; j >= 0; j--) {//�����ڲ��Ƚϣ���������
			if (nums[j] > nums[j+1]) {//���ﲻ��͵��дi��������j+1
				swap(nums, j, j+1);
			}
		}
	}
	return 1;
}