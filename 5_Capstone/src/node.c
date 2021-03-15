#include "../include/client.h"

INT main(INT argc, CHAR **argv) {
    client_t *client = create_client(PORTNO);

    create_socket(client);
    connect_socket(client, HOSTNAME);

    return 0;
}
