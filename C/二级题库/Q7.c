//定义M*M数组 求出数组周边元素平方和 作为函数值返回主函数s
//数组a为{0,1,2,7,9,1,67,20,93,5,2,5,18,34,1,9,9,8,87,2,5,4,1,4,1} s=310

#include<stdio.h>
#include<stdlib.h>
#define M 5
int proc(int w[][M]){
    int i,j,sum = 0;
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            if(i==0||i==M-1||j==0||j==M-1)
                sum += w[i][j] * w[i][j];
        }
    }
    return sum;
}
int main(){
    int arr[M][M] = {0,1,2,7,9,1,67,20,93,5,2,5,18,34,1,9,9,8,87,2,5,4,1,4,1};
    int i,j,sum;
    printf("* * * * The Array * * * *\n");
    for(i=0;i<M;i++){
        for(j=0;j<M;j++)
            printf("%4d",arr[i][j]);
        printf("\n");
    }
    sum = proc(arr);
    printf("* * * * The Result * * * *\n");
    printf("The sum is : %d\n",sum);
    return 0;
}