//100~200素数
#include<stdio.h>
int main(){
    int i,j;
    for(i=100;i<200;i++){
        for(j=2;j<i;j++){
            if(i%j == 0)
                break;
            if(i == j+1)
                printf("%6d",i);
        }
    }
}