#include "sort.h"
//二分法判断一个数在有序数组中是否存在
int BSExistSorted(int* nums, int numsSize,int num) {
	if (nums == NULL || numsSize < 1) {
		printf("\"二分法判断一个数在有序数组中是否存在\"输入不合法！\n");
		return 0;
	}
	int left = 0, right = numsSize - 1;
	int mid = 0;
	while (left <= right && left <= numsSize - 1 && right >= 0) {//极端终止条件是分割后的长度为1，仍然没找到
		//之所以多加了一个等于号是因为mid+1或者mid-1的值还没有判断
		mid = left + ((right - left) >> 1);//left+((right-left)/2)的技巧性写法，也因为移位运算速度更快。
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
	return nums[left] == num;//简洁明了的写法，厉害！
}

//二分法寻找一个数在含有重复元素的有序数组中的最左位置
int FindLeftValSorted(int* nums, int numsSize, int num) {
	if (nums == NULL || numsSize < 1) {
		printf("\"寻找最左位置\"输入不合法！\n");
		return -1;
	}
	int left = 0, right = numsSize - 1;
	int mid = 0;
	int index=-1;//我觉得应该是常识性内容
	while (left <= right&&left<=numsSize-1&&right>=0) {
		mid = left + ((right - left) >> 1);
		if (nums[mid] >= num) {
			index = mid;//标记符合条件的端点，同时也因为mid<=right，所以相当于有两个功能
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}
	return index;
}

//局部最小问题
int FindOneLessVal(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		printf("\"寻找局部最小问题\"输入不合法！\n");
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
	while (left < right) {//前面有判断了，所以可以不用
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