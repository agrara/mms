#include <stdio.h>
#include <string.h>

void VMirror(unsigned char *pImage);

int main()
{
    unsigned char arr[8] = {
        0x7F,
        0x40,
        0x40,
        0x7F,
        0x00,
        0x00,
        0x00};
    VMirror(arr);
    for (int i = 0; i < 8; i++)
    {
        printf("%x ", arr[i]);
    }
    putchar('\n');
    return 0;
}

void VMirror(unsigned char *pImage)
{
    for (int i = 0; i < 8; i++)
    {
        int num = pImage[i];
        for (int j = 0; j < 4; j++)
        {
            char left = (pImage[i] & (1 << j)) >> j;
            char right = (pImage[i] & (1 << (7 - j))) >> (7 - j);
            if (left != right)
            {
                if (left)
                {
                    pImage[i] |= 1 << (7 - j);
                }
                else
                {
                    pImage[i] &= ~(1 << (7 - j));
                }
                if (right)
                {
                    pImage[i] |= 1 << j;
                }
                else
                {
                    pImage[i] &= ~(1 << j);
                }
            }
        }
    }
}