#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define size 10

void print(double m[size][size],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            printf("%.2lf\t",m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    double m[size][size];
    double x[size];
    int n;
    printf("Enter the no of terms : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter %d row with coefficient",i+1);
        for(int j=0;j<=n;j++){
            scanf("%lf",&m[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double ratio = m[j][i]/m[i][i];
            for(int k=0;k<=n;k++){
                m[j][k] = m[j][k] - ratio*m[i][k];
            }
            printf("\n");
            print(m,n);
        }
    }

    x[n-1] = m[n-1][n]/m[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        x[i] = m[i][n];
        for(int j=i+1;j<=n;j++){
            x[i] = x[i]-m[i][j]*x[j];
        }
        x[i] = x[i]/m[i][i];
    }

    for(int i=0;i<n;i++){
        printf("%lf ",x[i]);
    }

    return 0;
}