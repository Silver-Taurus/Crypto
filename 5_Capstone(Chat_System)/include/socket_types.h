#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#ifndef __SOCKET_TYPES__
#define __SOCKET_TYPES__

/*
    Providing aliases for the data type to be used in the program
*/
typedef int INT;
typedef char CHAR;
typedef socklen_t SOCKLEN_T;
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct hostent HOSTENT;

/*
    Defining macros for the format specifiers to be used in the program
*/
#define INT_FS "%d"
#define CHAR_FS "%c"
#define STR_FS "%s"

/*
    Defining macros for the constants to be used in the program
*/
#define BUFFER_SIZE 256
#define PORTNO 8080
#define CONNECTIONS 1
#define HOSTNAME "localhost"

/*
    Defining macros to provide functionality in the program
*/
#define STROUT(str) fprintf(stdout, str)
#define OUT(format, var) fprintf(stdout, format, var)
#define NL() fprintf(stdout, "\n")
#define SOCKET_ERROR "Error in creating socket..."
#define BIND_ERROR "Error in binding socket..."
#define LISTEN_ERROR "Error in listening on socket..."
#define READ_ERROR "Error in reading on socket..."
#define WRITE_ERROR "Error in writing on socket..."
#define ACCEPT_ERROR "Error in accepting the connection on socket..."
#define HOST_ERROR "Error, no such host..."
#define CONNECT_ERROR "Error connecting to socket..."

/*
    Defining an enum for the boolean type
        - False (0)
        - True (1)
*/
typedef enum boolean {
    False,
    True
} bool_t;

/*
    Defining a structure for the common socket elements
*/
typedef struct socket {
    INT portno;
    INT sockfd;
    SOCKLEN_T addr_len;
    SOCKADDR_IN serv_addr;
} socket_t;

#endif