#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    int i,j;
    for(i=0;(str[i]=getchar()) != '\n';i++);
    for(j=i-1;j>=0;j--)
        printf("%c",str[j]);
    printf("\n");
    return 0;
    // char str[40];
    // int i = 0;
    // while(str[i] = getchar() != '\n')i++;Better
    // for(i=0;str[i]!='\n';i++)scanf("%c",&str[i]);Is bad
    // printf("%d\n",strlen(str));
    // puts(str);
    // return 0;
}