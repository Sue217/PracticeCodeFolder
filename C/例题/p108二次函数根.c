#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c,dert,x1,x2,real,imag;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(fabs(a) <= 1e-6)printf("It is not a quadratic\n");
    else{
        dert = b * b - 4 * a * c;
        if(fab(dert) <= 1e-6)printf("Two equal real roots:%8.4f\n",-b/(2*a));//∆ = 0
        else{
            if(dert > 1e-6){//∆ > 0
                x1 = (-b + sqrt(dert))/(2 * a);
                x2 = (-b - sqrt(dert))/(2 * a);
                printf("Two distinct real roots:%8.4f %8.4f\n",x1,x2);
            }
            else{//∆ < 0
                real = -b/(2*a);
                imag = (sqrt(-dert))/(2*a);//imag = √(-∆)/2a
                printf("Two complex roots:\n");
                printf("%8.4f + %8.4fi\n",real,imag);
                printf("%8.4f - %8.4fi\n",real,imag);
            }
        }
    }
    return 0;
}