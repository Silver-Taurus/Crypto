#include "socket_types.h"

#ifndef __CLIENT__
#define __CLIENT__

/*
    Defining a structure for the client
        - Common socklet elements
        - server (hostname / hostaddress)
        - server message buffer
        - client message buffer
*/
typedef struct client {
    socket_t sock_ele;
    HOSTENT *server;
    CHAR serv_buffer[BUFFER_SIZE];
    CHAR cli_buffer[BUFFER_SIZE];
} client_t;

/*
    Defining macros for providing functionality
        - Macro for typecasting of client_t for the thread functions
*/
#define client_ci ((client_t *) client)

/* ---------- Function Prototypes ---------- */
// Function to check for the termination condition of the process
void check_terminate(INT check, CHAR *msg);

// Function to create client
client_t* create_client(INT portno);

// Function to create socket
void create_socket(client_t *client);

// Function to connect on socket
void connect_socket(client_t *client, CHAR *hostname);

// Function to write on socket
void* write_socket(void *client);

// Function to read on socket
void* read_socket(void *client);

#endif