#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,k;
    int m = 0;
    scanf("%d",&n);
    scanf("%d",&k);
    int * a = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]*a[j] <= k)m++;
        }
    }
    printf("%d",m);
    return 0;
}