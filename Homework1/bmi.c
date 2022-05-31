#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// I use "weigth" instead of "mass" as it is most common used regarding human biometrics
typedef struct structBiometrics
{
	double weigth;
	double heigth;
} Biometrics;

double bmiClassic(const double *weigth, const double *heigth);

double bmiNew(const double *weigth, const double *heigth);

double calculateBMI(const double *weigth, const double *heigth, double (*realCalculation)(const double *weigth, const double *heigth));

void getOption(int *option);

void printOptions();

void getBiometricData(double *data);

int main()
{

	int option = 0;
	Biometrics *bioData = (Biometrics *)malloc(sizeof(Biometrics));
	bioData->heigth = 0;
	bioData->weigth = 0;
	double (*realCalculation)(const double *, const double *) = NULL;

	printOptions();
	getOption(&option);
	printf("Please, enter your weigth:\n");
	getBiometricData(&bioData->weigth);
	printf("Please, enter your heigth:\n");
	getBiometricData(&bioData->heigth);

	switch (option)
	{
	case 1:
	{
		realCalculation = &bmiClassic;
		break;
	}
	case 2:
	{
		realCalculation = &bmiNew;
		break;
	}
	default:
	{
		free(bioData);
		fprintf(stderr, "Invalid option passed");
		return 1;
	}
	}

	printf("Your BMI is: %.2lf\n", calculateBMI(&bioData->weigth, &bioData->heigth, realCalculation));

	free(bioData);

	return 0;
}

double bmiClassic(const double *weigth, const double *heigth)
{
	return *weigth / pow((*heigth), 2);
}

double bmiNew(const double *weigth, const double *heigth)
{
	return 1.3 * (*weigth) / pow((*heigth), 2.5);
}

double calculateBMI(const double *weigth, const double *heigth, double (*realCalculation)(const double *weigth, const double *heigth))
{
	return realCalculation(weigth, heigth);
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

void printOptions()
{
	printf("Please select an option:\n");
	printf("1. Classic formua \n");
	printf("2. 2013 impoved formula\n");
}

void getBiometricData(double *data)
{
	while (!(*data > 0))
	{
		scanf("%lf", data);
		if (!(*data > 0))
		{
			printf("Please, enter a positive number greater than 0!\n");
		}
	}
}