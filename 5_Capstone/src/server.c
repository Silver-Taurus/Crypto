#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Defining and Initializing the global variables
bool_t res = False;

void check_terminate(INT check, CHAR *msg) {
    if (check < 0) {
        perror(msg);
        exit(1);
    }
}

server_t* create_server(INT portno, INT connections) {
    // Create the new server instance
    server_t *new_server = (server_t *) malloc(sizeof(server_t));

    // Initialize the portno and addr_len in the socket element of the server
    new_server->sock_ele.portno = portno;
    new_server->sock_ele.addr_len = sizeof(SOCKADDR_IN);

    // Initialize the connections in the server
    new_server->connections = connections;

    return new_server;
}

void create_socket(server_t *server) {
    // Create the new socket and get the socket file descriptor
    server->sock_ele.sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check the error in creating the socket
    check_terminate(server->sock_ele.sockfd, SOCKET_ERROR);

    // Initialize the server address
    bzero(&server->sock_ele.serv_addr, server->sock_ele.addr_len);
}

void bind_socket(server_t *server) {
    // Initialize the server address fields for binding
    server->sock_ele.serv_addr.sin_family = AF_INET;
    server->sock_ele.serv_addr.sin_addr.s_addr = INADDR_ANY;
    server->sock_ele.serv_addr.sin_port = htons(server->sock_ele.portno);

    // Bind the socket
    INT bind_response = bind(server->sock_ele.sockfd, (SOCKADDR *) &server->sock_ele.serv_addr, server->sock_ele.addr_len);

    // Check for the error in binding the socket
    check_terminate(bind_response, BIND_ERROR);
}

void listen_socket(server_t *server) {
    // Listen on the socket
    INT listen_response = listen(server->sock_ele.sockfd, server->connections);

    // Check for the error in listening the socket
    check_terminate(listen_response, LISTEN_ERROR);
}

void accept_socket(server_t *server) {
    pthread_t read_id, write_id;

    // Accepting connection on socket
    server->newsockfd = accept(server->sock_ele.sockfd, (SOCKADDR *) &server->cli, &server->sock_ele.addr_len);

    // Check for the error on accepting the connection on the socket
    check_terminate(server->newsockfd, ACCEPT_ERROR);

    // Continuous communcation between clients and the server
    while(1) {
        // Initialize the cli_buffer and serv_buffer with 0
        bzero(server->cli_buffer, BUFFER_SIZE);
        bzero(server->serv_buffer, BUFFER_SIZE);

        pthread_create(&read_id, NULL, read_socket, server);

        pthread_create(&write_id, NULL, write_socket, server);

        pthread_join(write_id, NULL);

        if (res == True)
            break;

        pthread_join(read_id, NULL);
    }

    // Close the connection
    close(server->newsockfd);

    // Close the server
    close(server->sock_ele.sockfd);
}

void* read_socket(void *server) {
    // Read on the socket
    INT read_response = read(server_ci->newsockfd, (CHAR *) server_ci->cli_buffer, BUFFER_SIZE);

    // Check for the error on reading on the socket
    check_terminate(read_response, READ_ERROR);

    // Display the output
    fprintf(stdout, "Client: ");
    fprintf(stdout, STR_FS, server_ci->cli_buffer);

    // Clear the buffer
    bzero(server_ci->cli_buffer, BUFFER_SIZE);

    return NULL;
}

void* write_socket(void *server) {
    // Take the input from the server
    fgets(((server_t *) server)->serv_buffer, BUFFER_SIZE, stdin);

    // Write on the socket
    INT write_response = write(server_ci->newsockfd, (CHAR *) server_ci->serv_buffer, BUFFER_SIZE);

    // Check for the error on writing on the socket
    check_terminate(write_response, WRITE_ERROR);

    // Check for the close connection condition
    if (strncmp("Bye",server_ci->serv_buffer, 3) == 0)
        res = True;

    // Clear the buffer if connection is stil active
    bzero(server_ci->serv_buffer, BUFFER_SIZE);

    return NULL;
}
