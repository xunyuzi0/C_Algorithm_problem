#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct L {

	int data;
	struct L * pNext;

}Lnode, * pLnode;

void insert(pLnode pHead, int x){

    pLnode p = pHead;
    if (p != NULL)
    {
        while (p->pNext != NULL && p->pNext->data < x )
        {
            pLnode pNew = (pLnode)malloc(sizeof(Lnode));
            if (pNew == NULL) {
                printf("动态内存分配失败2！");
                exit(-1);
            }
            pLnode r = p->pNext;
            p->pNext = pNew;
            pNew->pNext = r;
            free(r);
        }
    }else{
        printf("链表为空！");
    }
}