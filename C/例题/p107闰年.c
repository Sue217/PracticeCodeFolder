#include<stdio.h>
int main(){
    int year;
    scanf("%d",&year);
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0))printf("The year is leap.\n");
    else printf("The year is not leap.\n");
    return 0;
}