#include <stdio.h>
#define MAX(x, y, z) ((x) > (y)) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z))
#define MIN(x, y, z) ((x) < (y)) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z))
#define SETBIT(mask, bit) mask |= (1 << bit)
#define CLEARBIT(mask, bit) mask &= ~(1 << bit)
#define INVERSEBIT(mask, bit) mask ^= (1 << bit)
#define CHECKBIT(mask, bit) (mask & (1 << bit)) >> bit
#define SWAP(a, b) a ^= b ^= a ^= b

int main()
{
    int a = 1, b = 3;
    printf("%d\n", MAX(1, 5, 3));
    printf("%d\n", MIN(4, 5, 3));
    printf("%d\n", CHECKBIT(1, 0));
    SWAP(a, b);
    printf("%d %d\n", a, b);
}