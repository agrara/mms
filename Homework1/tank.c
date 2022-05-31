#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tank
{
	double l;
	double r;
	double h;
} Tank;

void printOptions();

void getOption(int *option);

void validateDimension(double *dim);

void getDimensionsVertical(Tank *tank);

void getDimensionsHorizontal(Tank *tank);

double calculateVolumeVertical(const Tank *tank);

double calculateVolumeHorizontal(const Tank *tank);

int main()
{
	int option = 0;
	Tank *tank = (Tank *)malloc(sizeof(Tank));
	void (*getDimensions)(Tank *) = NULL;
	double (*calculateVolume)(const Tank *) = NULL;

	printOptions();
	getOption(&option);

	switch (option)
	{
	case 1:
	{
		getDimensions = &getDimensionsVertical;
		calculateVolume = &calculateVolumeVertical;
		break;
	}
	case 2:
	{
		getDimensions = &getDimensionsHorizontal;
		calculateVolume = &calculateVolumeHorizontal;
		break;
	}
	default:
		free(tank);
		fprintf(stderr, "Illegal option passed");
		return 1;
		break;
	}

	getDimensions(tank);
	printf("The volume of the liquid is %.2lf\n", calculateVolume(tank));
	free(tank);

	return 0;
}

void printOptions()
{
	printf("Please select position of the tank:\n");
	printf("1. Vertical\n");
	printf("2. Horizontal\n");
}

void getOption(int *option)
{
	while (*option != 1 && *option != 2)
	{
		scanf("%d", option);
		if (*option != 1 && *option != 2)
		{
			printf("Please, enter a valid option!\n");
		}
	}
}

void validateDimension(double *dim)
{
	while (!(*dim > 0))
	{
		printf("The dimension can't be negative or zero, please enter a new value");
		scanf("%lf", dim);
	}
}

void getDimensionsVertical(Tank *tank)
{
	printf("Please, enter h:\n");
	scanf("%lf", &tank->h);
	validateDimension(&tank->h);
	printf("Please, enter r:\n");
	scanf("%lf", &tank->r);
	validateDimension(&tank->r);
	tank->l = 0;
}

void getDimensionsHorizontal(Tank *tank)
{
	printf("Please, enter l:\n");
	scanf("%lf", &tank->l);
	validateDimension(&tank->l);
	printf("Please, enter r:\n");
	scanf("%lf", &tank->r);
	validateDimension(&tank->r);
	printf("Please, enter h:\n");
	scanf("%lf", &tank->h);
	validateDimension(&tank->h);
}

double calculateVolumeVertical(const Tank *tank)
{
	return 3.14 * pow(tank->r, 2) * tank->h;
}

double calculateVolumeHorizontal(const Tank *tank)
{
	double sinAlpha;
	double alpha;
	double areaTriangle;
	double areaSegment;

	sinAlpha = 2 * (tank->r - tank->h) * sqrt(2 * tank->r * tank->h - pow(tank->h, 2)) / pow(tank->r, 2);
	alpha = asin(sinAlpha);
	areaSegment = pow(tank->r, 2) * alpha;
	areaTriangle = pow(tank->r, 2) * sinAlpha / 2;

	return (areaSegment - areaTriangle) * tank->l;
}