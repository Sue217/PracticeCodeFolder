#include<stdio.h>
int fac(int i);
int main(){
    for(int i=1;i<=10;i++)
        printf("%d! = %d\n",i,fac(i));
    return 0;
}
int fac(int i){
    static int f = 1;//static int reserve the return value
    f *= i;
    return f;//return f!
}
