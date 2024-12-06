#include<stdio.h>
#define size 10

int x[size];
int y[size];

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&y[i]);
    }

    int x_val;
    scanf("%d",&x_val);

    float res = 0;
    for(int i=0;i<n;i++){
        float nr = 1,dr = 1;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            nr*=(x_val-x[j]);
            dr*=(x[i]-x[j]);
            // printf("in %f %f ",nr,dr);
        }
        res+=(nr/dr)*y[i];
        // printf("%f %f %f\n",nr,dr,res);
    }
    printf("Value of y at x = %d is %f",x_val,res);
    return 0;
}
