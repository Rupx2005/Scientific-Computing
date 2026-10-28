#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + (x * x));
}

int main() {
    double x_0, x_n, n, h, s = 0 ;
    double x[100];
    double y[100];

    printf("Enter the value of x_0: ");
    scanf("%lf", &x_0);

    printf("Enter the value of x_n: ");
    scanf("%lf", &x_n);

    printf("Enter the value of n: ");
    scanf("%lf", &n);

    h = (x_n - x_0) / n;

    for (int i = 0; i <= n; i++) {
        x[i] = x_0 + i * h;
        y[i] = f(x[i]);
    }

    for (int j = 1; j <= n - 1; j++) {
        s = s + y[j];
    }

    double t = (h / 2) * (f(x_0) + f(x_n) + 2 * s);

    printf("The result = %lf\n", t);

    return 0;
}

