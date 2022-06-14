#include <stdio.h>
#include <stdlib.h>

unsigned sumArrayDigits(const int *arr, size_t n);
unsigned sumDigits(int);

int main()
{
    int arr[] = {12, 34, 5, 70};
    printf("Sum of all digits in the array is %u\n", sumArrayDigits(arr, 4));

    return EXIT_SUCCESS;
}

unsigned sumDigits(int num)
{
    unsigned int sum = 0;
    do
    {
        sum += (num % 10);
        num /= 10;
    } while (num != 0);
    return sum;
}

unsigned sumArrayDigits(const int *arr, size_t n)
{
    unsigned sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += sumDigits(arr[i]);
    }
    return sum;
}