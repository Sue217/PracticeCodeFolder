/*
企业发放的奖金根据利润提成。利润低于或等于100000元的，奖金可提10%;
利润高于100000元，低于200000元（100000<I≤200000）时，低于100000元的部分按10％提成，高于100000元的部分，可提成 7.5%;
200000<I≤400000时，低于200000元部分仍按上述办法提成，（下同），高于200000元的部分按5％提成；
400000<I≤600000元时，高于400000元的部分按3％提成；

600000<I≤1000000时，高于600000元的部分按1.5%提成；
I>1000000时，超过1000000元的部分按1%提成。从键盘输入当月利润I,求应发奖金总数。

*/
#include <stdio.h>
#define TW 100000
int main(){
    long profit,b;
    scanf("%ld",&profit);
    if(profit <= TW)b = 0.1 * profit;
    else if(profit>TW && profit<=2*TW)b = 0.1 * TW + 0.075 * (profit - TW);
    else if(profit>2*TW && profit<=4*TW)b = 0.1 * TW + 0.15 * TW + 0.05 * (profit - 2 * TW);
    else if(profit>4*TW && profit<=6*TW)b = 0.1 * TW + 0.15 * TW + 0.2 * TW + 0.03 * (profit - 4 * TW);
    else if(profit>6*TW && profit<=10*TW)b = 0.1 * TW + 0.15 * TW + 0.2 * TW + 0.12 * TW +0.015 * (profit - 6 * TW);
    else b = 0.1 * TW + 0.15 * TW + 0.2 * TW + 0.12 * TW + 0.09 * TW + 0.01 * (profit - 10 * TW);
    printf("%ld\n",b);
    return 0;
}
