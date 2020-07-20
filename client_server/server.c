/**
 * @file
 * @author [Nairit11](https://github.com/Nairit11)
 * @author [Krishna Vedala](https://github.com/kvedala)
 * @brief Server side implementation of Server-Client system.
 * @see client_server/client.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #ifdef HAS_UNISTD
// #include <unistd.h>
// #endif

#ifdef _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS  // will make the code invalid for next
                                         // MSVC compiler versions
#include <winsock2.h>
#define bzero(b, len) \
    (memset((b), '\0', (len)), (void)0) /**< BSD name not in windows */
#define read(a, b, c) recv(a, b, c, 0)  /**< map BSD name to Winsock */
#define write(a, b, c) send(a, b, c, 0) /**< map BSD name to Winsock */
#define close closesocket               /**< map BSD name to Winsock */
#else
// if not windows platform
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#define MAX 80             /**< max. characters per message */
#define PORT 8080          /**< port number to connect to */
#define SA struct sockaddr /**< shortname for sockaddr */

#ifdef _WIN32
/** Cleanup function will be automatically called on program exit */
void cleanup() { WSACleanup(); }
#endif

/**
 * Continuous loop to send and receive over the socket.
 * Exits when "exit" is sent from commandline.
 * @param sockfd socket handle number
 */
void func(int sockfd)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;)
    {
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
        {
            ;
        }

        // and send that buffer to client
        write(sockfd, buff, sizeof(buff));

        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0)
        {
            printf("Server Exit...\n");
            break;
        }
    }
}

/** Driver code */
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
    unsigned int len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket creation failed...\n");
        exit(0);
    }
    else
    {
        printf("Socket successfully created..\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        perror("socket bind failed...\n");
        exit(0);
    }
    else
    {
        printf("Socket successfully binded..\n");
    }

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0)
    {
        perror("Listen failed...\n");
        exit(0);
    }
    else
    {
        printf("Server listening..\n");
    }
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)
    {
        perror("server acccept failed...\n");
        exit(0);
    }
    else
    {
        printf("server acccept the client...\n");
    }

    // Function for chatting between client and server
    func(connfd);

    // After chatting close the socket
    close(sockfd);
    return 0;
}
