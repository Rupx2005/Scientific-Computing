#include<stdio.h>
#include<math.h>
double f(double x){
    return ((x*x*x) - 2*x - 5);
}
double df(double x){
    return (3*(x*x)-2);
}
int main(){
    double x_0,x_1,tol;
    int i;
    printf("Enter the Value of X_0:");
    scanf("%lf",&x_0);
    printf("Enter the Tolerence");
    scanf("%lf",&tol);
    while(fabs(x_1-x_0)<tol){
        x_1 = x_0 - (f(x_0)/df(x_0));
        x_0 = x_1;
        }
    printf("The approximate root:%lf\n",x_1);
    printf("Number of iterations:%d",i);
}
