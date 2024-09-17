#include "sort.h"
//���ַ��ж�һ�����������������Ƿ����
int BSExistSorted(int* nums, int numsSize,int num) {
	if (nums == NULL || numsSize < 1) {
		printf("\"���ַ��ж�һ�����������������Ƿ����\"���벻�Ϸ���\n");
		return 0;
	}
	int left = 0, right = numsSize - 1;
	int mid = 0;
	while (left <= right && left <= numsSize - 1 && right >= 0) {//������ֹ�����Ƿָ��ĳ���Ϊ1����Ȼû�ҵ�
		//֮���Զ����һ�����ں�����Ϊmid+1����mid-1��ֵ��û���ж�
		mid = left + ((right - left) >> 1);//left+((right-left)/2)�ļ�����д����Ҳ��Ϊ��λ�����ٶȸ��졣
		if (nums[mid] == num) {
			return 1;
		}
		else if (nums[mid] > num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return nums[left] == num;//������˵�д����������
}

//���ַ�Ѱ��һ�����ں����ظ�Ԫ�ص����������е�����λ��
int FindLeftValSorted(int* nums, int numsSize, int num) {
	if (nums == NULL || numsSize < 1) {
		printf("\"Ѱ������λ��\"���벻�Ϸ���\n");
		return -1;
	}
	int left = 0, right = numsSize - 1;
	int mid = 0;
	int index=-1;//�Ҿ���Ӧ���ǳ�ʶ������
	while (left <= right&&left<=numsSize-1&&right>=0) {
		mid = left + ((right - left) >> 1);
		if (nums[mid] >= num) {
			index = mid;//��Ƿ��������Ķ˵㣬ͬʱҲ��Ϊmid<=right�������൱������������
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}
	return index;
}

//�ֲ���С����
int FindOneLessVal(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		printf("\"Ѱ�Ҿֲ���С����\"���벻�Ϸ���\n");
		return -1;
	}
	int left = 0, right = numsSize - 1;
	if (nums[left] < nums[left + 1]) {
		return left;
	}
	else if (nums[right] < nums[right - 1]) {
		return right;
	}
	int mid = 0;
	/*int index = -1;*/
	while (left < right) {//ǰ�����ж��ˣ����Կ��Բ���
		mid = left + ((right - left) >> 1);
		if (nums[mid]>nums[mid-1]) {
			right = mid - 1;
		}
		else if(nums[mid]>nums[mid+1]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	
}