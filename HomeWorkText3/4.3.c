#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct L
{
    int data;
    struct L *pNext;
} Lnode, *pLnode;

insert(pLnode rear, int x) { 
    pLnode p;
    p = (pLnode)malloc(sizeof(Lnode));
    if (rear == NULL) 
        rear = p;
        rear->pNext = p; 
    }
    else 
    {
        p->pNext = rear->pNext;
        rear->pNext = p;
        rear = p;
    }
}
delete(pLnode rear) {
    if (rear == NULL) 
        printf("空队\n");
    if (rear->pNext == rear) 
        rear = NULL;
    else
        rear->pNext = rear->pNext->pNext;
}