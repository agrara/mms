#include <stdio.h>

void Reverse(char *ptr);

int main()
{
    char *arr = "Hello";
    Reverse(arr);
    printf("%s\n", arr);
    return 0;
}

void Reverse(char *ptr)
{
    int i = 0;
    while (ptr[i])
    {
        i++;
    }

    for (int j = 0; j < (i / 2); j++)
    {
        char tmp;
        tmp = ptr[j];
        *(ptr + j) = 'a';
        ptr[i - j - 1] = 'b';
    }
}