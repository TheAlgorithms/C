#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    pid_t parents_id;

    id = getpid();
    parents_id = getppid();

    printf("ID: %d\n", id);
    printf("Parents ID: %d\n", parents_id);
    return 0;
}
