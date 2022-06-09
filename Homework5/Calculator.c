#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LIMIT 50

double addition(const double *firstNum, const double *secondNum)
{
    return *firstNum + *secondNum;
}

double subtraction(const double *firstNum, const double *secondNum)
{
    return *firstNum - *secondNum;
}

double multiplication(const double *firstNum, const double *secondNum)
{
    return *firstNum * *secondNum;
}

double division(const double *firstNum, const double *secondNum)
{
    if (*secondNum != 0)
    {
        return *firstNum / *secondNum;
    }
    else
    {
        fprintf(stderr, "The divisor can't be 0!\n");
        exit(EXIT_FAILURE);
    }
}

void operationController(const char *operation, double (**operationResult)(const double *firstNum, const double *secondNum))
{
    if (strcmp(operation, "+") == 0)
    {
        *operationResult = &addition;
    }
    else if (strcmp(operation, "-") == 0)
    {
        *operationResult = &subtraction;
    }
    else if (strcmp(operation, "x") == 0)
    {
        *operationResult = &multiplication;
    }
    else if (strcmp(operation, "/") == 0)
    {
        *operationResult = &division;
    }
    else
    {
        fprintf(stderr, "Illegal operation has been entered!\n");
        exit(EXIT_FAILURE);
    }
}

void printResult(const double *firstNum, const double *secondNum, const char *operation, const double *result)
{
    printf("%.2lf %s %.2lf = %.2lf\n", *firstNum, operation, *secondNum, *result);
}

void showErr()
{
    fprintf(stderr, "Illegal number of arguments entered\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{

    char userInput[MAX_LIMIT];
    double firstNum;
    double secondNum;
    char *operation;
    char *stopstring;
    int counter = 0;
    double (*operationResult)(const double *firstNum, const double *secondNum) = NULL;

    printf("Please enter an expresiion in the following format: x operation y\n");

    while (fgets(userInput, MAX_LIMIT, stdin))
    {
        const char delimiter[2] = " ";
        char *token;

        token = strtok(userInput, delimiter);

        while (token != NULL)
        {
            counter++;
            if (counter == 1)
            {
                if (token[0] == '\0')
                {
                    showErr();
                }
                firstNum = strtod(token, &stopstring);
            }
            else if (counter == 2)
            {
                operation = token;
            }
            else if (counter == 3)
            {
                secondNum = strtod(token, &stopstring);
            }
            else
            {
                showErr();
            }

            token = strtok(NULL, delimiter);
            if (token == NULL && counter != 3)
            {
                showErr();
            }
            counter = (token == NULL && counter == 3) ? 0 : counter;
        };

        operationController(operation, &operationResult);
        double result = operationResult(&firstNum, &secondNum);
        printResult(&firstNum, &secondNum, operation, &result);
    }
    return EXIT_SUCCESS;
}