#include <stdio.h>

int main()
{
    int n;
    double x[100], y[100][100];
    double term;
    double x_p;
    double h;
    double u;
    double sum;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of x[%d]: ", i);
        scanf("%lf", &x[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of y[%d]: ", i);
        scanf("%lf", &y[i][0]);
    }

    // Backward difference table
    for (int j = 1; j < n; j++
    )
    {
        for (int i = n - 1; i >= j; i--)
        {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    printf("\nBackward Difference Table:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%lf", x[i]);

        for (int j = 0; j <= i; j++)
        {
            printf("\t%lf", y[i][j]);
        }

        printf("\n");
    }

    printf("Enter the value of interpolation: ");
    scanf("%lf", &x_p);

    h = x[1] - x[0];

    u = (x_p - x[n - 1]) / h;

    sum = y[n - 1][0];
    term = 1;

    for (int j = 1; j < n; j++)
    {
        term = term * (u + (j - 1)) / j;
        sum = sum + term * y[n - 1][j];
    }

    printf("\nInterpolated value at x = %.4lf is %.6lf\n", x_p, sum);

    return 0;
}