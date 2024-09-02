#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> // ���� malloc �� free ������
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ���� arr[i] �� arr[minIndex]
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//int main() {
//    int n;
//
//    printf("����������Ĵ�С: ");
//    scanf("%d", &n);
//
//    // ��̬�����ڴ�
//    int* arr = (int*)malloc(n * sizeof(int));
//
//    if (arr == NULL) {
//        printf("�ڴ����ʧ��!\n");
//        return 1; // ���ط�0��ʾʧ��
//    }
//
//    printf("����������Ԫ��:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // ð������
//    printf("����ǰ���� (ð������): \n");
//    printArray(arr, n);
//
//    bubbleSort(arr, n);
//
//    printf("��������� (ð������): \n");
//    printArray(arr, n);
//
//    // ѡ������
//    // ��Ҫ��������
//    printf("��������������Ԫ���Խ���ѡ������:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    printf("����ǰ���� (ѡ������): \n");
//    printArray(arr, n);
//
//    selectionSort(arr, n);
//
//    printf("��������� (ѡ������): \n");
//    printArray(arr, n);
//
//    // �ͷŶ�̬������ڴ�
//    free(arr);
//
//    return 0;
//}
//��ôȷ���������ָ�����1.�����û�����Ԫ�ظ���
//��̬�ڴ���䣺ʹ��malloc����������������ڴ档ȷ���ڳ��������ʹ��free�ͷ��ѷ�����ڴ棬�Է��ڴ�й©��
// �ڴ��Сͨ��n*sizeof(int)������
//�ڴ�����飺�ڷ����ڴ���鷵�ص�ָ���Ƿ�ΪNULL����������ʾ�ڴ����ʧ�ܣ����򽫷��ش�����롣
//2.�Զ�ȷ�������С
int main() {
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return 1;//�������򣬷��ط�0������ʧ��
    }

    int n = 0;
    printf("����������Ԫ�أ���������ֽ�������\n");
    while (n<size)//��Ϊ�������룬��������������
    {
        int input;
        if (scanf("%d", &input) != 1)//�ɹ����뷵�����ݸ�����Ҳ����1�����ɹ�����EOF����һ��������
            break;//��������֣��˳�ѭ����ȡ��������洢
        arr[n++] = input;//����ı��Ƚ�input��ֵ����arr[n]��������1
        //����1�����ж�����Ϊ��������ҪС1
        //���������������չ����
        if (n == size) {
            size += 10;
            arr = (int*)realloc(arr, size * sizeof(int));
            //��չ�����ǵ��ж��Ƿ�ʧ��
            if (arr == NULL) {
                printf("�ڴ���չʧ�ܣ�\n");
                return 1;//�������򣬷��ط�0������ʧ��
            }
        }
    }
    // ð������
    printf("����ǰ���� (ð������): \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("��������� (ð������): \n");
    printArray(arr, n);
    free(arr);
    return 0;
}
//###�����޸ĵ㣺
//1.��ʼ����������С�趨Ϊ10����ʹ��`malloc�����ڴ档
//2.���û������ڼ䣬����������룬ֱ���û���������ֺ��ֹͣ��scanf��Ӧ��
//3.��̬���������С��ʹ��`realloc��չ�����Ա���ո���Ԫ�ء�������һ����ʾ�����С�ı���size
//4.�ṩ������ǰ������������������ܣ������ڿ�ʼʱѯ�������С��