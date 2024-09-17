#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


//交换函数声明
void swap(int* arr, int i, int j);
//生成随机数组
int* generateRandomNums(int maxNum,int maxSize,int* resSize);
//打印数组
void printnums(int* nums, int numsSize);
//冒泡排序声明
int BubbleSort(int* nums,int numsSize);
//选择排序
int SelectionSort(int* nums, int numsSize);
//插入排序
int InsertionSort(int* nums, int numsSize);
//二分法判断一个数在有序数组中是否存在
int BSExistSorted(int* nums, int numsSize, int num);
//寻找最左位置
int FindLeftValSorted(int* nums, int numsSize, int num);
//局部最小问题
int FindOneLessVal(int* nums, int numsSize);
//归并排序
int MergeSort(int* nums, int left, int right);
int* merge(int* nums, int left, int mid, int right);
//小和问题
int Smallsum(int* nums, int left, int right);
int mergesum(int* nums, int left, int mid, int right);
//逆序对问题
void ReversedNums(int* nums, int left, int right);
//荷兰国旗问题
int NetherlandsFlag(int* nums, int numsSize, int num);
//快速排序
int QuickSort(int* nums, int left, int right);
void partition(int* nums, int left, int right,int* res);
//堆排序
int HeapSort(int* nums, int numsSize);
void heapInsert(int* nums, int index);
void heapify(int* nums, int index, int heapsize);
void SortArrayDistanceLessK(int* nums, int numsSize, int k);
//桶排序
#define RADIX 10
int BucketSort(int* nums, int left, int right);