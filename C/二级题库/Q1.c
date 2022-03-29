#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

//输入字符串，输入一个数，删除所在该数的字符
//eg.student 5 => studet
void proc(char a[],char b[],int n)
{
    int k;
    k = strlen(a);
    for(int i=0;i<n;i++)b[i] = a[i];
    for(int j=n;j<k;j++)b[j] = a[j+1];//删除输入对应下标的字符
    /*
    int k = 0;
    for(int i=0;a[i]!='\0';i++)
        if(i != n)b[k++] = a[i];
    b[k] = 0;*/
}

int main()
{
    char str1[N],str2[N];
    int n;
    printf("Enter the string: \n ");
    gets(str1);
    printf("Enter the position of the string deleted:");
    scanf("%d",&n);
    proc(str1,str2,n);
    printf("The new string is: %s \n",str2);
}