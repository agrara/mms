#include <stdio.h>

int main()
{
    // This is a direct solution with three numbers to use the file from task 1
    int firstNum, secondNum, thirdNum;
    scanf("%d %d %d", &firstNum, &secondNum, &thirdNum);
    if (firstNum < 0 || firstNum > 1 || secondNum < 0 || secondNum > 1 || thirdNum < 0 || thirdNum > 1)
    {
        fprintf(stderr, "Invalid data.\n");
        return 1;
    }
    printf("%d\n", firstNum ^= secondNum ^= thirdNum);
    return 0;
}

// call with data from file after compilation
// gcc xor.c -o xor; ./xor < dataFile