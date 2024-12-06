#include<stdio.h>
#include<math.h>
#define MAX_ITER 1000000

double f(double x){
    return x*x*x - x*x + 2;
}

double df(double x){
    return 3*x*x - 2*x;
}

void newtonRapson(double x0){
    double x1;
    for(int i=0;i<MAX_ITER;i++){
        double f0 = f(x0);
        double df0 = df(x0);

        if(df0 == 0){
            printf("Denominator Zero\n");
            return;
        }

        x1 = x0 - f0/df0;
        if(fabs(f(x1)) < 0.001){
            break;
        }
        x0 = x1;
    }
    printf("Root of the equation = %f",x1);
}

int main(){
    newtonRapson(3);
}