//1900~2000闰年
#include<stdio.h>
int main(){
    for(int i =1900;i<=2000;i++)
        if(i%4==0&&i%100!=0 || i%100==0&&i%400==0)
            printf("%5d",i);
    return 0;
}