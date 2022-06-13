#include "car.h"
#include <stdint.h>

typedef struct Car
{
    char *model[21];
    uint8_t maxspeed;
    double price;
} Car;

int alphaCompare(Car *Car1, Car *Car2)
{
    for (int i = 0; i < 20; i++)
    {
        if ((Car1->model[i] > Car2->model[i]) || (Car1->model[i] != 0 && Car2->model == 0))
        {
            return 1;
        }
        else if ((Car1->model[i] < Car2->model[i]) || (Car2->model[i] != 0 && Car1->model == 0))
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int alphaCompare_r(Car *Car1, Car *Car2)
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

int speedCompare(Car *Car1, Car *Car2)
{
    if (Car1->maxspeed > Car2->maxspeed)
    {
        return 1;
    }
    else if (Car2->maxspeed > Car1->maxspeed)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int speedCompare_r(Car *Car1, Car *Car2)
{
    if (Car1->maxspeed < Car2->maxspeed)
    {
        return 1;
    }
    else if (Car2->maxspeed < Car1->maxspeed)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int priceCompare(Car *Car1, Car *Car2)
{
    if (fabs(Car1->price - Car2->price) < 0.01)
    {
        return 0;
    }
    else if (Car1->price > Car2->price)
    {
        return 1;
    }
    else if (Car1->price < Car2->price)
    {
        return -1;
    }
}

int priceCompare_r(Car *Car1, Car *Car2)
{
    if (fabs(Car1->price - Car2->price) < 0.01)
    {
        return 0;
    }
    else if (Car1->price < Car2->price)
    {
        return 1;
    }
    else if (Car1->price > Car2->price)
    {
        return -1;
    }
}

int (*getComparator(int n))(Car *, Car *)
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

void carGenerator(Car cars[])
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        cars[i].model[0] = 65 + rand() % (90 + 1 - 65);
        int numChars = 3 + rand() % (9 + 1 - 3);
        for (int j = 0; j < numChars; j++)
        {
            cars[i].model[j] = 97 + rand() % (122 + 1 - 97);
            if (j == numChars - 1)
            {
                cars[i].model[j + 1] = 0;
            }
        }
        cars[i].maxspeed = 100 + rand() % (300 + 1 - 100);
        cars[i].price = (rand() % 10000000) / 100;
    }
}