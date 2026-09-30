#include<stdio.h>
#include<math.h>
int main() {
    int n,i,j,k;
    float a[10][11],x[10],factor;
    printf("Enter the number of Equations(n)");
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        for (j=1;j<=n;j++) {
            scanf("%f",&a[i][j]);
        }
    }
    printf("%d",a);
    for (k=0;k<n-1;k++) {
        for (i=k+1;i<n;i++) {
            factor=a[i][k]/a[k][k];
            for (j=k+1;j<n;j++) {
                factor = a[i][k]/a[k][k];
                for (j=k;j<=n;j++) {
                    a[i][j]=a[i][j]-a[k][j]*factor;
                }
            }
        }
        x[n-1]=a[n-1][n]/a[n-1][n-1];
        for (i=n-2;i>=0;i--) {
            x[i]=a[i][n];
            for (j=i+1;j<n;j++) {
                x[i]=x[i]-a[i][j]*x[j];
            }
            x[i]=x[i]/a[i][i];
        }
    }
    printf("The result is:");
    for (i=0;i<n;i++) {
        printf("x%d = %.2f\n",i+1,x[i]);
    }
    return 0;
}