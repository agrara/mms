#include <stdio.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);

int main()
{
    printf("%d\n", bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa));
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...)
{
    unsigned int masksCount = 0;
    va_list args;

    va_start(args, bitscnt);
    for (int i = 0; i < count; i++)
    {
        unsigned int mask = va_arg(args, int);
        unsigned int bits = 0;
        for (int shift = 0; shift < 32; shift++)
        {
            if (mask & 1 << shift)
            {
                bits++;
            }
        }
        if (bits == bitscnt)
        {
            masksCount++;
        }
    }
    va_end(args);
    return masksCount;
}