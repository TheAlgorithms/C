#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Before exec\n");
    execl("/bin/ls", "/bin/ls", "-a", "-l", NULL);
    printf("After exec\n");
    return 0;
}



