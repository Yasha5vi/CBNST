#include<stdio.h>
#include<math.h>
#define MAX_ITER 1000000

double func(double x){
    return pow(x, 3) + x - 1;
}

void secant(double x0, double x1){
    double x2;

    if(func(x0)*func(x1) > 0){
        printf("Assumed Values are wrong\n");
        return;
    }
    for(int i=0;i<MAX_ITER;i++){

        x2 = ((x0*func(x1)-x1*func(x0))/(func(x1)-func(x0)));

        if(fabs(x2-x1) < 0.001){
            break;
        }
        x0 = x1;
        x1 = x2;
    }
    printf("Root found = %f",x2);
}

int main(){
    secant(0,1);
}
