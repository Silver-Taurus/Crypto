#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
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
    int portno, connections, sockfd, newsockfd, res;
    struct sockaddr_in server_addr, client_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    /* Take user inputs */
    portno = atoi(argv[1]);
    connections = atoi(argv[2]);

    /* Create Socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    check_terminate(sockfd, "Error creating socket...");

    /* Initialize the server address */
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    /* Bind Socket*/
    check_terminate(bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)), "Error binding socket...");

    /* Listen Socket */
    check_terminate(listen(sockfd, connections), "Error listening socket...");

    /* Accept Socket */
    clilen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, (socklen_t *) &clilen);
    check_terminate(newsockfd, "Error accepting on socket...");

    /* Continuous communication between clients and server */
    while (1) {
        // Initialize the buffer with 0
        bzero((char *) buffer, BUFFER_SIZE);

        // Read Socket
        check_terminate(read(newsockfd, (char *) buffer, BUFFER_SIZE), "Error reading socket...");

        // Display the output
        fprintf(stdout, "Client: %s", buffer);

        // Clear the buffer
        bzero((char *) buffer, BUFFER_SIZE);

        // Take the input from the server
        fgets(buffer, BUFFER_SIZE, stdin);

        // Write Socket
        check_terminate(write(newsockfd, (char *) buffer, BUFFER_SIZE), "Error writing socket...");

        /* Close connection condition */
        res = strncmp("Bye", buffer, 3);
        if (res == 0)
            break;
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}
