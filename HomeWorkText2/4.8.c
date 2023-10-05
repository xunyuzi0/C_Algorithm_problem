#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct L
{

    int data;
    struct L *pNext;

} Lnode, *pLnode;

void SubSequence(pLnode A, pLnode B)
{
    pLnode pa = A->pNext, pb = B->pNext;
    int count = 0; 
    if (Length(A) < Length(B))
    {
        printf("不是子序列\n");
        return;
    }
    while (pa != NULL && pb != NULL)
    {
        if (pa->data == pb->data)
        {
            count = 1;
            pa = pa->pNext;
            pb = pb->pNext;
        }
        else
        {
            if (count == 1)
            {
                printf("B不是A的连续子序列\n");
                return;
            }
            else
                pa = pa->pNext;
        }
    }
    printf("\nB是A的连续子序列");
}

// 表长
int Length(pLnode L)
{
    int cnt = 0;
    pLnode p = L->pNext;
    while (p != NULL)
    {
        cnt++;
        p = p->pNext;
    }
    return cnt;
}