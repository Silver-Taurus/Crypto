# Socket Programming

## Files Included
1. <stdio.h>
    - This header file contains declarations used in most input and output.
    - It is typically included in all C programs.
2. <stdlib.h>
    - This header file defines four variable types
    - several macros
    - various functions
3. <string.h>
    - Contains bzero() and
    - memset()
4. <sys/types.h>
    - The header file contains definitions of a number of data types used in system calls.
5. <sys/socket.h>
    - The header file "socket.h" includes a number of definitions of structures needed for internet domain addresses.
6. <netinet/in.h>
    - The header file "in.h" contains constants and structures needed for internet domain addresses.
7. <netdb.h>
8. <unistd.h>

## Client-Server Model
1. Server side
    - On server side we have the following functions
        1. socekt()
        2. bind()
        3. listen()
        4. accept()
        5. read()
        6. write()
        7. close()

2. Client side
    - On client side we have the following functions
        1. socket()
        2. connect()
        3. read()
        4. write()
        5. close()


## Model Overview
1. Socket
    - It is present on the both sides.
    - It is used to create a socket.
    - socket() needs
        1. domain
            - Address family
            - (IPv4 or IPv6 i.e., network protocol)
            - AF_INET for IPv4
            - AF_INET6 for IPv6
        2. type
            - (TCP or UDP i.e., transport protocol)
            - SOCK_STREAM for TCP protocol
            - SOCK_DGRAM for UDP protocol
        3. protocol
            - 0 is the default
            - 0 is for the TCP protocol
    - It returns a socket file descriptor.
2. Bind
    - It is present on the server side.
    - When a socket is created using socket function it exists in a namespace, i.e., address family
    - but has no adress assigned to it.
    - Bind function assigns the address specified by the "addr",
    - to the socket referred by the file descriptor.
    - bind() needs
        1. Socket file descriptor
        2. pointer "addr" of type "struct sockaddr"
            - "struct sockaddr" contains
                - "sa_family" of type "sa_family_t"
                - "sa_data[14]" of type "char"
        3. address length "addrlen" of type "socklen_t"
    - It returns
        - 0 for success
        - -1 for failure
3. Listen
    - It is present on the server side.
    - It is used to listen the incoming connections or hits from the client side.
    - listen() needs
        1. Socket file descriptor
        2. backlog - number of connections that the server can handle at a time.
    - It returns
        - 0 for success
        - -1 for failure
4. Accept
    - It is on the server side
    - and is used to accept the connection from the client side
    - in order start the communicatioin between server and the client.
    - accept() needs
        1. Socket file descriptor
        2. "addr"
        3. addrlen
    - Function signature (argument list) is similar to the bind but
        - it waits for a connection function,
        - so that whenever a connection function is generated on the client side,
        - the accept function responds to it (till that time, it sleeps).
    - It also returns a file descriptor.
    - In future all the operations and communications are then performed on this new file descriptor.
5. Connect
    - Connect is on the client side
    - and will ask for the permission to communicate with the server.
    - It interacts with the accept function on the server side.
    - connect() needs
        1. Socket file descriptor
        2. "addr"
        3. "addrlen"
    - It returns
        - 0 for success
        - -1 for failure
6. Read
    - It is use to read the data, i.e., to receive the data
    - and can be present on the either side.
    - For every read on any side, there should be a write function on the other side.
    - read() needs
        1. New socket file descriptor
        2. buffer data (buffer is the string message that is being passed in communication)
        3. buffer size
7. Write
    - It is use to write the data, i.e., to send the data
    - and can be present on the either side.
    - For every write on any side, there should be a read function on the other side.
    - write() needs
        1. New socket file descriptor
        2. buffer data
        3. buffer size
8. Close
    - It can be present on the both sides.
    - If the server closes, client connection will automatically closes.
    - Opposite is not true, i.e., if the client connection closes, server can still goes on running
    - and communicating with other clients.
    