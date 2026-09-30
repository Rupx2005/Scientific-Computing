#include <stdio.h>

int main() {
    int n;
    double x[100], y[100];
    double term;
    double x_p;
    double result = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    for (int j = 0; j < n; j++) {
        printf("Enter the value of x[%d]: ", j);
        scanf("%lf", &x[j]);
    }

    for (int k = 0; k < n; k++) {
        printf("Enter the value of y[%d]: ", k);
        scanf("%lf", &y[k]);
    }

    printf("Enter the value of x for which interpolation is required: ");
    scanf("%lf", &x_p);

    for (int i = 0; i < n; i++) {
        term = y[i];

        for (int j = 0; j < n; j++) {
            if (i != j) {
                term = term * (x_p - x[j]) / (x[i] - x[j]);
            }
        }

        result = result + term;
    }

    printf("The interpolated value is %lf\n", result);

    return 0;
}
