//给三角形三边长求三角形面积
//area = sqrt(s*(s-a)*(s-b)*(s-c))
#include<stdio.h>
#include<math.h>
int main(){
    double a = 3.67,b = 5.43,c = 6.21,s,area;
    s = (a + b + c)/2;
    area = sqrt(s * (s-a) * (s-b) * (s-c));
    printf("%f\n",area);
    return 0;
}