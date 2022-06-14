#include <stdio.h>
#include <stdlib.h>

void arrayEvaluate(int *arr, size_t n, int (*f)(int *, int));
int arraySum(int *, int);

int main()
{
    int arr[] = {1, 2, 3};

    arrayEvaluate(arr, 3, arraySum);

    EXIT_SUCCESS;
}

int arraySum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void arrayEvaluate(int *arr, size_t n, int (*f)(int *, int))
{
    int sum = f(arr, n);
    printf("The sum of all members of the array is %d\n", sum);
}
