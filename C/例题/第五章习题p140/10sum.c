#include<stdio.h>
int main(){
    int p,q;
    double i = 2.0,j = 1.0,k,sum = 0.0;
    for(p=0;p<20;p++){
        sum += i / j;
        k = i;
        i += j;
        j = k;
    }
    printf("%lf\n",sum);
    return 0;
}