#include <stdio.h>
#include <stdlib.h>

int secondMax(const int *arr, size_t n, int *secondMax);

int main()
{
    int secondMaxValue;
    int arr[] = {12, 34, 5, 70, 46};
    if (!secondMax(arr, 5, &secondMaxValue))
    {
        printf("The secondMax value is %d\n", secondMaxValue);
    }
    return EXIT_SUCCESS;
}

int secondMax(const int *arr, size_t n, int *secondMax)
{
    if (n > 1)
    {
        *secondMax = (arr[0] < arr[1]) ? arr[0] : arr[1];
        int maxValue = (arr[0] > arr[1]) ? arr[0] : arr[1];
        for (int i = 2; i < n; i++)
        {
            if (arr[i] > maxValue)
            {
                *secondMax = maxValue;
                maxValue = arr[i];
            }
            else if (arr[i] > *secondMax && arr[i] < maxValue)
            {
                *secondMax = arr[i];
            }
        }
        if (*secondMax == maxValue)
        {
            fprintf(stderr, "All elements are equal!\n");
            return -1;
        }
        return 0;
    }
    else if (n == 0)
    {
        fprintf(stderr, "Empty array!\n");
        return -1;
    }
    else if (n == 1)
    {
        fprintf(stderr, "Array of one element only!\n");
        return -1;
    }
}