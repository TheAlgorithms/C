/**
 * @file
 * @author [NVombat](https://github.com/NVombat)
 * @brief Client side implementation of TCP Half Duplex Communication
 * @see tcp_half_duplex_client.c
 */

// Imports
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8100

int main()
{
    // Socket descriptor used to create socket handle
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    char serverResponse[1024];
    char clientResponse[1024];

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));

    // Filling Server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("Client is running...\n");

    // Connecting to server
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Client is connected...\n");

    // Sending & receiving data one at a time - HALF DUPLEX
    while (1)
    {
        bzero(&serverResponse, sizeof(serverResponse));
        bzero(&clientResponse, sizeof(clientResponse));
        recv(sockfd, serverResponse, sizeof(serverResponse), 0);
        printf("\nServer message: %s \n", serverResponse);
        printf("\nEnter message here: ");
        fgets(clientResponse, 10000, stdin);
        send(sockfd, clientResponse, strlen(clientResponse) + 1, 0);
    }

    close(sockfd);
    printf("Client is offline...\n");
    return 0;
}
