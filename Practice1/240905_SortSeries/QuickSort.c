#include "sort.h"
void partition(int* nums, int left, int right,int* res) {
	int less = left - 1;
	int more = right;//这里注意因为选择最后一个数作num，所以more的节点不能是right+1，否则死循环
	
	while (left < more) {
		if (nums[left] < nums[right]) {
			swap(nums, left++, ++less);
		}
		else if(nums[left]==nums[right])
		{
			left++;
		}
		else
		{
			swap(nums, left, --more);
		}
	}
	swap(nums, right, more);
	res[0]=less;//注意这里less可能没有发生变化，也就是可能为-1
	res[1] = more;
	
}
int QuickSort(int* nums, int left,int right) {
	if (left >= right) {//left>right的判断必不可少，因为右端点可能为负数
		return;
	}
	swap(nums, right, left + (rand() % (right - left)));
	int* help = (int*)malloc(2 * sizeof(int));
	partition(nums, left, right,help);
	QuickSort(nums, left, help[0]);
	QuickSort(nums, help[1]+1, right);//这里加1是把排序好的那个数除去
	free(help);
	return 1;
}
