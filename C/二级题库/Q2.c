#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//proc()将str指字符串中ascii值偶数的字符删除
//eg.aBcdefg789 => aceg79
void proc(char *str,char t[])
{
    int k = 0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]%2 != 0)t[k++] =  str[i];//返回ASCII码奇数的字符
    }
    t[k] = '\0';
}
int main()
{
    char str[100],t[100];
    printf("\n Enter string S: ");
    scanf("%s",str);//注意这里没有&
    proc(str,t);
    printf("\nThe result is: %s\n",t);
}