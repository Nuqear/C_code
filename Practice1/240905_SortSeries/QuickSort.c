#include "sort.h"
void partition(int* nums, int left, int right,int* res) {
	int less = left - 1;
	int more = right;//����ע����Ϊѡ�����һ������num������more�Ľڵ㲻����right+1��������ѭ��
	
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
	res[0]=less;//ע������less����û�з����仯��Ҳ���ǿ���Ϊ-1
	res[1] = more;
	
}
int QuickSort(int* nums, int left,int right) {
	if (left >= right) {//left>right���жϱز����٣���Ϊ�Ҷ˵����Ϊ����
		return;
	}
	swap(nums, right, left + (rand() % (right - left)));
	int* help = (int*)malloc(2 * sizeof(int));
	partition(nums, left, right,help);
	QuickSort(nums, left, help[0]);
	QuickSort(nums, help[1]+1, right);//�����1�ǰ�����õ��Ǹ�����ȥ
	free(help);
	return 1;
}
