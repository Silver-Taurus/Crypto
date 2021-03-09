#include <netinet/in.h>
#include <netdb.h>
#include "types.h"

#ifndef __SOCKETS__
#define __SOCKETS__

// Defining Alias regarding sockets to be used latter
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

// Defining the Macros to be used latter
#define BUFFER_SIZE 256
#define PORT 8080

// Defining a structure sockets
typedef struct socket {
    INT port;
    INT connections;
    INT client_length;
    INT sockfd;
    SOCKADDR_IN server_addr;
    SOCKADDR_IN client_addr;
    CHAR buffer[BUFFER_SIZE];
} t_socket;


/* ---------- Function Prototypes ---------- */
// Function to create new socket data
t_socket* create_new_socket_data(INT portno, INT connections);

// Function to create a new socket
void create_socket(t_socket *socket_data);

// Function to bind the host address
void bind_socket(t_socket *socket_data);

// Function to start listening for the clients
// Here, process will go in sleep mode and will wait for the incoming connections.
void listen_socket(t_socket *socket_data);

// Function to accept actual connections from the client and start communication
void accept_socket(t_socket *socket_data);

// Function to terminate the process if the response is less than 0
void check_terminate(INT response, CHAR *terminate_string);

#endif