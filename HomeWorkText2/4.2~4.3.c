#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct L {

	int data;
	struct L * pNext;

}Lnode, * pLnode;


pLnode init_LList(void);
bool show_LList(pLnode pHead);
bool ListLength(pLnode p, int*);//4.2求表长算法
bool Reverse(pLnode pHead);//4.3链表倒置

int main(void) {

	int len = 0;//储存得到的表长

	pLnode pHead = NULL;//创建一个链表结构的指针，作为头指针
	pHead = init_LList();
	show_LList(pHead);

	if(ListLength(pHead, &len)){
		printf("求表长成功，表长为：%d\n",len);
	}else{
		printf("求表长失败！\n");
	}

	Reverse(pHead);
	show_LList(pHead);

	return 0;
}

//初始化链表
pLnode init_LList(void) {

	int i = 0;
	int cnt = 0;//储存用户需要创建的结点数
	int temp = 0;//临时存储用户需要输入的链表内容

	pLnode p = (pLnode)malloc(sizeof(Lnode));
	//创建一个结点指针，作为头结点指针
	if (p == NULL) {
		printf("动态内存分配失败1！");
		exit(-1);
	}//创建一个新结点的指针,并检查内存是否分配成功
	p->pNext = NULL;//注意指针域为空

	pLnode pLast = p;//创建一个结点，作为尾结点，初始状态为头结点

	printf("请输入需要创建的链表结点数：");
	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++) {

		printf("请输入第%d个结点储存的数：", i + 1);
		scanf("%d", &temp);

		//printf("a ");

		pLnode pNew = (pLnode)malloc(sizeof(Lnode));//新结点
		//printf("b ");
		if (pNew == NULL) {
			printf("动态内存分配失败2！");
			exit(-1);
		}
		//printf("c ");
		pNew->data = temp;//储存数据
		pNew->pNext = NULL;//注意指针域为空
		//printf("d ");

		pLast->pNext = pNew;
		pLast = pNew;//将新结点插入尾节点，新结点成为尾结点
		//printf("e ");
	}

	return p;
}

//输出整个链表
bool show_LList(pLnode p) {

	int i;
	for (i = 0; p->pNext != NULL; p = p->pNext, i++) {
		printf("%d:%d   ", i + 1, p->pNext->data);
	}//注意p初始时指向的是头结点，其数据域无有效数据
	printf("\n");

	return true;

}

//求表长
bool ListLength(pLnode p, int *len){

	int length = 0;
	while(p->pNext != NULL){
		p = p->pNext;
		length++;
	}
	*len = length;

	return true;
}

//实现链表倒置
bool Reverse(pLnode pHead)
{
	pLnode p,s;
	p = pHead->pNext;
	pHead->pNext = NULL;
	
	while(p)
	{
		s = p; 
		p = p->pNext;

		s->pNext = pHead->pNext; 
		pHead->pNext = s;
	}
}
