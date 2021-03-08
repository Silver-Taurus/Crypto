#include <netinet/in.h>
#include <netdb.h>
#include "types.h"

#ifndef __SOCKETS__
#define __SOCKETS__

// Defining Alias regarding sockets to be used latter
typedef struct sockaddr_in SOCKADDR_IN;

// Defining a structure sockets
typedef struct socket {
    INT sockfd;
    INT port;
    INT client_length;
    CHAR buffer[256];
    SOCKADDR_IN server_addr;
    SOCKADDR_IN client_addr;
    INT N;
} t_socket;


/* ---------- Function Prototypes ---------- */
void create_new_socket()

#endif