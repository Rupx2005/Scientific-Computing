#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, iteration;
    float a[10][10], b[10], x[10], old[10];
    float sum, error, tolerance = 0.0001;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter coefficients of equations:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }

        printf("Enter constant for equation %d: ", i + 1);
        scanf("%f", &b[i]);

        x[i] = 0; // Initial guess
    }

    for (iteration = 1; iteration <= 100; iteration++) {
        error = 0;

        for (i = 0; i < n; i++) {
            old[i] = x[i];

            sum = b[i];

            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum = sum - a[i][j] * x[j];
                }
            }

            x[i] = sum / a[i][i];

            if (fabs(x[i] - old[i]) > error) {
                error = fabs(x[i] - old[i]);
            }
        }

        if (error < tolerance) {
            break;
        }
    }

    printf("\nSolution:\n");

    for (i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    printf("Number of iterations = %d\n", iteration);

    return 0;
}
