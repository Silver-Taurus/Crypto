#include "../include/client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Decalaring and Initializing the global variable
bool_t res = False;

void check_terminate(INT check, CHAR *msg) {
    if (check < 0) {
        perror(msg);
        exit(1);
    }
}

client_t* create_client(INT portno) {
    // Create the new client instance
    client_t *new_client = (client_t *) malloc(sizeof(client_t));

    // Initialize the portno and addr_len in the socket element of the server
    new_client->sock_ele.portno = portno;
    new_client->sock_ele.addr_len = sizeof(SOCKADDR_IN);

    return new_client;
}

void create_socket(client_t *client) {
    // Create the new socket and get the socket file descriptor
    client->sock_ele.sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check the error in creating the socket
    check_terminate(client->sock_ele.sockfd, SOCKET_ERROR);
}

void connect_socket(client_t *client, CHAR *hostname) {
    pthread_t read_id, write_id;

    // Store the hostname
    client->server = gethostbyname(hostname);

    // Check for the validaty of hostname
    if (client->server == NULL)
        fprintf(stderr, HOST_ERROR);
    
    // Initialize the server address
    bzero(&client->sock_ele.serv_addr, client->sock_ele.addr_len);

    // Initialize the server address fields
    client->sock_ele.serv_addr.sin_family = AF_INET;
    bcopy(client->server->h_addr, &client->sock_ele.serv_addr.sin_addr.s_addr, client->server->h_length);
    client->sock_ele.serv_addr.sin_port = htons(client->sock_ele.portno);

    // Connect to server
    INT connect_response = connect(client->sock_ele.sockfd, (SOCKADDR *) &client->sock_ele.serv_addr, client->sock_ele.addr_len);

    // Check for the error in the connection to the server
    check_terminate(connect_response, CONNECT_ERROR);

    // Continuous communication with the server
    while(1) {
        // Initialize the cli_buffer and serv_buffer with 0
        bzero(client->cli_buffer, BUFFER_SIZE);
        bzero(client->serv_buffer, BUFFER_SIZE);

        pthread_create(&write_id, NULL, write_socket, client);

        pthread_create(&read_id, NULL, read_socket, client);

        pthread_join(read_id, NULL);

        if (res == True)
            break;
    }

    // Close the client and the connection
    close(client->sock_ele.sockfd);
}

void* write_socket(void *client) {
    // Take the input from the server
    fgets(client_ci->cli_buffer, BUFFER_SIZE, stdin);

    // Write on the socket
    INT write_response = write(client_ci->sock_ele.sockfd, (CHAR *) client_ci->cli_buffer, BUFFER_SIZE);

    // Check for the error on writing on the socket
    check_terminate(write_response, WRITE_ERROR);

    // Clear the buffer
    bzero(client_ci->cli_buffer, BUFFER_SIZE);

    return NULL;
}

void* read_socket(void *client) {
    // Read on the socket
    INT read_response = read(client_ci->sock_ele.sockfd, (CHAR *) client_ci->serv_buffer, BUFFER_SIZE);

    // Check for the error on reading on the socket
    check_terminate(read_response, READ_ERROR);

    // Display the output
    fprintf(stdout, "Server: ");
    fprintf(stdout, STR_FS, client_ci->serv_buffer);

    // Check for the close connection condition
    if (strncmp("Bye", client_ci->serv_buffer, 3) == 0)
        res = True;

    // Clear the buffer if connection is stil active
    bzero(client_ci->serv_buffer, BUFFER_SIZE);
    
    return NULL;
}
