#include <math.h>
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

    for (int j = 0; j < n; j++)
    {
        printf("Enter the value of x[%d]: ", j);
        scanf("%lf", &x[j]);
    }

    for (int k = 0; k < n; k++)
    {
        printf("Enter the value of y[%d]: ", k);
        scanf("%lf", &y[k][0]);
    }

    // Forward difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    printf("\nForward Difference Table:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%lf", x[i]);

        for (int j = 0; j < n - i; j++)
        {
            printf("\t%lf", y[i][j]);
        }

        printf("\n");
    }

    printf("Enter the value of interpolation: ");
    scanf("%lf", &x_p);

    h = x[1] - x[0];

    u = (x_p - x[0]) / h;

    sum = y[0][0];
    term = 1;

    for (int j = 1; j < n; j++)
    {
        term = term * (u - (j - 1)) / j;
        sum = sum + term * y[0][j];
    }

    printf("\nInterpolated value at x = %.4lf is %.6lf\n", x_p, sum);

    return 0;
}

