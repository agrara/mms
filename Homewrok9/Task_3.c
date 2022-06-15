#include <stdio.h>
#include <math.h>

int binarySearch(int *array, size_t n, int key)
{
    int startIndex = 0;
    int endIndex = n - 1;
    int compIndex = (n - 1) / 2;
    do
    {
        if (key > array[compIndex])
        {
            startIndex = compIndex;
        }
        else if (key < array[compIndex])
        {
            endIndex = compIndex;
        }
        else
        {
            printf("The element with index %d has value %d.\n", compIndex, key);
            break;
        }
        int tmpIndex = compIndex;
        compIndex = (endIndex - startIndex) / 2 + startIndex;
        if (tmpIndex == compIndex)
        {
            compIndex++;
        }
        if (compIndex > endIndex)
        {
            printf("No elemet with the value of %d has been found.\n", key);
            break;
        }
    } while (1);
}

int main()
{
    int arr[] = {1, 4, 8, 11, 18, 23, 28};
    binarySearch(arr, 7, 0);
}