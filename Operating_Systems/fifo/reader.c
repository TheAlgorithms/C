#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 128

int main(int argc, char const *argv[])
{
    int fd;
    unsigned char buff[BUFF_SIZE];

    fd = open("dacp", O_RDONLY);
    read(fd, buff, BUFF_SIZE);
    printf("Read buffer: %s\n", buff);
    close(fd);
    return 0;
}


