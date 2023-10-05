#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    int front;//队头
    int rear;//队尾
    int size;//容量
} CirQueue; 

//初始化队列
CirQueue* Create(int k) {
    CirQueue* obj = (CirQueue*)malloc(sizeof(CirQueue));
    if (obj == NULL) {
        return NULL;
    }
    obj->array = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->size = k + 1;
    return obj;
}

//入队
bool EnQueue(CirQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    obj->array[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;
    return true;
}

//出队
bool DeQueue(CirQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    obj->front = (obj->front + 1) % obj->size;
    return true;
}

//判空
bool IsEmpty(CirQueue* obj) {
    if (obj->front == obj->rear) {
        return true;
    }
    return false;
}

//删除队列
void CirQueueFree(CirQueue* obj) {
    free(obj->array);
    free(obj);
}