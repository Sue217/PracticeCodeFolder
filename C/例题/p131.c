#include<stdio.h>
int main(){
    double pi,n,sign=1,sum = 0;//!
    for(n=1;(1/(n+2))>1e-6;n+=2){
        sum += sign/n;
        sign = -sign;//!
    }
    pi = sum * 4;
    printf("π = %10.8f\n",pi);
    return 0;
}