int alphaCompare(Car *, Car *);
int alphaCompare_r(Car *, Car *);

int speedCompare(Car *, Car *);
int speedCompare_r(Car *, Car *);

int priceCompare(Car *, Car *);
int priceCompare_r(Car *, Car *);

int (*getComparator(int n))(Car *, Car *);

void carGenerator(Car cars[]);