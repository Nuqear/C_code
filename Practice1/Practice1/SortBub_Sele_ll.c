#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ����ڵ㵽����ĩβ
void appendNode(Node** head_ref, int new_data) {
    // 1. �����½ڵ���ڴ�  
    Node* new_node = (Node*)malloc(sizeof(Node));

    // 2. ����ڴ�����Ƿ�ɹ�����ʵ��Ӧ���У�����һ����ϰ�ߣ�������Ϊ�˼���ʡ���ˣ�  
    // if (new_node == NULL) {  
    //     // �����ڴ����ʧ�ܵ����  
    // }  

    // 3. �����½ڵ������  
    new_node->data = new_data;

    // 4. ��ʼ���½ڵ��nextָ��ΪNULL����ʾ�½ڵ�Ŀǰ����������һ���ڵ�  
    new_node->next = NULL;

    // 5. ��������Ƿ�Ϊ��  
    if (*head_ref == NULL) {
        // �������Ϊ�գ����½ڵ㼴Ϊͷ�ڵ�  
        *head_ref = new_node;
        return;
    }

    // 6. �������Ϊ�գ��ҵ���������һ���ڵ�  
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // 7. �����һ���ڵ��nextָ��ָ���½ڵ㣬��ɲ���  
    last->next = new_node;
}

// ��ӡ����
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// ð������
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

// ѡ������
void selectionSort(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    while (current != NULL) {
        Node* minNode = current;
        Node* nextNode = current->next;

        // �ҵ���С�Ľڵ�
        while (nextNode != NULL) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // ��������
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

    printf("����������Ԫ�� (��������ֽ���):\n");
    while (1) {
        int input;
        if (scanf("%d", &input) != 1) {
            break; // ���������ֹͣ
        }
        appendNode(&head, input); // ������洢��������
    }

    // ð������
    printf("����ǰ���� (ð������): \n");
    printList(head);

    bubbleSort(head);

    printf("��������� (ð������): \n");
    printList(head);

    // ѡ������
    printf("��������������Ԫ�� (��������ֽ���):\n");
    head = NULL; // ��������
    while (1) {
        int input;
        if (scanf("%d", &input) != 1) {
            break; // ���������ֹͣ
        }
        appendNode(&head, input); // ������洢��������
    }

    printf("����ǰ���� (ѡ������): \n");
    printList(head);

    selectionSort(head);

    printf("��������� (ѡ������): \n");
    printList(head);

    // �ͷ�������ڴ�
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

//### ����˵����
//1. * *����ڵ�ṹ(`Node`) * *����̬����洢ÿ���������ݵ���ֵ��ָ����һ���ڵ��ָ�롣
//2. * *`appendNode` ���� * *�����½ڵ�׷�ӵ������ĩβ��
//3. * *`printList` ���� * *������������ӡÿ���ڵ�����ݡ�
//4. * *`bubbleSort` ���� * *��ͨ���ڵ����ݵĽ���ʵ��ð������
//5. * *`selectionSort` ���� * *��ѡ�������㷨���ҵ���С�ڵ㲢�����뵱ǰ�ڵ㽻����
//6. * *`main` ���� * *�������������ݡ��������򣬲����û���������ֺ�ֹͣ��
//
//### �����ԣ�
//�ó��������û����������������������û�ֻ����������ɺ���������ּ��ɽ������롣
// Ȼ����������е�Ԫ�ؽ������򲢴�ӡ�������ʵ��ʹ������Ľṹ����̬�����������ݡ�
