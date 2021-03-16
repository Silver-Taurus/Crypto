#include "socket_types.h"

#ifndef __SERVER__
#define __SERVER__

/*
    Defining a structure for the server
*/
typedef struct server {
    socket_t sock_ele;
    INT connections;
    INT newsockfd;
    SOCKADDR_IN cli;
    CHAR serv_buffer[BUFFER_SIZE];
    CHAR cli_buffer[BUFFER_SIZE];
} server_t;

/* ---------- Function Prototypes ---------- */
// Function to check for the termination condition of the process
void check_terminate(INT check, CHAR *msg);

// Function to create server
server_t* create_server(INT portno, INT connections);

// Function to create socket
void create_socket(server_t *server);

// Function to bind socket
void bind_socket(server_t *server);

// Function to listen on socket
void listen_socket(server_t *server);

// Function to accept on socket
void accept_socket(server_t *server);

// Function to read on socket
void read_socket(server_t *server);

// Function to write on socket
bool_t write_socket(server_t *server);

#endif