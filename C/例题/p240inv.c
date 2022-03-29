#include<stdio.h>
int main(){
    int i,j,arr[10] = {3,5,4,6,7,8,9,3,1,2};
    void inv(int a[],int n);
    inv(arr,10);
    for(j=0;j<10;j++)
        printf("%d",arr[j]);
    printf("\n");
    return 0;
}
void inv(int a[],int n){
    int i,j,tmp;
    for(i=0;i<=(n-1)/2;i++){
        j = n-1-i;//Remember
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    return;
}