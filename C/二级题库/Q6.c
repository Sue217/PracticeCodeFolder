//计算输出3～m所有素数平方根之和
//eg.m = 50 => s = 63.665791
//m>2 && m<=100
#include<stdio.h>
#include<math.h>
double fun(int m){
    int i,j;
    double sum = 0.0;
    for(i=3;i<m;i+=2){
        for(j=2;j<i;j++)
            if(i % j == 0)break;
        if(j >= i)sum += sqrt(i);//!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    return sum;
} 
int main(){
    int m;
    double s;
    printf("Input m: ");
    scanf("%d",&m);
    s = fun(m);
    printf("s = %f\n",s);
    return 0;
}