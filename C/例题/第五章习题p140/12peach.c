#include<stdio.h>
// int peachleft(int * day,int * p){
//     if(*day >= 1)*p = peachleft(day--,p) * 2 - 1;
//     return *p;
// }
int main(){
    int i = 1,peach = 1;//day = 9,pe = 1;
    while(i <= 9){
        peach = (peach + 1) * 2;
        i++;
    }
    // peachleft(&day,&pe);
    printf("%d\n",peach);
    // printf("%d\n",pe);
    return 0;
}
//Out :1534