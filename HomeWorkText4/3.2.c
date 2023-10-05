#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
struct ListNode {
    char data;
    struct ListNode* next;
};

// 创建单链表节点
struct ListNode* createNode(char ch) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = ch;
    newNode->next = NULL;
    return newNode;
}

// 找出s中第一个不在t中出现的字符
char findFirstUniqueChar(struct ListNode* s, struct ListNode* t) {
    int hashTable[128] = {0}; 
    struct ListNode* p = t;

    while (p != NULL) {
        hashTable[p->data] = 1;
        p = p->next;
    }

    // 查找第一个不在t中出现的字符
    p = s;
    while (p != NULL) {
        if (hashTable[p->data] == 0) {
            return p->data;
        }
        p = p->next;
    }

    return '\0'; // 如果没有找到，则返回空字符
}
