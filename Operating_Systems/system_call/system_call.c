#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;

    fd = open("dac.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if(-1 == fd) {
        perror("Error in opening file\n");
    } else {
        printf("File opened with descriptor %d\n", fd);
        write(fd, "Hello\n", 6);
        close(fd);
    }

    return 0;
}
