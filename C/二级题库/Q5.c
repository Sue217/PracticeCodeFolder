//将大于int m且紧靠m的k个素数存入所指数组中
//eg.IN:20 6 OUT:23 29 31 41 43
#include<stdio.h>

void proc(int m,int k,int xx[]){
    int i,j,num = 0;
    for(i=m+1;num<k;i++){
        for(j=2;j<i;j++)
            if(i%j == 0)break;
        if(j >= i)xx[num++] = i;//!!!!!!!!!!!!!!!!!!!!!!
    }
}
int main(){
    void proc(int m,int k,int xx[]);
    int m,n,arr[1000];
    printf("Enter 2 integers: ");
    scanf("%d%d",&m,&n);
    proc(m,n,arr);
    for(m=0;m<n;m++)
        printf("%d ",arr[m]);
    return 0;
}