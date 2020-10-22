#include <stdio.h>
#include <pthread.h>

void* helloThread(void *data) {
    printf("Hello thread\n");
}

int main(int argc, char const *argv[])
{
    pthread_t tidHello;
    printf("Creating thread\n");
    pthread_create(&tidHello, NULL, helloThread, NULL);    
    printf("Created thread\n");
    pthread_join(tidHello, NULL);
    return 0;
}
