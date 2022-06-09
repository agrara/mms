#include <stdio.h>

void maxNum(double, double, double);

int main()
{
    double firstNum, secondNum, thirdNum;
    scanf("%lf %lf %lf", &firstNum, &secondNum, &thirdNum);
    maxNum(firstNum, secondNum, thirdNum);
    return 0;
}

void maxNum(double firstNum, double secondNum, double thirdNum)
{
    double maxNum = (firstNum > secondNum) ? firstNum : secondNum;
    maxNum = (maxNum > thirdNum) ? maxNum : thirdNum;
    fprintf(stdout, "%.3lf\n", maxNum);
}

// gcc maxNm -o maxNum; ./maxnNum < dataFile