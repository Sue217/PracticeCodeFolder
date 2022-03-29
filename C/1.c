#include<stdio.h>
int main()
{
    int n,m;
    int q=0;
    scanf("%d",&n);
    scanf("%d",&m);
    int * a = (int*)malloc(n*sizeof(int));
    int * b = (int*)malloc(m*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int j=0;j<m;j++)
    {
        scanf("%d",&b[j]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j]){
                q++;
            }
        }
    }
    printf("%d",q);
    return 0;
}