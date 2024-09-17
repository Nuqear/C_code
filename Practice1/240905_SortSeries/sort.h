#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


//������������
void swap(int* arr, int i, int j);
//�����������
int* generateRandomNums(int maxNum,int maxSize,int* resSize);
//��ӡ����
void printnums(int* nums, int numsSize);
//ð����������
int BubbleSort(int* nums,int numsSize);
//ѡ������
int SelectionSort(int* nums, int numsSize);
//��������
int InsertionSort(int* nums, int numsSize);
//���ַ��ж�һ�����������������Ƿ����
int BSExistSorted(int* nums, int numsSize, int num);
//Ѱ������λ��
int FindLeftValSorted(int* nums, int numsSize, int num);
//�ֲ���С����
int FindOneLessVal(int* nums, int numsSize);
//�鲢����
int MergeSort(int* nums, int left, int right);
int* merge(int* nums, int left, int mid, int right);
//С������
int Smallsum(int* nums, int left, int right);
int mergesum(int* nums, int left, int mid, int right);
//���������
void ReversedNums(int* nums, int left, int right);
//������������
int NetherlandsFlag(int* nums, int numsSize, int num);
//��������
int QuickSort(int* nums, int left, int right);
void partition(int* nums, int left, int right,int* res);
//������
int HeapSort(int* nums, int numsSize);
void heapInsert(int* nums, int index);
void heapify(int* nums, int index, int heapsize);
void SortArrayDistanceLessK(int* nums, int numsSize, int k);
//Ͱ����
#define RADIX 10
int BucketSort(int* nums, int left, int right);