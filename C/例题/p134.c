#include<stdio.h>
int main(){
    int f1=1,f2=1,f3,m;
    for(m=0;f1<=100;m++){
        printf("%d  ",f1);
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    printf("\n");
    return 0;
}

/*p135!!!
int f1=1,f2=1;
for(int i=0;i<21;i++){
    printf("%12d%12d",f1,f2);
    if(i % 2 == 0)printf("\n");四个一换行!
    f1 = f1 + f2;!!
    f2 = f2 + f1;!!
}
*/