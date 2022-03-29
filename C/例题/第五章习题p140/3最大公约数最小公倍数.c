#include<stdio.h>
int main(){
    int m,n,max = -1;
    int p,q,tmp,i;

    scanf("%d%d",&m,&n);
    while(max != 0){
        max = m % n;
        if(max == 0){
            printf("%d",n);
            break;
        }
        else{
            m = n;
            n = max;
        }
    }
    scanf("%d%d",&p,&q);
    if(p < q){//p is bigger
        tmp = p;
        p = q;
        q = tmp;
    }
    if(p % q == 0)printf("%d",p);
    else{
        for(i=1;i<=q;++i)
            if((p * i)%q == 0)break;
        printf("%d",p*i);
    }
}