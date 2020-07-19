// Write CPP code here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef HAS_UNISTD
#include <unistd.h>
#endif

#ifdef _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS  // will make the code invalid for next
                                         // MSVC compiler versions
#include <winsock2.h>
#define bzero(b, len) \
    (memset((b), '\0', (len)), (void)0)  // not defined in windows

#define read(a, b, c) recv(a, b, c, 0)
#define write(a, b, c) send(a, b, c, 0)
#define close closesocket
#else
// if not windows platform
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#endif

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;)
    {
        bzero(buff, sizeof(buff));
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0)
        {
            printf("Client Exit...\n");
            break;
        }
    }
}

#ifdef _WIN32
/** Cleanup function will be automatically called on program exit */
inline void cleanup() { WSACleanup(); }
#endif

int main()
{
#ifdef _WIN32
    // when using winsock2.h, startup required
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0)
    {
        perror("WSA Startup error: \n");
        return 0;
    }

    atexit(cleanup);  // register at-exit function
#endif

    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}
