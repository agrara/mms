#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Polygon
{
    double side1;
    double side2;
    double side3;
    double P;
    double S;

    double (*perimeter)(const double *, const double *, const double *);
    double (*area)(const double *, const double *, const double *);
} Polygon;

double trianglePerimeter(const double *side1, const double *side2, const double *side3)
{
    return *side1 + *side2 + *side3;
}

double triangleArea(const double *side1, const double *side2, const double *side3)
{
    double perimeter = trianglePerimeter(side1, side2, side3);
    return sqrt(perimeter * (perimeter - *side1) * (perimeter - *side2) * (perimeter - *side3));
}

double rectanglePerimeter(const double *side1, const double *side2, const double *side3)
{
    return 2 * (*side1 + *side2);
}

double rectangleArea(const double *side1, const double *side2, const double *side3)
{
    return (*side1) * (*side2);
}

void printOptions()
{
    printf("\n");
    printf("______________________________________\n");
    printf("Please select the type of the polygon:\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("______________________________________\n\n");
}

int getOption()
{
    int option;
    while (1)
    {
        printf("Select an option: ");
        scanf("%d", &option);
        if ((option == 1) || (option == 2))
        {
            return option;
        }
        else
        {
            printf("Please, select a valid option!\n");
        }
    }
}

void optionController(const int *option, Polygon *polygon)
{
    if (*option == 1)
    {
        polygon->perimeter = &trianglePerimeter;
        polygon->area = &triangleArea;
    }
    else if (*option == 2)
    {
        polygon->perimeter = &rectanglePerimeter;
        polygon->area = &rectangleArea;
    }
    else
    {
        fprintf(stderr, "Possible hacking detected! Exiting...");
        exit(EXIT_FAILURE);
    }
}

int checkSides(const double *side1, const double *side2, const double *side3, const int *option)
{
    if (*side1 > 0 && *side2 > 0 && *side3 > 0)
    {
        if (*option == 1)
        {
            if ((*side1 + *side2 > *side3) && (*side1 + *side3 > *side2) && (*side2 + *side3 > *side1))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (*option == 2)
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int getSides(double *side1, double *side2, double *side3, const int *option)
{
    printf("Enter sides: ");
    scanf("%lf", side1);
    scanf("%lf", side2);
    if (*option == 1)
    {
        scanf("%lf", side3);
    }
    else if (*option == 2)
    {
        *side3 = 1;
    }

    if (checkSides(side1, side2, side3, option))
    {
        return 0;
    }
    else
    {
        fprintf(stderr, "Wrong side values entered!\n");
        return -1;
    }
}

int main()
{
    int option;
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));

    printOptions();
    option = getOption();
    if (getSides(&polygon->side1, &polygon->side2, &polygon->side3, &option) == 0)
    {
        optionController(&option, polygon);
        (*polygon).P = polygon->perimeter(&polygon->side1, &(*polygon).side2, &polygon->side3);
        polygon->S = polygon->area(&(*polygon).side1, &polygon->side2, &polygon->side3);
        printf("\n");
        printf("The perimeter is %lf\n", polygon->P);
        printf("The area is %lf\n", (*polygon).S);
    }
    else
    {
        return EXIT_FAILURE;
    }

    free(polygon);
    return EXIT_SUCCESS;
}