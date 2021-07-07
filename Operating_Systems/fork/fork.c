#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;

    id = fork();

    if(0 == id) {
        printf("Child\n");
    } else {
        printf("Parent\n");
    }

    return 0;
}
