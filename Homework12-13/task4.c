#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void Conv(int, char *);

int main()
{
    int16_t number = 16025;
    char string[7];

    Conv(number, string);
    printf("%s\n", string);

    return 0;
}

void Conv(int sValue, char *pBuffer)
{
    int digitsNum = 1;
    int digits[5];
    while (sValue / 10)
    {
        digits[6 - digitsNum] = abs(sValue % 10);
        digitsNum++;
        sValue /= 10;
        digits[6 - digitsNum] = abs(sValue % 10);
    }
    if (sValue < 0)
    {
        pBuffer[0] = '-';
    }
    else
    {
        pBuffer[0] = 32;
    }
    for (int i = 1; i < 6 - digitsNum; i++)
    {
        pBuffer[i] = 32;
    }
    for (int i = 6 - digitsNum; i < 6; i++)
    {
        pBuffer[i] = digits[i] + 48;
    }
    pBuffer[6] = '\n';
}
