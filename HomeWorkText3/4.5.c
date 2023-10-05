#include<stdio.h>
#include<stdlib.h>

//递归
int fn1(int n){
	if(n==0)
		return n+1;
	else 
		return n*math(n/2);
}

//非递归
int fn2(void){
	int n,i;
	printf("输入n的值：\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<=n;i++){
		if(i<1)
			a[i]=1;
		else{
			a[i]=i*a[i/2];
		}
	}
	
	return 0;
}