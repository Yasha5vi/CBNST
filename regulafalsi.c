#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x){
    return x*x*x - x*x + 2;
}

int main(){
    float a,b,c,te;
    printf("Enter the intervals : ");
    scanf("%f %f",&a,&b);
    printf("Enter tolerance error : ");
    scanf("%f",&te);
    if(f(a)*f(b) > 0){
        printf("Intervals guessed are wrong ");
        return 0;
    }
    if(f(a)*f(b) == 0){
        printf("Guessed intervals are the roots");
        return 0;
    }

    while(1){
        c = a - (((b-a)*f(a))/(f(b)-f(a)));
        if(fabs(f(c)) < te){
            break;
        }
        if(f(a)*f(c) > 0){
            a = c;
        }else{
            b = c;
        }
        printf("Interval : [ %f , %f ]\n",a,b);
    }
    printf("Roots of the equation : %.4f",c);
    return 0;
}
