#include "sort.h"
//�������������������������ͨ��������������Ҫ�ϲ�������
int* merge(int* nums,int left, int mid, int right) {
	int* help = (int*)malloc(sizeof(int) * (right - left+1));
	int l = left;
	int r = mid + 1;
	int i = 0;
	while (l <= mid && r <= right) {//����������Խ��ʱ�Ƚ�
		if (nums[l] < nums[r]) {
			help[i++] = nums[l++];
			
		}
		else {
			help[i++] = nums[r++];
			
		}
	}
	//�Ƚ����˺�˭����ʣ��Ͱ�ʣ�µĸ��ƹ�ȥ
	//����whileѭ����Ȼ�ǲ���д�ģ���ʵ��ִֻ����һ��
	while (l <= mid) {
		help[i++] = nums[l++];
	}
	while (r <= right) {
		help[i++] = nums[r++];
	}
	//������õ����鿽����ȥ
	memcpy(nums+left, help, sizeof(int) * (right - left+1));//ע�⣺ÿ�β��Ǵ�ͷ��ʼ��
	free(help);
	return nums;
}
//�鲢����
int MergeSort(int* nums, int left,int right) {
	if (nums == NULL || left<0||left>right) {
		return 0;
	}
	if (left == right) {
		return nums;
	}
	int mid = left + ((right - left) >> 1);

	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);
	merge(nums,left,mid, right);

}
int mergesum(int* nums, int left, int mid, int right) {
	if (nums==NULL||left>right||left>mid||mid>right)
	{
		return 0;
	}
	int len = right - left + 1;
	int* help = (int*)malloc(len * sizeof(int));
	int l = left;
	int r = mid + 1;
	int res = 0;
	int i = 0;
	while (l <= mid && r <= right) {
		res += nums[l] < nums[r] ? (right - r+1) * nums[l] : 0;
		help[i++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
	}
	while (l <= mid) {
		help[i++] = nums[l++];
	}
	while (r <= right) {
		help[i++] = nums[r++];
	}
	memcpy(nums + left, help, len * sizeof(int));
	free(help);
	return res;
}
//С������
int Smallsum(int* nums, int left, int right) {
	if (nums == NULL || left<0 || left>right) {
		return 0;
	}
	if (left == right) {
		return 0;
	}
	int mid = left + ((right - left) >> 1);

	return	Smallsum(nums, left, mid)+
			Smallsum(nums, mid + 1, right)+
			mergesum(nums, left, mid, right);
}
void mergeReversed(int* nums, int left, int mid, int right) {
	if (nums == NULL || left > right) {
		return;
	}
	int len = right - left + 1;
	int* help = (int*)malloc(len * sizeof(int));
	int l = left;
	int r = mid + 1;
	int j = 0;
	while (l <= mid && r <= right) {
		if (nums[l] > nums[r]) {
			for (int i = l; i < mid + 1; i++) {
				printf("%d ", nums[i]);
				printf("%d\n", nums[r]);
			}
		}
		help[j++] = nums[l] <= nums[r] ? nums[l++] : nums[r++];
	}
	while (l <= mid) {
		help[j++] = nums[l++];
	}
	while (r <= right) {
		help[j++] = nums[r++];
	}
	memcpy(nums + left, help, len * sizeof(int));
	free(help);
}
//���������
void ReversedNums(int* nums, int left,int right) {
	if (nums == NULL || left >= right) {
		return;
	}
	int mid = left + ((right - left) >> 1);
	ReversedNums(nums, left, mid);
	ReversedNums(nums, mid + 1, right);
	mergeReversed(nums, left, mid, right);
}