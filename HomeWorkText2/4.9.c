#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int data;
    int freq;
    struct Node* pre;
    struct Node* next;
} Node;

// 初始化双向循环链表
void initList(Node** head) {
    *head = NULL;
}

// 创建新结点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->freq = 0;
    newNode->pre = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在链表尾部插入结点
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->pre = newNode;
        (*head)->next = newNode;
    } else {
        Node* last = (*head)->pre;
        newNode->pre = last;
        newNode->next = *head;
        last->next = newNode;
        (*head)->pre = newNode;
    }
}

// 调整链表结点顺序
void adjustOrder(Node** head, Node* current) {
    Node* temp = current->pre;
    while (temp != *head && current->freq > temp->freq) {
        temp = temp->pre;
    }
    if (current->pre != temp) {
        current->pre->next = current->next;
        current->next->pre = current->pre;
        current->next = temp->next;
        current->pre = temp;
        temp->next->pre = current;
        temp->next = current;
    }
}

// 定位元素并更新频度
Node* locate(Node** head, int x) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data == x) {
            current->freq++;
            adjustOrder(head, current);
            return current;
        }
        current = current->next;
    }
    return NULL;
}