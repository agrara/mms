#include <stdio.h>
#include <stdint.h>

unsigned bitsNCount(uint64_t mask);

int main()
{
    bitsNCount(65L);
    return 0;
}

unsigned bitsNCount(uint64_t mask)
{
    int count = 0;
    for (int i = 0; i < (sizeof(mask) * 8); i++)
    {
        if (mask & (1UL << i))
        {
            count++;
        }
    }

    printf("Nuber of 1 bits is %d\n", count);
}