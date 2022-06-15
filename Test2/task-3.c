#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char num[501];

    scanf("%s", num);

    for (int i = 0; i < strlen(num); i++)
    {
        if (num[i] < '0' || num[i] > '9')
        {
            fprintf(stderr, "Invalid input!\n");
            return EXIT_FAILURE;
        }
        if (i % 2 != 0)
        {
            switch (num[i])
            {
            case '0':
                num[i] = '!';
                break;
            case '1':
                num[i] = '#';
                break;
            case '2':
                num[i] = '/';
                break;
            case '3':
                num[i] = '~';
                break;
            case '4':
                num[i] = '=';
                break;
            case '5':
                num[i] = '`';
                break;
            case '6':
                num[i] = '\\';
                break;
            case '7':
                num[i] = '>';
                break;
            case '8':
                num[i] = ',';
                break;
            case '9':
                num[i] = '.';
                break;
            }
        }
        else
        {
            num[i] += 'A' - '0';
        }
    }
    printf("%s\n", num);
    return 0;
}