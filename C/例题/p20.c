//1-1/2+1/3-1/4+...+1/99-1/100
#include<stdio.h>
int main(){
    int m;
    double sum = 0.0;
    for(m=1;m<=100;m++){
        if(m % 2 == 0)//偶数
            sum -= 1.0/m;//1.0!!!!!!!
        if(m % 2 == 1)//奇数
            sum += 1.0/m;//1.0!!!!!!!
    }
    printf("%lf",sum);
    return 0;
}