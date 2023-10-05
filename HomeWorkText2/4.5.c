#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct L {

	int data;
	struct L * pNext;

}Lnode, * pLnode;

//以没有头结点的链表为例
delete (pLnode head, int max, int min){
    pLnode p, q;
    if (head != NULL)
    {
        q = head;
        p = head->pNext;
        while (p != NULL && p->data <= min)
        {
            q = p;
            p = p->pNext;
        }
        while(p != NULL && p->data > min){
                q = p->pNext;
                free(p);
                p = q->pNext;
        }
    }else{
        printf("链表为空！");
    }
}