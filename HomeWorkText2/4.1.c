#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct L {

	int data;
	struct L * pNext;

}Lnode, * pLnode;

pLnode init_LList(void);
bool delete_i(pLnode p, int pos, int *pNum);//4.1删除第i个结点算法
bool show_LList(pLnode p);


int main(void) {

	int temp = 0;//临时储存被删除结点的值

	pLnode p = NULL;//创建一个链表结构的指针，作为首指针
	p = init_LList();
	show_LList(p);

	if (delete_i(p, 2, &temp))
		printf("删除结点成功，删除的值为：%d\n", temp);
	show_LList(p);

	return 0;
}

//初始化链表
pLnode init_LList(void) {

	int i = 0;
	int cnt = 0;//储存用户需要创建的结点数
	int temp = 0;//临时存储用户需要输入的链表内容

	pLnode p = (pLnode)malloc(sizeof(Lnode));
	//创建一个结点指针，作为首结点指针
	if (p == NULL) {
		printf("动态内存分配失败1！");
		exit(-1);
	}//创建一个新结点的指针,并检查内存是否分配成功
	p->pNext = NULL;

	pLnode pLast = p;//创建一个结点，作为尾结点，初始状态为头结点

	printf("请输入需要创建的链表结点数：");
	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++) {

		printf("请输入第%d个结点储存的数：", i + 1);
		scanf("%d", &temp);
        
        if(i == 0){
            p->data = temp;//储存数据
            p->pNext = NULL;//注意指针域为空
        }else{
            pLnode pNew = (pLnode)malloc(sizeof(Lnode));
            if (pNew == NULL) {
                printf("动态内存分配失败2！");
                exit(-1);
            }

            pNew->data = temp;//储存数据
            pNew->pNext = NULL;//注意指针域为空

            pLast->pNext = pNew;
            pLast = pNew;//将新结点插入尾节点，新结点成为尾结点
        }
		
	}

	return p;
}

//删除并返回链表中某个元素
bool delete_i(pLnode p, int pos, int* pNum) {

	int i = 0;
	pLnode ptemp = p;//使得ptemp指向首结点

	if(pos == 1){
		p = p->pNext;
		*pNum = ptemp->data;
		free(ptemp);

	}else{
		while (ptemp != NULL && i < pos - 2) {
		ptemp = ptemp->pNext;
		i++;
		}//若输入无误，则使得ptemp指针最终指向pos前一个结点

		if (ptemp == NULL || i > pos - 2) {
			printf("输入有误，删除失败！");
			return false;
		}//排除错误可能

		*pNum = ptemp->pNext->data;//将所删除结点的值赋给num

		pLnode r = ptemp->pNext;//使得r指向需要删除的结点
		ptemp->pNext = ptemp->pNext->pNext;//用删除结点的下一个结点地址覆盖删除节点
		free(r);
		//注意！！！
		//必须手动释放删除结点的内存！！！！
	}

	return true;
}

//输出整个链表
bool show_LList(pLnode p) {

	int i;
	for (i = 0; p != NULL; p = p->pNext, i++) {
		printf("%d:%d   ", i + 1, p->data);
	}
	printf("\n");

	return true;

}
