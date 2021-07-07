#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int id;
    int pipe_comm[2];
    unsigned char buff[128];
    int read_result, write_result;

    pipe(pipe_comm);
    printf("1st: %d\n2nd: %d\n", pipe_comm[0], pipe_comm[1]);

    id = fork();

    if(0 == id) { // Child
        close(pipe_comm[1]);
        read_result = read(pipe_comm[0], buff, 128);
        printf("Child: Read %d bytes\nBuffer: %s\n", read_result, buff);
    } else { // Parent
        close(pipe_comm[0]);
        write_result = write(pipe_comm[1], "Hello\n", 6);
        printf("Parent: Wrote %d bytes\n", write_result);
    }

    return 0;
}
