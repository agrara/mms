#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TINT 1
#define TCHAR 2
#define TFLOAT 3
#define TDOUBLE 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8

void printValue(const void *valuePtr, uint8_t flag);

int main()
{
    int n = 23;
    double num = 3.14;
    char symbol = 'A';

    printValue(&n, TINT);
    printValue(&num, TDOUBLE);
    printValue(&symbol, TCHAR);

    return EXIT_SUCCESS;
}

void printValue(const void *valuePtr, uint8_t flag)
{
    if (flag == 1)
    {
        printf("%d\n", *((int *)valuePtr));
    }
    else if (flag == 2)
    {
        printf("%c\n", *((char *)valuePtr));
    }
    else if (flag == 3)
    {
        printf("%.2f\n", *((float *)valuePtr));
    }
    else if (flag == 4)
    {
        printf("%.2lf\n", *((double *)valuePtr));
    }
    else if (flag == 5)
    {
        printf("%d\n", *((uint8_t *)valuePtr));
    }

    else if (flag == 6)
    {
        printf("%d\n", *((uint16_t *)valuePtr));
    }
    else if (flag == 7)
    {
        printf("%d\n", *((uint32_t *)valuePtr));
    }
    else if (flag == 9)
    {
        printf("%ld\n", *((uint64_t *)valuePtr));
    }
}