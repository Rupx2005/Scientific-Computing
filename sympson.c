#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + (x * x));
}

int main() {
    double x_0, x_n, h, s_o = 0, s_e = 0;
    int n;
    double x[100];
    double y[100];

    printf("Enter the value of x_0: ");
    scanf("%lf", &x_0);

    printf("Enter the value of x_n: ");
    scanf("%lf", &x_n);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error: n must be a positive even integer less than 100.\n");
    }

    h = (x_n - x_0) / n;

    for (int i = 0; i <= n; i++) {
        x[i] = x_0 + i * h;
        y[i] = f(x[i]);
    }

    for (int i = 1; i < n; i++) {
        if (i % 2 != 0) {
            s_o += y[i];
        } else {
            s_e += y[i];
        }
    }

    double t = (h / 3.0) * (y[0] + y[n] + 4 * s_o + 2 * s_e);

    printf("The result = %lf\n", t);

    return 0;
}

