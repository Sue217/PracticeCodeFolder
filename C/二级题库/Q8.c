//In:(int) n
//Out:S = 1+(1+√2)+(1+√2+√3)+...+(1+√2+√3+...+√n)
#include<stdio.h>
#include<math.h>
double proc(int n){
    int i;
    double sum = 0.0,part = 0.0;
    for(i=1;i<=n;i++){
        part += sqrt(i);
        sum += part;
    }
    return sum;
}
int main(){
    int n;
    double S;
    scanf("%d",&n);
    S = proc(n);
    printf("%f\n",S);
    return 0;
}