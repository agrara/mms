#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <math.h>    // -lm
#include <pthread.h> // - ptread
#include <semaphore.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        FILE *fp;
        fopen(argv[i], "r");
        int num;
        while (fscanf(fp, "%d", &num) != EOF)
        {
            sum += num;
        }
        fclose(fp);
    }
    return 0;
}