#include<stdio.h>
#include<string.h>
int main(){
    char str[100],ch = ' ';
    int i,j = 0;
    // scanf("%c",&ch);
    for(i=0,j=0;(str[i]=getchar())!='\n';i++)
        if(str[i] != ch)str[j++] = str[i];
    str[j] = '\0';
    puts(str);
    return 0;
}