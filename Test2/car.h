
#include <stdint.h>

typedef struct Car
{
    char model[21];
    uint8_t maxspeed;
    double price;
} Car;

int alphaCompare(void *, void *);
int alphaCompare_r(void *, void *);

int speedCompare(void *, void *);
int speedCompare_r(void *, void *);

int priceCompare(void *, void *);
int priceCompare_r(void *, void *);

int (*getComparator(int n))(void *, void *);

void carGenerator(Car *cars[]);