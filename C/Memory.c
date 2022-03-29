#include<stdio.h>
#include<stdlib.h>
int globel_uninit;//BBS段->全局未初始化变量，运行时先初始化为0
int globel_init = 10;//数据段->全局初始化变量
void foo(void){
    static int num = 0;//栈帧计数
    int autovar;//(自动)局部变量
    int *ptr_foo = (int *)malloc(sizeof(int));
    if(++num == 4)return;//创建4个栈帧
    printf("Stack frame number %d: address of autovar: %p\n",num,&autovar);
    printf("Address of heap allocated inside foo() %p\n",ptr_foo);
    foo();
}
int main(){
    int *ptr_main = (int *)malloc(sizeof(int));
    printf("Text Segment:\n");
    printf("Address of main: %p\n",main);
    printf("Address of afunc: %p\n",foo);
    printf("Stack Locations:\n");
    foo();
    printf("Data Segment:\n");
    printf("Address of globel_init: %p\n",&globel_init);
    printf("BSS Segment:\n");
    printf("Address of globel_uninit: %p\n",&globel_uninit);
    printf("Heap Segment:\n");
    printf("Address of heap allocated inside main() %p\n",ptr_main);
    free(ptr_main);
    return 0;
}
/*
➜ gcc -o Memory Memory.c
➜ ./Memory
Text Segment:
Address of main: 0x100b48d50
Address of afunc: 0x100b48ce0
Stack Locations:
Stack frame number 1: address of autovar: 0x7ffeef0ba9ac
Address of heap allocated inside foo() 0x7f927c405860
Stack frame number 2: address of autovar: 0x7ffeef0ba97c
Address of heap allocated inside foo() 0x7f927c405870
Stack frame number 3: address of autovar: 0x7ffeef0ba94c
Address of heap allocated inside foo() 0x7f927c405880
Data Segment:
Address of globel_init: 0x100b4d018
BSS Segment:
Address of globel_uninit: 0x100b4d020
Heap Segment:
Address of heap allocated inside main() 0x7f927c405850
*/