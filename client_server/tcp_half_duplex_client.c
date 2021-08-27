/**
 * @file
 * @author [NVombat](https://github.com/NVombat)
 * @brief Client side implementation of TCP Half Duplex Communication
 * @see tcp_half_duplex_client.c
 * @link
 * http://www.tcpipguide.com/free/t_SimplexFullDuplexandHalfDuplexOperation.htm
 *
 * The algorithm is based on the simple TCP client and server model. However
 * Instead of the server only sending and the client only receiving data,
 * The server and client can both send data but only one at a time. This is
 * implemented by using a particular ordering of the send() and recv()
 * functions. When one of the client or server is sending the other can only
 * receive and vice-versa. In this way the Half Duplex Form of communication can
 * be represented using the TCP server client model & socket programming
 */

// Imports
#include <netdb.h>  // For structures returned by the network database library - formatted internet addresses and port numbers
#include <netinet/in.h>  // Needed for in_addr and sockaddr_in structs
#include <stdio.h>  // Variable types, several macros, and various functions for performing input and output
#include <stdlib.h>  // Variable types, several macros, and various functions for performing general functions
#include <string.h>  // Various functions for manipulating arrays of characters
#include <sys/socket.h>  // Contains macro definitions related to the creation of sockets
#include <sys/types.h>  // Contains definitions to allow for the porting of BSD programs
#include <unistd.h>  // Defines miscellaneous symbolic constants and types, and declares miscellaneous functions

#define PORT 8100  // Define port over which communication will take place

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char serverResponse[10000], clientResponse[10000];

    // Socket descriptor used to create socket handle for TCP connection with
    // specific family, type and protocol
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Server information
    bzero(&server_addr, sizeof(server_addr));
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
        // Empty the contents of the variables in memory
        bzero(&serverResponse, sizeof(serverResponse));
        bzero(&clientResponse, sizeof(clientResponse));

        // Send and receive messages
        recv(sockfd, serverResponse, sizeof(serverResponse), 0);
        printf("\nServer message: %s \n", serverResponse);
        printf("\nEnter message here: ");
        fgets(clientResponse, 10000, stdin);
        send(sockfd, clientResponse, strlen(clientResponse) + 1, 0);
    }

    // Close Socket
    close(sockfd);
    printf("Client is offline...\n");
    return 0;
}
