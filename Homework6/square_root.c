#include <stdio.h>

float mySqrt(int);

void main()
{
    int number;

    printf("Provide the number: \n");
    scanf("%d", &number);
    float sqrt = mySqrt(number);
    printf("The square root of '%d' is '%f'\n", number, sqrt);
}

float mySqrt(int num)
{
    if (num != 1)
    {
        float temp, sqrt;
        sqrt = num / 2;
        temp = 0;
        while (sqrt != temp)
        {
            temp = sqrt;
            sqrt = (num / temp + temp) / 2;
        }
        return sqrt;
    }
    return 1;
}