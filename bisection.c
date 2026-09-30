#include<stdio.h>
#include<math.h>
#include<adoguids.h>
double f(double x){
    return 3*(x*x*x) + 2*x - 2;
}

int main(){
    double a, b, c, tol;

    printf("Enter the interval a: ");
    scanf("%lf", &a);
    printf("Enter the interval b: ");
    scanf("%lf", &b);

    printf("%f\n", a);
    printf("%f\n", b);

    if (f(a) * f(b) > 0){
        printf("invalid input\n");
    }
    else{
        printf("Enter the tolerance: ");
        scanf("%lf", &tol);

        c = a; // initialize c in case loop doesn't run

        while (fabs(b - a) > tol){
            c = (a + b) / 2;

            if (fabs(f(c)) < tol){
                break; // root found, stop the loop
            }
            else if (f(a) * f(c) < 0){
                b = c;
            }
            else{
                a = c;
            }
        }

        printf("Root is: %f\n", c);
    }

    return 0;
}
