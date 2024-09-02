#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 插入节点到链表末尾
void appendNode(Node** head_ref, int new_data) {
    // 1. 分配新节点的内存  
    Node* new_node = (Node*)malloc(sizeof(Node));

    // 2. 检查内存分配是否成功（在实际应用中，这是一个好习惯，但这里为了简洁而省略了）  
    // if (new_node == NULL) {  
    //     // 处理内存分配失败的情况  
    // }  

    // 3. 设置新节点的数据  
    new_node->data = new_data;

    // 4. 初始化新节点的next指针为NULL，表示新节点目前是链表的最后一个节点  
    new_node->next = NULL;

    // 5. 检查链表是否为空  
    if (*head_ref == NULL) {
        // 如果链表为空，则新节点即为头节点  
        *head_ref = new_node;
        return;
    }

    // 6. 如果链表不为空，找到链表的最后一个节点  
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // 7. 将最后一个节点的next指针指向新节点，完成插入  
    last->next = new_node;
}

// 打印链表
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// 冒泡排序
void bubbleSort(Node* head) {
    if (head == NULL) return;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// 选择排序
void selectionSort(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    while (current != NULL) {
        Node* minNode = current;
        Node* nextNode = current->next;

        // 找到最小的节点
        while (nextNode != NULL) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // 交换数据
        if (minNode != current) {
            int temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }

        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    printf("请输入数组元素 (输入非数字结束):\n");
    while (1) {
        int input;
        if (scanf("%d", &input) != 1) {
            break; // 输入非数字停止
        }
        appendNode(&head, input); // 将输入存储到链表中
    }

    // 冒泡排序
    printf("排序前数组 (冒泡排序): \n");
    printList(head);

    bubbleSort(head);

    printf("排序后数组 (冒泡排序): \n");
    printList(head);

    // 选择排序
    printf("请重新输入数组元素 (输入非数字结束):\n");
    head = NULL; // 重置链表
    while (1) {
        int input;
        if (scanf("%d", &input) != 1) {
            break; // 输入非数字停止
        }
        appendNode(&head, input); // 将输入存储到链表中
    }

    printf("排序前数组 (选择排序): \n");
    printList(head);

    selectionSort(head);

    printf("排序后数组 (选择排序): \n");
    printList(head);

    // 释放链表的内存
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

//### 代码说明：
//1. * *链表节点结构(`Node`) * *：动态分配存储每个输入数据的数值和指向下一个节点的指针。
//2. * *`appendNode` 函数 * *：将新节点追加到链表的末尾。
//3. * *`printList` 函数 * *：遍历链表并打印每个节点的数据。
//4. * *`bubbleSort` 函数 * *：通过节点数据的交换实现冒泡排序。
//5. * *`selectionSort` 函数 * *：选择排序算法，找到最小节点并将其与当前节点交换。
//6. * *`main` 函数 * *：负责输入数据、调用排序，并在用户输入非数字后停止。
//
//### 适用性：
//该程序允许用户输入任意数量的整数，用户只需在输入完成后输入非数字即可结束输入。
// 然后程序将链表中的元素进行排序并打印结果。本实现使用链表的结构来动态管理输入数据。
