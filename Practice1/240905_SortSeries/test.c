#include "sort.h"
int compare(const void* i, const void* j) {
	return(*(int*)i - *(int*)j);
}

int main() {
	
	int nums_maxnum = 500;
	int nums_maxsize = 10;
	int len;
	int findnum = 20;
	int flag = 0;
	//int nums[] = { 9,10,8,6,7,4,3,2,5,1 };
	//len = sizeof(nums) / sizeof(int);
	int* nums=generateRandomNums(nums_maxnum, nums_maxsize,&len);
	int* nums2 =(int*)malloc(len*sizeof(int));
	if (nums2 == NULL) {
		perror("main");
		exit(1);
	}
	memcpy(nums2, nums, len * sizeof(int));
	qsort(nums2, len, sizeof(int), compare);
	//BubbleSort(nums,len);
	SelectionSort(nums, len);
	//InsertionSort(nums, len);
	//MergeSort(nums, 0, len - 1);
	//ReversedNums(nums, 0, len - 1);
	//flag=Smallsum(nums, 0, len - 1);
	//flag = BSExistSorted(nums, len, findnum);
	//flag = FindLeftValSorted(nums, len, findnum);
	//flag=FindOneLessVal(nums, len);
	//NetherlandsFlag(nums, len, findnum);
	//QuickSort(nums, 0, len - 1);
	//HeapSort(nums, len);
	//SortArrayDistanceLessK(nums, len, 3);
	//BucketSort(nums, 0, len - 1);
	//printf("%d\n", flag);
	//if (flag!=-1) {
	//	//printf("%d存在！\n",findnum);
	//	printf("存在！\n");
	//	printf("位置%d\n", flag);
	//}
	//else
	//{
	//	//printf("%d不存在！\n",findnum);
	//	printf("不存在！\n");
	//}
	//if (memcmp(nums, nums2, len * sizeof(int)) == 0) {
	//	printf("good!\n");
	//}
	//else
	//{
	//	printf("something wrong.\n");
	//}
	printnums(nums2, len);
	printnums(nums, len);
	//free(nums);
	//nums = NULL;
	free(nums2);
	nums2 = NULL;
	return 0;
}