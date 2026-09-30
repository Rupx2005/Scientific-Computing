#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20][20], xp, h, u, sum;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    // Backward difference table
    for (j = 1; j < n; j++)
        for (i = n - 1; i >= j; i++)
            y[i][j] = y[i][j-1] - y[i-1][j-1];

    printf("\nBackward Difference Table:\n");

    for (i = 0; i < n; i++) {
        printf("%0.2f", x[i]);

        for (j = 0; j <= i; j++)
            printf("\t%0.2f", y[i][j]);

        printf("\n");
    }

    printf("\nEnter value of x to interpolate: ");
    scanf("%f", &xp);

    // Newton's Backward Interpolation Formula
    h = x[1] - x[0];

    u = (xp - x[n-1]) / h;

    sum = y[n-1][0];

    float term = 1;

    for (i = 1; i < n; i++) {
        term = term * (u + (i - 1)) / i;
        sum = sum + term * y[n-1][i];
    }

    printf("\nInterpolated value at x = %.2f is %.6f\n", xp, sum);

    return 0;
}