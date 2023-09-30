#include<stdio.h>


int main(){

    int s,v;//路程时间
    int time_min = 0;
    int time_hour = 0;
    scanf("%d %d",&s,&v);

    double temp1 = 1.0*s/1.0*v;
    time_hour = (int)temp1*60/60;
    time_min = (int)temp1*60%60+10;

    if(time_min >= 60){
        time_hour +=2;
        time_min %= 60;
    }
    else{
        time_hour += 1;
        time_min %= 60;
    }

    int a = (8 - time_hour + 24)%24;
    int b = 60 - time_min;
    if(a>9&&b>9){
        printf("%d:%d",a,b);
    }else if(a>9&&b<10){
        printf("%d:0%d",a,b);
    }else if(a<10&&b>9){
        printf("0%d:%d",a,b);
    }else{
        printf("0%d:0%d",a,b);
    }
    
    

    return 0;
}