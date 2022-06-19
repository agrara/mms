#include <stdio.h>
#include <string.h>

void Reverse(char *);

int main()
{
    char arr[50] = "Hello";
    Reverse(arr);
    printf("%s\n", arr);
    return 0;
}

void Reverse(char *ptr)
{
    size_t len = strlen(ptr);

    for (int i = 0; i < len / 2; i++)
    {
        ptr[i] ^= ptr[len - i - 1] ^= ptr[i] ^= ptr[len - i - 1];
    }
}