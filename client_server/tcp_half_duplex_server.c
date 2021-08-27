/**
 * @file
 * @author [NVombat](https://github.com/NVombat)
 * @brief Client side implementation of TCP Half Duplex Communication
 * @see client_server/tcp_half_duplex_client.c
 */

// Imports
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
    // Creating the TCP Socket
    int sockfd, conn;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    char server_msg[1024];
    char client_msg[1024];

    // Server Address Information
    struct sockaddr_in server_addr, client_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("Server is running...\n");

    // Bind server to socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    listen(sockfd, 5);

    printf("Server is listening...\n");

    // Accepting a connection from the client
    conn = accept(sockfd, (struct sockaddr *)NULL, NULL);

    printf("Server is connected...\n");

    // Exchanging data one at a time - HALF DUPLEX
    while (1)
    {
        bzero(&server_msg, sizeof(server_msg));
        bzero(&client_msg, sizeof(client_msg));
        printf("\nEnter message here: ");
        fgets(server_msg, 10000, stdin);
        send(conn, server_msg, strlen(server_msg) + 1, 0);
        recv(conn, client_msg, sizeof(client_msg), 0);
        printf("\nClient Message: %s\n", client_msg);
    }

    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}
