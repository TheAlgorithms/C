/*
** client.c --
*/
////////////////////////////////////////////////////////////////////////////////
// Author       :   Nazmus Saqib
// Function     :   Client program -a stream socket client demo
// Description  :   The purpose of this program is to request file from the server on user specified localhost port, download and save the file
//                  and gracefully one the file is downloaded or server is halted.
//					the signal part is not working as intended. I do not have plan to fix it as of right now
//
// Inputs       :   ip address (only tested with 127.0.0.1)              = argv[1];
//                  port (port number of the server)      			     = argv[2];
//                  filename(requested file from the server)    		 = argv[3];
// Output       :   User requested file from the server. it saves in the directory this program is located
// other info   :   See server.c for more information about the function implementation since both were made to work together.
// Note         :   This client program may or may not work with other server program.
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#include <fcntl.h>

#define MAXDATASIZE 50//max number of bytes we can get at once

// get sockaddr, IPv4 or IPv6:
///
/// \param sa
/// \return socket address
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in *) sa)->sin_addr);
	}

	return &(((struct sockaddr_in6 *) sa)->sin6_addr);
}

int main(int argc, char *argv[]) {

	int sockfd; //socket flile descriptor. This is going to be close if there problem with something
	// otherwise it might create zombie.
	char buf[MAXDATASIZE]; //this the actual buffer which going to store the requested file data temporarily before writing to a file
	struct addrinfo hints, *servinfo, *p; //this structs was included in lab9 where the we developed this program further
	int rv;
	char s[INET6_ADDRSTRLEN], *ip, *port, *filename;

	if (argc != 4) {
		fprintf(stderr, "please put one address, port number and filename\n");
		exit(1);
	}
    // getting the ip, port and the filename from the client
	ip = argv[1];
	port = argv[2];
	filename = argv[3];


	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
    ///getting the address info for the socket
	if ((rv = getaddrinfo(ip, port, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and connect to the first we can
	for (p = servinfo; p != NULL; p = p->ai_next) {

		if ((sockfd = socket(p->ai_family, p->ai_socktype,
		                     p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			perror("client: connect");
			close(sockfd);
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *) p->ai_addr),
	          s, sizeof s);
	printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // all done with this structure
	char filenamecmd[100];
	strcpy(filenamecmd, "get "); //strcpy and strcat is deleting "get" from the filename
	strcat(filenamecmd, filename);
	if (send(sockfd, filenamecmd, strlen(filenamecmd), 0) == -1) //creating socket
		perror("send");

	int file_descriptor;

	if ((file_descriptor = open(filename, O_WRONLY | O_CREAT, 0644)) ==
	    -1) //open or create the user requested downloded file
	{
		perror("open");
		close(sockfd);
	}
	int receive;
	char *bye = "/cmsc257", *kill = "/kill";
	int write_f;


	while (1)
	{
		if ((receive = recv(sockfd, buf, MAXDATASIZE, 0)) <-1) //receiving the file constantly in 50 character increment
		{
			perror("receive");
			close(sockfd);
		}

		if (strstr(buf, bye)) //if the program receives "/cmsc 257" it will break out of the loop
		{
			break;
		}

		if ((write_f = write(file_descriptor, buf, receive)) == -1)//writing the content inside the buffer to the file.
		{
			perror("1st_write: ");
			close(sockfd);
			exit(0);
		}
		if (strstr(buf, kill)) //This function was created to when the sever halts due signals, before server crash it
			// will send "/kill" when the client receives it will do close the socket and file descriptor before exiting out
		{
			printf("Server halted!\n");
			close(sockfd);
			close(file_descriptor);
			exit(0);
		}
	}
	if ((write_f = write(file_descriptor, buf, receive-8 )) ==-1) //writing the last remaining file right before "/cmsc257"
	{
		perror("2nd_write\n");
		close(sockfd);
	}
	printf("File transferred successfully\n");
	close(file_descriptor);
	close(sockfd);


	return 0;
}

