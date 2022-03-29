#include<stdio.h>
int main(){
    double height = 100.0,sum = 0.0;
    int i;
    for(i=0;i<9;i++){
        sum += height;
        height = height / 2;
        sum += height;
    }//9次反弹
    sum += height;//10次落地
    printf("%lf\n",sum);
    height = height / 2;//10次反弹
    printf("%lf\n",height);
    return 0;
}