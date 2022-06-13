#include <stdio.h>
#include "car.h"
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int alphaCompare(void *Car1, void *Car2)
{
    for (int i = 0; i < 20; i++)
    {
        if ((((Car *)Car1)->model[i] > ((Car *)Car2)->model[i]) || (((Car *)Car1)->model[i] != 0 && ((Car *)Car2)->model == 0))
        {
            return 1;
        }
        else if ((((Car *)Car1)->model[i] < ((Car *)Car2)->model[i]) || (((Car *)Car2)->model[i] != 0 && ((Car *)Car1)->model == 0))
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int alphaCompare_r(void *Car1, void *Car2)
{
    if (alphaCompare(Car1, Car2) == 1)
    {
        return -1;
    }
    else if (alphaCompare(Car1, Car2) == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int speedCompare(void *Car1, void *Car2)
{
    if (((Car *)Car1)->maxspeed > ((Car *)Car2)->maxspeed)
    {
        return 1;
    }
    else if (((Car *)Car2)->maxspeed > ((Car *)Car1)->maxspeed)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int speedCompare_r(void *Car1, void *Car2)
{
    if (((Car *)Car1)->maxspeed < ((Car *)Car2)->maxspeed)
    {
        return 1;
    }
    else if (((Car *)Car2)->maxspeed < ((Car *)Car1)->maxspeed)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int priceCompare(void *Car1, void *Car2)
{
    if (fabs(((Car *)Car1)->price - ((Car *)Car2)->price) < 0.01)
    {
        return 0;
    }
    else if (((Car *)Car1)->price > ((Car *)Car2)->price)
    {
        return 1;
    }
    else if (((Car *)Car1)->price < ((Car *)Car2)->price)
    {
        return -1;
    }
}

int priceCompare_r(void *Car1, void *Car2)
{
    if (fabs(((Car *)Car1)->price - ((Car *)Car2)->price) < 0.01)
    {
        return 0;
    }
    else if (((Car *)Car1)->price < ((Car *)Car2)->price)
    {
        return 1;
    }
    else if (((Car *)Car1)->price > ((Car *)Car2)->price)
    {
        return -1;
    }
}

int (*getComparator(int n))(void *, void *)
{
    if (n < 1 || n > 6)
    {
        return NULL;
    }

    switch (n)
    {
    case 1:
        return alphaCompare;
        break; // for readability
    case 2:
        return alphaCompare_r;
        break;
    case 3:
        return speedCompare;
        break;
    case 4:
        return speedCompare_r;
        break;
    case 5:
        return priceCompare;
        break;
    case 6:
        return priceCompare_r;
        break;
    default:
        return NULL;
        break;
    }
}

void carGenerator(Car *cars[])
{
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        cars[i]->model[0] = (65 + rand() % (90 + 1 - 65));

        int numChars = 3 + rand() % (9 + 1 - 3);
        for (int j = 0; j < numChars; j++)
        {
            cars[i]->model[j] = (97 + rand() % (122 + 1 - 97));
            if (j == numChars - 1)
            {
                cars[i]->model[j + 1] = 0;
            }
        }
        cars[i]->maxspeed = 100 + rand() % (300 + 1 - 100);
        cars[i]->price = (double)(rand() % 10000000 + 1) / 100;
    }
}