#include <stdio.h>

unsigned char CheckBit(unsigned int uValue);

int main()
{
    printf("%d\n", CheckBit(2));

    return 0;
}

unsigned char CheckBit(unsigned int uValue)
{
    int flag = 0;
    for (int i = 0; i < sizeof(uValue) * 8; i++)
    {
        if ((uValue & (1 << i)) && flag == 0)
        {
            flag = 1;
        }
        else if ((uValue & (1 << i)) && flag == 1)
        {
            return 0;
        }
    }
    return flag;
}