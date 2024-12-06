#include<stdio.h>
#define size 10

float x[size];
float y[size];

float fn(float x){
    return 1/(x*x*x + 10);
}

int main(){
    int n;  // number of points
    scanf("%d",&n);
    float ul,ll;
    scanf("%f %f",&ul,&ll);

    float h = (ul-ll)/(n-1);
    // printf("%d %f %f %f\n",n,ll,ul,h);
    // fill x and y
    for(int i=0;i<n;i++){
        x[i] = (h*i)+ll;
        y[i] = fn(x[i]);
    }
    for(int i=0;i<n;i++){
        printf("%f %f\n",x[i],y[i]);
    }
    float res = y[0]+y[n-1];
    for(int i=1;i<n-1;i++){
        res+=2*y[i];
    }
    res = res*h/2;
    printf("Value of integral is  : %f",res);
    return 0;
}