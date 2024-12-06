#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define size 10

void backward(float x[size],float y[size][size],int n){
    for(int j=1;j<n;j++){
        for(int i=j;i<n;i++){
            y[i][j] = y[i][j-1]-y[i-1][j-1];
        }
    }

    printf("Table\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%f\t",y[i][j]);
        }
        printf("\n");
    }

    float v;
    printf("Enter the interpolating value : ");
    scanf("%f",&v);
    float h = x[1]-x[0];
    float u = (v-x[n-1])/h;
    float sum = y[n-1][0];
    float p = 1;
    for(int j=1;j<n;j++){
        p = p*(u+j-1)/j;
        sum = sum + p*y[n-1][j];
    }
    printf("The values is : %f",sum);
    
}


int main(){
    float x[size],y[size][size];
    printf("Enter the numeber of points : ");
    int n;
    scanf("%d",&n);
    printf("Enter the x values : ");
    for(int i=0;i<n;i++){
        scanf("%f",&x[i]);
    }
    printf("Enter the y values : ");
    for(int i=0;i<n;i++){
        scanf("%f",&y[i][0]);
    }
    printf("Entered table : \n");
    printf("x : ");
    for(int i=0;i<n;i++){
        printf("%f\t",x[i]);
    }printf("\n");
    printf("y : ");
    for(int i=0;i<n;i++){
        printf("%f\t",y[i][0]);
    }
    printf("\n");
    backward(x,y,n);
    return 0;
}