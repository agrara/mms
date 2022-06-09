#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkValues(const double *a, const double *b, const double *c)
{
    if (pow(*b, 2) < 4 * (*a) * (*c))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int getValues(double *a, double *b, double *c)
{
    printf("Please, enter the values for a, b and c - ax^2 + bx + c = 0!\n");
    scanf("%lf %lf %lf", a, b, c);
    if (checkValues(a, b, c) == -1)
    {
        fprintf(stderr, "Invalid values supplied!\n");
        return -1;
    }
    else
        return 0;
}

int calculateResults(double *a, double *b, double *c, double *x1, double *x2, int *solCount)
{
    if (getValues(a, b, c) == 0)
    {
        if (*a == 0 && *b == 0 && *c != 0)
        {
            return -1;
        }
        else if (*a == 0 && *b == 0 && *c == 0)
        {
            *solCount = 3;
            return 0;
        }
        else if (*a == 0 && *b != 0 && *c == 0)
        {
            *x1 = 0;
            *solCount = 1;
            return 0;
        }
        else if (*a == 0 && *b == 0 && *c != 0)
        {
            return -1;
        }
        else
        {
            *x1 = (-1 * (*b) + sqrt(pow(*b, 2) - 4 * (*a) * (*c))) / (2 * (*a));
            *x2 = (-1 * (*b) - sqrt(pow(*b, 2) - 4 * (*a) * (*c))) / (2 * (*a));
            *solCount = (fabs(*x1 - *x2) < 1e-3) ? 1 : 2;
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int solCount;

    if (calculateResults(&a, &b, &c, &x1, &x2, &solCount) == 0)
    {
        if (solCount == 1)
        {
            printf("There is only one solution: x = %lf\n", x1);
        }
        else if(solCount == 3){
            printf("There are infinite number of solutions.\n");
        }
        else
        {
            printf("The solutions are: x1 = %lf, x2 = %lf\n", x1, x2);
        }
    }
    else
    {
        fprintf(stderr, "There is no solution!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}