#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;

    fd = open("dacp", O_WRONLY);
    write(fd, "Hello\n", 6);
    close(fd);
    return 0;
}


