#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 0;
sem_t semCount;

void * incThread(void* data)  {
    while(1) {
        sem_wait(&semCount);
        count++;
        printf("Inc: %d\n", count);
        sem_post(&semCount);
    }
}

void * decThread(void* data)  {
    while(1) {
        sem_wait(&semCount);
        count--;
        printf("Dec: %d\n", count);
        sem_post(&semCount);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t incId, decId;
    sem_init(&semCount, 0, 1);
    pthread_create(&incId, NULL, incThread, NULL);
    pthread_create(&decId, NULL, decThread, NULL);
    pthread_join(incId, NULL);
    pthread_join(decId, NULL);
    sem_destroy(&semCount);
    return 0;
}
