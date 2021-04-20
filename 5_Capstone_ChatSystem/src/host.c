#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>

void display_command_info(CHAR *command) {
    STROUT("You can either run command as,");
    NL();
    OUT(STR_FS, command);
    NL();
    STROUT("or as,");
    NL();
    OUT(STR_FS, command);
    STROUT(" <portno> <connections>");
    NL();
    NL();
}

INT main(INT argc, CHAR **argv) {
    // Declare input variables
    INT portno, connections;

    // Declare server instance
    server_t *server;

    // Take the input from the user and create the server based on those inputs
    if (argc < 2) {
        // Input variables status
        STROUT("Portno and Connections not provided... Proceeding with the default");
        NL();
        STROUT("Portno: ");
        OUT(INT_FS, PORTNO);
        NL();
        STROUT("Connections: ");
        OUT(INT_FS, CONNECTIONS);
        NL();
        NL();

        // Display the info about the command
        display_command_info(argv[0]);

        // Set input variables
        portno = PORTNO;
        connections = CONNECTIONS;
    }

    else if (argc == 2) {
        // Input variables status
        STROUT("Connections not provided... Proceeding with the default");
        NL();
        STROUT("Connections: ");
        OUT(INT_FS, CONNECTIONS);
        NL();
        NL();

        // Display the info about the command
        display_command_info(argv[0]);
        
        // Set input variables
        portno = atoi(argv[1]);
        connections = CONNECTIONS;
    }

    else if (argc == 3) {
        // Set input variables
        portno = atoi(argv[1]);
        connections = atoi(argv[2]);
    }

    else {
        // Input variables status
        STROUT("Invalid number of arguments... Aborting the process.");
        NL();
        NL();

        // Display the info about the command
        display_command_info(argv[0]);

        // Abort the process
        exit(1);
    }

    // Create server instance
    server = create_server(portno, connections);

    // Display program status
    STROUT("Starting connection process...");
    NL();
    NL();

    /* Make socket connection */
    create_socket(server);
    bind_socket(server);
    listen_socket(server);
    accept_socket(server);

    return 0;
}