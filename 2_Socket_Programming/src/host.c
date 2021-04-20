#include "server.h"

INT main(INT argc, CHAR **argv) {
    server_t *server = create_server(PORTNO, CONNECTIONS);

    create_socket(server);
    bind_socket(server);
    listen_socket(server);
    accept_socket(server);

    return 0;
}