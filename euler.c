#include<stdio.h>

float fn(float x,float y){
    // dy/dx
    return x+y; 
}

int main(){
    float xi,yi,h,xf;
    scanf("%f %f %f %f",&xi,&yi,&h,&xf);

    int n = (xf-xi)/h+1;
    float table[2][n];

    table[0][0] = xi;
    table[1][0] = yi;

    for(int i=1;i<n;i++){
        float px = table[0][i-1];
        float py = table[1][i-1];
        table[0][i] = px+h;
        table[1][i] = py+h*fn(px,py);
    }
    for(int i=0;i<n;i++){
        printf("%f %f\n",table[0][i],table[1][i]);
    }
    return 0;
}