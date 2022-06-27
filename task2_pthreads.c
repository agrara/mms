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
pthread_mutex_t mutex;

void *routine(void *args)
{
    pthread_mutex_lock(&mutex);
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
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char **argv)
{
    int sum = 0;
    pthread_mutex_init(&mutex, NULL);
    pthread_t th[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        pthread_create(th[i], NULL, &routine, (void *)argv[i]);
    }

    for (int i = 0; i < argc - 1; i++)
    {
        pthread_join(th[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}