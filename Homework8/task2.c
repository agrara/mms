#include <stdio.h>

void map(int *array, size_t n, int (*func)(int));

int main()
{

    return 0;
}

void map(int *array, size_t n, int (*func)(int))
{
    for (size_t i; i < n; i++)
    {
        array[i] = func(array[i]);
    }
}