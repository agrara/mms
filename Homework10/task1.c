#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint32_t n;
    scanf("%d", &n);
    for (int i = 31; i > -1; i--)
    {
        printf("%d", (n & (1 << i)) >> i);
    }
    putchar('\n');
    return 0;
}