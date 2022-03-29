#include<stdio.h>
#include<stdlib.h>

//proc()将两个两位数num1,num2合并成一个整数放在num中
//合并方式：num1十位和个位依次放在num十位和千位上，num2数十位和个位依次放在num百位和个位上
//eg.num1=64 num2=18 => num=4168

void proc(int num1,int num2,long * num){
    //两位数十位:num/10 个位:num%10
    *num = (num1%10)*1000+(num2/10)*100+(num1/10)*10+num2%10;
    //注意*!warning: incompatible integer to pointer conversion assigning to 'long *' from 'int'
}
int main(){
    int num1,num2;
    long num;
    printf("Input num1,num2:");
    scanf("%d%d",&num1,&num2);
    proc(num1,num2,&num);
    printf("The result is:%ld\n",num);
}