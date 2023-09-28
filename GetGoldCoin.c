#include<stdio.h>
#include<malloc.h>


//洛谷算法题【算法1-5贪心】题单，P2240，背包问题

typedef struct A{
    int m;
    int v;
    double value;
}A,*PA;//储存每一堆金币的信息

int main() {

    int i,j;
    int cnt, total;//金币堆数，背包总重量
    int temp_m, temp_v;
    A p_temp;
    double getval = 0.0;//取得金币数

    scanf_s("%d %d", &cnt, &total);
    PA a = (PA)malloc(cnt * sizeof(A));

    for (i = 0; i < cnt; i++) {
        scanf_s("%d %d", &temp_m, &temp_v);
        //printf("测试1");
        a[i].m = temp_m;
        //printf("测试2");
        a[i].v = temp_v;
        a[i].value = 1.0 * temp_v / temp_m;
        //printf("测试3");
    }

    for (i = 0; i < cnt - 1; i++) {
        for (j = i + 1; j < cnt; j++) {
            if (a[i].value < a[j].value) {
                p_temp = a[i];
                a[i] = a[j];
                a[j] = p_temp;
            }
        }
    }

    for (i = 0; i < cnt && total>0; i++) {
        if (total > a[i].m) {
            total -= a[i].m;
            getval += a[i].v;
        }
        else {
            getval += total * a[i].value;
            total = 0;
        }
    }

    printf("%.2lf", getval);

}