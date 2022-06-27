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

int sum = 0;
sem_t semaphore;

void *routine(void *args)
{
    sem_wait(&semaphore);
    FILE *fp;
    if (!fopen((char *)args, "r"))
    {
        perror("Fopen:");
    }
    int num;
    while (fscanf(fp, "%d", &num) != EOF)
    {
        sum += num;
    }
    fclose(fp);
    sem_post(&semaphore);
}

int main(int argc, char **argv)
{
    int sum = 0;
    sem_init(&semaphore, 0, 1);
    pthread_t th[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        pthread_create(th[i], NULL, &routine, (void *)argv[i]);
    }

    for (int i = 0; i < argc - 1; i++)
    {
        pthread_join(th[i], NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}