#include <stdio.h>

typedef struct L {
    int data;
    struct node *next, *prior;
} Lnode, *pLnode;

void InsertSort(pLnode pHead)
{
    pLnode p, s, q;
    p = pHead->next; 
    while (p != NULL)
    {
        s = pHead;                                  
        q = pHead->prior;                           
        while ((q != NULL) && (p->data > q->data)) 
        {
            s = q;
            q = q->prior;
        }
        s->prior = p;
        p->prior = q; 
        p = p->next;
    }
}