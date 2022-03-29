#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*对长度为9字符串，除首尾字符其余7个字符按ASCII降序排列*/
void proc(char *m,int num){
    // char * p = m;
    char tmp;
    for(int i=1;i<num-2;i++){//基本冒泡排序(字符串可用)
        for(int j=i+1;j<num-1;j++){
            if(m[i] < m[j]){
                tmp = m[i];
                m[i] = m[j];
                m[j] = tmp;
            }
        }
    }
}

int main(){
    char t[10];
    printf("Enter 9 Characters:");
    gets(t);
    proc(t,9);
    printf("\n%s",t);
}