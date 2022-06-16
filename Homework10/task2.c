#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swapBytes(uint16_t *);

int main()
{

    uint16_t a = 32768;

    swapBytes(&a);
    printf("%d\n", a);

    return 0;
}

void swapBytes(uint16_t *word)
{
    int bit1 = (*word & 1);
    int bit16 = (*word & (1 << 15)) >> 15;
    *word = (bit1 == 0) ? *word & ~(1 << 15) : *word | (1 << 15);
    *word = (bit16 == 0) ? *word & ~1 : *word | 1;
}