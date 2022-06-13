#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include "car.h"

typedef struct Car
{
    char *model[21];
    uint8_t maxspeed;
    double price;
} Car;

int main()
{
    int option;
    Car carsArray[10];
    carGenerator(carsArray);

    scanf("%d", &option);

    getComparator(option);

    for (int i = 0; i < 10; i++)
    {
        printf("%s %d %lf\n", *(carsArray[i].model), carsArray[i].maxspeed, carsArray[i].price);
    }

    return 0;
}
