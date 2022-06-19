#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, m, p;

    scanf("%d", &n);
    double *arr = malloc(n * sizeof(double));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (double)rand() / RAND_MAX;
    }

    scanf("%d", &m);

    arr = realloc(arr, (n + m) * sizeof(double));

    for (int i = n; i < n + m; i++)
    {
        arr[i] = (double)rand() / RAND_MAX + 1;
    }

    scanf("%d", &p);

    arr = realloc(arr, (n + m + p) * sizeof(double));

    for (int i = n + m; i < n + m + p; i++)
    {
        arr[i] = (double)rand() / RAND_MAX + 2;
    }
    printf("Members of the array:\n");
    for (int i = 0; i < n + m + p; i++)
    {
        printf("%.2lf\n", arr[i]);
    }

    free(arr);

    return EXIT_SUCCESS;
}