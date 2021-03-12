#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void check_terminate(int check, char *msg) {
    if (check < 0) {
        perror(msg);
        exit(1);
    }
}

int main (int argc, char **argv) {
    /* Declare the variables*/
    int portno, sockfd, res;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Take the portno input
    portno = atoi(argv[2]);

    /* Create Socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    check_terminate(sockfd, "Error creating socket...");

    // Take the server input
    server = gethostbyname(argv[1]);

    // Check for the server hostname validation
    if (server == NULL)
        // Error output
        fprintf(stderr, "Error, no such host...");

    // Initialize server address
    bzero((char *) &server_addr, sizeof(server));
    server_addr.sin_family = AF_INET;

    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(portno);
    // Connect to server
    check_terminate(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)), "Connection Failed...");

    // Continuous communcation with the server
    while (1) {
        // Initialize the buffer with 0
        bzero((char *) buffer, BUFFER_SIZE);

        // Take input from the client
        fgets(buffer, BUFFER_SIZE, stdin);

        // Write Socket
        check_terminate(write(sockfd, (char *) buffer, BUFFER_SIZE), "Error writing socket...");

        // Clear the buffer
        bzero((char *) buffer, BUFFER_SIZE);

        // Read Socket
        check_terminate(read(sockfd, (char *) buffer, BUFFER_SIZE), "Error reading socket...");

        // Display the output
        fprintf(stdout, "Server: %s", buffer);

        /* Close connection condition */
        res = strncmp("Bye", buffer, 3);
        if (res == 0)
            break;
    }

    close(sockfd);

    return 0;
}
