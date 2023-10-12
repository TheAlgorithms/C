/**
 * @file
 * @author [NVombat](https://github.com/NVombat)
 * @brief Server-side implementation of [TCP Half Duplex
 * Communication](http://www.tcpipguide.com/free/t_SimplexFullDuplexandHalfDuplexOperation.htm)
 * @see tcp_half_duplex_server.c
 *
 * @details
 * The algorithm is based on the simple TCP client and server model. However,
 * instead of the server only sending and the client only receiving data,
 * The server and client can both send data but only one at a time. This is
 * implemented by using a particular ordering of the `send()` and `recv()`
 * functions. When one of the clients or servers is sending, the other can only
 * receive and vice-versa. In this way, the Half Duplex Form of communication
 * can be represented using the TCP server-client model & socket programming
 */

#ifdef _WIN32
#define bzero(b, len) \
    (memset((b), '\0', (len)), (void)0) /**< BSD name not in windows */
#define close _close
#include <Ws2tcpip.h>
#include <io.h>
#include <winsock2.h>
#else
#include <netdb.h>  /// For structures returned by the network database library - formatted internet addresses and port numbers
#include <sys/socket.h>  /// For macro definitions related to the creation of sockets
#include <sys/types.h>  /// For definitions to allow for the porting of BSD programs
#include <unistd.h>
#endif
// #include <netinet/in.h>  /// For in_addr and sockaddr_in structures
#include <stdint.h>  /// For specific bit size values of variables
#include <stdio.h>  /// Variable types, several macros, and various functions for performing input and output
#include <stdlib.h>  /// Variable types, several macros, and various functions for performing general functions
#include <string.h>  /// Various functions for manipulating arrays of characters

#define PORT 8100  /// Define port over which communication will take place

/**
 * @brief Utility function used to print an error message to `stderr`.
 * It prints `str` and an implementation-defined error
 * message corresponding to the global variable `errno`.
 * @returns void
 */
void error()
{
    perror("Socket Creation Failed");
    exit(EXIT_FAILURE);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    /** Variable Declarations */
    uint32_t sockfd,
        conn;  ///< socket descriptors - Like file handles but for sockets
    char server_msg[10000],
        client_msg[10000];  ///< character arrays to read and store string data
                            /// for communication
    struct sockaddr_in server_addr,
        client_addr;  ///< asic structures for all syscalls and functions that
                      /// deal with internet addresses. Structures for handling
                      /// internet addresses

    /**
     * The TCP socket is created using the socket function
     *
     * AF_INET (Family) - it is an address family that is used to designate the
     * type of addresses that your socket can communicate with
     *
     * SOCK_STREAM (Type) - Indicates TCP Connection - A stream socket provides
     * for the bidirectional, reliable, sequenced, and unduplicated flow of data
     * without record boundaries. Aside from the bidirectionality of data flow,
     * a pair of connected stream sockets provides an interface nearly identical
     * to pipes
     *
     * 0 (Protocol) - Specifies a particular protocol to be used with the
     * socket. Specifying a protocol of 0 causes socket() to use an unspecified
     * default protocol appropriate for the requested socket type
     */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        error();  ///< Error if the socket descriptor has a value lower than 0 -
                  /// socket wasnt created
    }

    /**
     * Server Address Information
     *
     * The bzero() function erases the data in the n bytes of the memory
     * starting at the location pointed to, by writing zeros (bytes
     * containing '\0') to that area
     *
     * We bind the server_addr to the internet address and port number thus
     * giving our socket an identity with an address and port where it can
     * listen for connections
     *
     * htons - The htons() function translates a short integer from host byte
     * order to network byte order
     *
     * htonl - The htonl() function translates a long integer from host byte
     * order to network byte order
     *
     * These functions are necessary so that the binding of address and port
     * takes place with data in the correct format
     */
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;    /// Domain/Family to be used
    server_addr.sin_port = htons(PORT);  /// Port to be used
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("Server is running...\n");

    /**
     * This binds the socket descriptor to the server thus enabling the server
     * to listen for connections and communicate with other clients
     */
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error();  /// If binding is unsuccessful
    }

    /**
     * This is to listen for clients or connections made to the server
     *
     * The limit is currently at 5 but can be increased to listen for
     * more connections
     *
     * It listens to connections through the socket descriptor
     */
    listen(sockfd, 5);

    printf("Server is listening...\n");

    /**
     * When a connection is found, a socket is created and connection is
     * accepted and established through the socket descriptor
     */
    conn = accept(sockfd, (struct sockaddr *)NULL, NULL);

    printf("Server is connected...\n");

    /**
     * Communication between client and server
     *
     * The bzero() function erases the data in the n bytes of the memory
     * starting at the location pointed to, by writing zeros (bytes
     * containing '\0') to that area. The variables are emptied and then
     * ready for use
     *
     * First the SERVER is prompted to type a message which is read from
     * stdin and then sent over the connection that was established - the socket
     * - to be received by the client (send())
     *
     * The SERVER then waits for the client to reply. It then receives the reply
     * in the string variable and displays it (recv())
     *
     * The server and client can communicate till one of them exits the
     * connection
     *
     * Since the exchange of information between the server and client take
     * place one at a time this represents HALF DUPLEX COMMUNICATION
     */
    while (1)
    {
        bzero(&server_msg, sizeof(server_msg));
        bzero(&client_msg, sizeof(client_msg));

        /// Send message
        printf("\nEnter message here: ");
        fgets(server_msg, 10000, stdin);
        send(conn, server_msg, strlen(server_msg) + 1, 0);

        /// Receive Message
        recv(conn, client_msg, sizeof(client_msg), 0);
        printf("\nClient Message: %s\n", client_msg);
    }

    /// Close socket
    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}
