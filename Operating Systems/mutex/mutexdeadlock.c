#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutexCount = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
// pthread_mutex_t mutexCount = PTHREAD_MUTEX_INITIALIZER;

void * incThread(void* data)  {
    while(1) {
        pthread_mutex_lock(&mutexCount);
        count++;
        printf("Inc: %d\n", count);
        pthread_mutex_unlock(&mutexCount);
    }
}

void * decThread(void* data)  {
    while(1) {
        pthread_mutex_lock(&mutexCount);
        printf("Locked once\n");
        pthread_mutex_lock(&mutexCount);
        printf("Locked second time\n");
        count--;
        printf("Dec: %d\n", count);
        pthread_mutex_unlock(&mutexCount);
        pthread_mutex_unlock(&mutexCount);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t incId, decId;
    pthread_create(&incId, NULL, incThread, NULL);
    pthread_create(&decId, NULL, decThread, NULL);
    pthread_join(incId, NULL);
    pthread_join(decId, NULL);
    pthread_mutex_destroy(&mutexCount);
    return 0;
}
