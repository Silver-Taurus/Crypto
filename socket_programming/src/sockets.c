#include "../include/sockets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_socket* create_new_socket_data(INT portno, INT connections) {
    // Creating new socket data
    t_socket *new_socket_data = (t_socket *)malloc(sizeof(t_socket));

    // Initializing the port, connections and client length
    new_socket_data->port = portno;
    new_socket_data->connections = connections;
    new_socket_data->client_length = sizeof(SOCKADDR_IN);

    return new_socket_data;
}

void create_socket(t_socket *socket_data) {
    /*
    Creating a new socket using socket() call
        - AF_INET is for IPv4 Network protocol
        - SOCK_STREAM is for TCP Transport protocol
        - 0 is for the protocol to be used

    In return we got a file descriptor for the socket in the sockfd.
    */
    socket_data->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check for the error during the creation of socket
    check_terminate(socket_data->sockfd, "Error opening socket...");

    // Initialize the server address
    memset((CHAR *) &socket_data->server_addr, 0, sizeof(socket_data->server_addr));
    socket_data->server_addr.sin_family = AF_INET;
    socket_data->server_addr.sin_addr.s_addr = INADDR_ANY;
    socket_data->server_addr.sin_port = htons(socket_data->port);
}

void bind_socket(t_socket *socket_data) {
    /*
    Bind the host address using bind() call
        - socket file descriptor
        - server address (in generic address format)
        - sizeof server address
    */
    INT bind_response = bind(socket_data->sockfd, (SOCKADDR *) &socket_data->server_addr, sizeof(socket_data->server_addr));

    // Check for the error during binding of the socket
    check_terminate(bind_response, "Error on binding...");
}

void listen_socket(t_socket *socket_data) {
    /*
    Listening using the listen() call
        - socket file descriptor
        - number of connections
    */
   INT listen_response = listen(socket_data->sockfd, socket_data->connections);

   // Check for the error during the listening of the socket
   check_terminate(listen_response, "Error listening...");
}

void accept_socket(t_socket *socket_data) {
    /*
    Accept the client connection using accept() call
        - socket file descriptor
        - client address holder (in generic address format)
        - length of the client address
    */
    INT new_sockfd = accept(socket_data->sockfd, (SOCKADDR *) &socket_data->client_addr, &socket_data->client_length);

    // Check for the error during the acceptance of the client
    check_terminate(new_sockfd, "Error on accept...");

    // If the connection is estalished then start communicating
    memset(socket_data->buffer, 0, BUFFER_SIZE);

    // INT node = read()
}

void check_terminate(INT response, CHAR *terminate_string) {
    if (response < 0) {
        perror(terminate_string);
        exit(1);
    }
}