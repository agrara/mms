#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int floatDirectCompare(const float *a, const float *b)
{
    return (*a == *b);
}

int floatEpsilonCompare(const float *a, const float *b)
{
    return (fabs(*a - *b) < 10e-3f);
}

int floatEpsilonMaxNumCompare(const float *a, const float *b)
{
    return (fabs(*a - *b) < 10e-3f * fmaxf(fabs(*a), fabs(*b)));
}

int doubleDirectCompare(const double *a, const double *b)
{
    return (*a == *b);
}

int doubleEpsilonCompare(const double *a, const double *b)
{
    return (fabs(*a - *b) < 10e-3);
}

int doubleEpsilonMaxNumCompare(const double *a, const double *b)
{
    return (fabs(*a - *b) < 10e-3 * fmax(fabs(*a), fabs(*b)));
}

void printOptions()
{
    printf("\n");
    printf("Select an option:\n");
    printf("_________________________________________\n");
    printf("1. Direct compare\n");
    printf("2. Epsilon compare\n");
    printf("3. Epsilon compare depending on max(a, b)\n");
    printf("4. Exit\n");
    printf("_________________________________________\n");
}

int getOption()
{
    int option;
    int validOption;

    printf("Please enter an option: ");
    do
    {
        scanf("%d", &option);
        validOption = (option == 1 || option == 2 || option == 3 || option == 4);

        if (validOption)
        {
            return option;
        }
        else
        {
            printf("Enter a valid option: ");
        }
    } while (!validOption);
}

int optionController(const int *option, int (**floatCompare)(const float *a, const float *b), int (**doubleCompare)(const double *a, const double *b))
{
    if (*option == 1)
    {
        *floatCompare = &floatDirectCompare;
        *doubleCompare = &doubleDirectCompare;
    }
    else if (*option == 2)
    {
        *floatCompare = &floatEpsilonCompare;
        *doubleCompare = &doubleEpsilonCompare;
    }
    else if (*option == 3)
    {
        *floatCompare = &floatEpsilonMaxNumCompare;
        *doubleCompare = &doubleEpsilonMaxNumCompare;
    }
    else if (*option == 4)
    {
        printf("Exiting...\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        fprintf(stderr, "Posibble hacking detected! Exiting...\n");
        exit(EXIT_FAILURE);
    }
}

void floatResult(const float *a, const float *b, int (*floatCompare)(const float *, const float *))
{
    printf("\n");
    printf("a = %f, b = %f\n", *a, *b);
    if (floatCompare(a, b))
    {
        printf("Float comparison result: True.\n\n");
    }
    else
    {
        printf("Float comparison result: False.\n\n");
    }
}

void doubleResult(const double *a, const double *b, int (*doubleCompare)(const double *a, const double *b))
{
    printf("a = %lf, b = %lf\n", *a, *b);
    if (doubleCompare(a, b))
    {
        printf("Double comparison result: True.\n\n");
    }
    else
    {
        printf("Double comparison result: False.\n\n");
    }
}

int main()
{
    int option = 0;

    float af = 1.0f;
    float bf = 0.01f;
    double ad = 1.0;
    double bd = 0.01;

    int (*floatCompare)(const float *a, const float *b) = NULL;
    int (*doubleCompare)(const double *a, const double *b) = NULL;

    for (int i = 0; i < 100; ++i)
    {
        bf += 0.01f;
        bd += 0.01;
    }

    printOptions();
    option = getOption();
    optionController(&option, &floatCompare, &doubleCompare);
    floatResult(&af, &bf, floatCompare);
    doubleResult(&ad, &bd, doubleCompare);

    return EXIT_SUCCESS;
}