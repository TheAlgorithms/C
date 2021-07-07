#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    
    id = fork();

    if(0 == id) {
        execl("/bin/ls", "/bin/ls", "-a", "-l", NULL);
    } else {
        printf("Parent: \n");
    }
    
    return 0;
}



