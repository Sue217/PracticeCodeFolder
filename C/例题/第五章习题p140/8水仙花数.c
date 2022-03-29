#include<stdio.h>
int main(){
    int i;
    for(i=100;i<1000;i++)
        if((i/100)*(i/100)*(i/100)+(i%100/10)*(i%100/10)*(i%100/10)+(i%10)*(i%10)*(i%10) == i)
            printf("%d\n",i);
    printf("\n");
    return 0;
}