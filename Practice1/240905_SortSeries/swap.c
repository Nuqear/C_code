#include "sort.h"

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	//arr[i] = arr[i] ^ arr[j];
	//arr[j] = arr[i] ^ arr[j];
	//arr[i] = arr[i] ^ arr[j];
}
