#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int top[2], bot[2];
	int *V;
	int m;
}DblStack;

int Empty(DblStack *stk)
{
	return (stk->top[0] == -1 && stk->top[1] == m);
}

bool Init(DblStack *stk)
{
	stk->top[0] = -1;
	stk->top[1] = stk->m;
	stk->bot[0] = 0;
	stk->bot[1] = stk->m - 1;
	return true;
}

int push(DblStack *stk, int i, int val)
{
	if (stk->top[1] - stk->top[0] == 1)
	{
		printf("OverFlow!/n");
		return 0;
	}
	switch (i)
	{
	case 0:
		V[++top[0]] = val;
		return 1;
		break;
	case 1:
		V[--top[1]] = val;
		return 1;
		break;
	default:
		printf("Error stack!\n");
		return 0;
	}
}

int pop(DblStack *stk, int i)
{
	switch (i)
	{
	case 0:
		if (stk->top[0] == -1)
			printf("左栈为空!\n");
		else
			return stk->V[top[0]--];
	case 1:
		if (stk->top[1] == m)
			printf("右栈为空!\n");
		else
			return stk->V[top[1]++];
	default:
	}
}

