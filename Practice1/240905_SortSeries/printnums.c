#include "sort.h"
void printnums(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		printf("��ӡ������Ϊ�գ�");
		exit(1);
	}
	int i = 0, j;
	while (i < numsSize) {
		for (j = 0; j < 10; j++) {
			if (i < numsSize) {
				printf("%-6d", nums[i++]);
			}
			else {
				break;
			}
		}
		printf("\n");
	}
}