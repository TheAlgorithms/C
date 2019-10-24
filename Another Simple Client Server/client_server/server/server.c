/*
** server.c -- a stream socket server demo
 * Author:      Nazmus Saqib
 * Function:    Server Program
 * Description: This programs listens continuously to a designated port on local host for client program to connect
 *              and request a existing file. It can have multiple clients. 
 * Input:       port    =argv[1]
 * Output:      nothing. Just send file to the client over the localhost
 * Other Info:  In order to understand every part of this program, please look at the client.c on the client directory
 * Note:        This program may or may not work with other client programs (Not universally compatible)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define BACKLOG 5      // how many pending connections queue will hold
#define MAXDATASIZE 50  //max number of bytes we can get at once
int counter = 1;        //count the number of child
int status = 0;         //we need status to do counter -- in the child
int file_descriptor;    //file descriptor used in the child

// get sockaddr, IPv4 or IPv6:
int sockfd, new_fd;

// the below function return a socket address
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in *) sa)->sin_addr);
    }

    return &(((struct sockaddr_in6 *) sa)->sin6_addr);
}

void sig_func(int sig) //Signal function, upon catching signal it will send signal to the client to kill itself
//  and close its own file descriptor
{
    if (sig == SIGINT)
    {
        printf ("\nCaugth SIGINT!\nClosing the client and server programs \n");
    }
    char *bye = "/kill";
    if ((send (new_fd, bye, strlen (bye), 0)) == -1) //todo found a bug where only one client receive the signal when handling multiple signals (TA told me this problem is beyond this class) (update: found the problem, cant implement SIGCHILD to the child, only SIGINT needs to be implemented)
    {
        perror ("On sending signal to kill the client");
    } else
    {
        printf ("Sending kill command to the active clients\n");
    }
    close (new_fd); //file descriptor
    close (sockfd); //socket
    close (file_descriptor); //file descriptor in the child
    exit (0);
}

// \brief parent wait for the children to finish it process so that it can change the child counter
void child_handler(int sig)
{
    waitpid (-1, &status, WNOHANG);

    if (WEXITSTATUS(status) > 0)
    {
        counter--;
    }
}


int main(int argc, char *argv[])
{
    // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    int yes = 1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    char buf[MAXDATASIZE]; //this is where the file data will be store temporally before sending to the client
    char *port = argv[1];//getting the port from the user

    if (argc != 2)
    {
        perror ("One port please\n");
    }
    /// \brief setting up socket
    memset (&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    /// \brief Working like a DNS
    if ((rv = getaddrinfo (NULL, port, &hints, &servinfo)) != 0)
    {
        fprintf (stderr, "getaddrinfo: %s\n", gai_strerror (rv));
        return 1;
    }

    // loop through all the results and bind to the first we can
    /// \brief: setting up socket and binding the ip address to the socket
    for (p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket (p->ai_family, p->ai_socktype,
                              p->ai_protocol)) == -1)
        {
            perror ("server: socket");
            continue;
        }

        if (setsockopt (sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                        sizeof (int)) == -1)
        {
            perror ("setsockopt");
            exit (1);
        }

        if (bind (sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            close (sockfd);
            perror ("server: bind");
            continue;
        }

        break;
    }

    freeaddrinfo (servinfo); // all done with this structure
    /// \brief failed to bind
    if (p == NULL)
    {
        fprintf (stderr, "server: failed to bind\n");
        exit (1);
    }

    if (listen (sockfd, BACKLOG) == -1)
    {
        perror ("listen");
        exit (1);
    }

    int pid, numbytes, limit;
    limit = 5;
    printf ("server: waiting for connections...\n");


    while (1) // main accept() loop
    {
        sin_size = sizeof their_addr;
        new_fd = accept (sockfd, (struct sockaddr *) &their_addr,
                         &sin_size); // opening file descriptor new_fd means new file descriptor
//		printf("main counter: %d\n", counter);
        if (new_fd == -1)
        {
            perror ("accept");
            continue;
        }
        /// \brief keeping track of how many client the server has so that it doesn't overload the sever
        if (counter >= limit)
        {

            close (new_fd);

            continue;
        }
//		printf("main2 counter: %d\n", counter);
        pid = fork ();

        if (pid < 0)
        {
            perror ("fork");
            close (new_fd);
            exit (-1);

        }
            /// \brief this is the parent
        else if (pid > 0)
        {
            counter++;
            signal (SIGINT, sig_func); //catching the signal just for parent, there is other signal for the child

            /// \brief the bottom child handler is special, with this the parent can iterate or de-iterate the client counter.
            signal (SIGCHLD, child_handler);

        } else if (pid == 0)
        {
            signal (SIGINT, sig_func); //signal catcher for the child


//            raise (SIGUSER1);//trying to raise SIGUSER1 so that I can trigger it


//            sleep (10); //with sleep I can catch the signal by pressign ctrl C


            printf ("Number of client(s): %d\n", counter);


            inet_ntop (their_addr.ss_family, get_in_addr ((struct sockaddr *) &their_addr), s,
                       sizeof s); //this is where server connect with the clients
            printf ("server: got connection from %s\n", s);


            /// \brief get the file name
            if ((numbytes = recv (new_fd, buf, MAXDATASIZE - 1, 0)) == -1)
            {
                perror ("receive");
                exit (1);
            }
//			printf("After receive\n");
            buf[numbytes] = '\0';
            char *buf2 = buf + 4; // removing "get" from the file name
            printf ("Server: sent '%s'\n", buf2);

            /// \brief file descriptor is first defined here
            if ((file_descriptor = open (buf2, O_RDONLY)) == -1)
            {
                perror ("open");
                counter--;
                close (new_fd);
                exit (-1);
            }
//			printf("After open\n");
            int read_file;
            char buf3[50];
            /// \brief reading the user requested file in iteration of 50 and temporarily store in buf3
            while ((read_file = read (file_descriptor, buf3, 50)) != 0)
            {
                buf3[read_file] = '\0';
//				printf("%s\n", buf3);
                /// \brief sending to the client
                if ((send (new_fd, buf3, strlen (buf3), 0)) == -1)
                {
                    counter--;
                    perror ("send");
                    close (new_fd);
                }
//				printf("working after send\n");
            }
            char *bye = "/cmsc257";
            /// \brief sending the "/cmsc257" to the client so that client knows that its the EOF
            if ((send (new_fd, bye, strlen (bye), 0)) == -1)
            {
                counter--;
                perror ("send");
                close (new_fd);
            }
            printf ("File sent succesfully.\n");

            close (new_fd);

            exit (1);
        }


    }


}


