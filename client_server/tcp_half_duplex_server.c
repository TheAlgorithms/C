/**
 * @file
 * @author [NVombat](https://github.com/NVombat)
 * @brief Server side implementation of TCP Half Duplex Communication
 * @see tcp_half_duplex_server.c
 *
 * @details
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
    int sockfd, conn;
    char server_msg[10000], client_msg[10000];
    struct sockaddr_in server_addr, client_addr;

    // Creating the TCP Socket with specific family, type and protocol
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Server Address Information
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
        // Empty the contents of the variables in memory
        bzero(&server_msg, sizeof(server_msg));
        bzero(&client_msg, sizeof(client_msg));

        // Send and receive messages
        printf("\nEnter message here: ");
        // Read input from stdin
        fgets(server_msg, 10000, stdin);
        send(conn, server_msg, strlen(server_msg) + 1, 0);
        recv(conn, client_msg, sizeof(client_msg), 0);
        printf("\nClient Message: %s\n", client_msg);
    }

    // Close socket
    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}
