#include <stdio.h>
#include <stdint.h>

int clearBit(uint32_t *maskArr, size_t nitems, size_t bit);
int setBit(uint32_t *maskArr, size_t nitems, size_t bit);
int checkBit(uint32_t *maskArr, size_t len, size_t bit);

int main()
{

    return 0;
}

int clearBit(uint32_t *maskArr, size_t nitems, size_t bit)
{
    if (bit > 31)
        return -1;
    for (int i = 0; i < nitems; i++)
    {
        maskArr[i] &= ~(1 << bit);
    }
    return 0;
}

int setBit(uint32_t *maskArr, size_t nitems, size_t bit)
{
    if (bit > 31)
        return -1;
    for (int i = 0; i < nitems; i++)
    {
        maskArr[i] |= (1 << bit);
    }
    return 0;
}

int checkBit(uint32_t *maskArr, size_t len, size_t bit)
{
    if (bit > 31)
        return -1;
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", (maskArr[i] & (1 << bit)) >> bit);
    }
    return 0;
}