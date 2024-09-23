// Online C compiler to run C program online
#include <stdio.h>

double func(double x){
    return x*x*x - x*x + 2;
}

void bisection(double a,double b){
    if(func(a)* func(b) >= 0){
        printf("Assumed values are wrong\n");
        return;
    }
    double c = a;
    while((b-a) >= 0.01){
        c = (b+a)/2;
        if(func(c) == 0.0){
            break;
        }
        if(func(c)*func(a) > 0){
            a=c;
        }else{
            b=c;
        }
    }
    printf("Root for the given equation is : %.4f",c);
}

int main() {
    double a =-200, b = 300;
    bisection(a, b);
    return 0;
    return 0;
}
