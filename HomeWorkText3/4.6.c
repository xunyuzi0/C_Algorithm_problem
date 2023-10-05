#include<stdio.h>	
#include<stdlib.h>	
#include<string.h>	
#include<stdbool.h>	

typedef struct QueneNode {
	int data;	//病历号
	struct Queue *next;;
} QNode, *pQNode;

typedef struct LinkQuene {
	pQNode front;	//指向队首结点
	pQNode rear;	//指向队尾结点
} LQueue, *pLQueue;

bool InitQuene(pLQueue q);	
bool DestroyQuene(pLQueue q);
bool isEmpty(pLQueue q);
bool enQuene(pLQueue q, int e);
bool deQuene(pLQueue q, int* e);
bool Test(pLQueue q);
void menu(void);

int main(void)
{
	pLQueue q = NULL;
	bool flag = Test(q);
	if (flag)
		printf("谢谢使用,再见。\n");
	return 0;
}
bool Test(pLQueue q)
{
	int n;
	pQNode p;
	bool flag = false;	//是否关闭程序，默认为“否”
	int e;
	InitQuene(q);	//创建链队
	menu();			//输出菜单
	while (scanf("%d", &n) != EOF) {
		switch (n) {
			case 1:printf("请输入您的病历号(不超过十位的整数)：");
				scanf("%lld", &e);
				while (e > 1e10) {
					printf("\n病历号不合规，重新输入：");
					scanf("%lld", &e);
				}
				enQuene(q, e);	//将病历号入队
				printf("\n排队成功。\n");
				break;
			case 2:if (!isEmpty(q)) {
					deQuene(q, e);	//当有人排队，即队不为空时出队
					printf("就诊成功。\n");
				}
				else
					printf("当前无人排队。\n");
				break;
			case 3:p = q->front;	//遍历一遍链队
				printf("排在您前面的人有：\n");
				while (p != NULL) {
					printf("%lld\n", p->data);
					p = p->next;
				}
				break;
			default:printf("指令错误，重新输入。\n");
		}
		if (flag)
			break;
		menu();
	}
	DestroyQuene(q);	//销毁链队
	return true;
}
void menu(void)
{
	printf("菜单:\n");
	printf("1.排队\n");
	printf("2.就诊\n");
	printf("3.查看排队\n");

}
bool InitQuene(pLQueue q)
{
	q = (pLQueue)malloc(sizeof(LQueue));

	q->front = q->rear = NULL;	
    //此时队列无元素（两个下标之间差的绝对值为0）
    return true;
}
bool DestroyQuene(pLQueue q)
{
	pQNode p;		//工作指针
	while (q->front != q->rear) {	//当队列中的结点大于一个时循环
		p = q->front;				//工作指针指向队首结点
		q->front = q->front->next;	//队首结点后移
		free(p);					//释放掉工作指针指向的结点
	}
	p = q->front;
	free(p);	//释放掉最后一个结点
	free(q);	//释放掉链队结点
	return true;
}
bool isEmpty(pLQueue q)
{
	return (q->front == NULL);	//当队列为空时返回“真”，否则返回“假”
}

bool enQuene(pLQueue q, int e)
{
	pQNode p = (pQNode)malloc(sizeof(QNode));
    while (!p) {
		p = (pQNode)malloc(sizeof(QNode));
	}
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;	//当链队为空时，新结点既是头结点又是尾结点
	else {
		q->rear->next = p;	//将新结点接到队尾
		q->rear = p;		//队尾移动
	}
	return true;
}
bool deQuene(pLQueue q, int* e)
{
	if (q->front == NULL)  //当队列为空时无法出队，返回“假”
		return false;
	pQNode p = q->front;	//工作指针指向队首
	if (q->front == q->rear)	//当链队中只有一个结点时
		q->front = q->rear = NULL;
	else						//当链队中有一个以上的结点时
		q->front = q->front->next;
	e = p->data;
	free(p);
	return true;
}
