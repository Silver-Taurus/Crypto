#include "../include/client.h"
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
    STROUT(" <hostname|hostaddress> <connections>");
    NL();
    NL();
}

INT main(INT argc, CHAR **argv) {
    // Declare input variables
    CHAR *host;
    INT portno;

    // Declare client instance
    client_t *client;

    // Take the input from the user and create the server based on those inputs
    if (argc < 2) {
        // Input variables status
        STROUT("Host and Portno not provided... Proceeding with the default");
        NL();
        STROUT("Host: ");
        OUT(STR_FS, HOSTNAME);
        NL();
        STROUT("Portno: ");
        OUT(INT_FS, PORTNO);
        NL();
        NL();

        // Display the info about the command
        display_command_info(argv[0]);

        // Set input variables
        host = HOSTNAME;
        portno = PORTNO;
    }

    else if (argc == 2) {
        // Input variables status
        STROUT("Portno not provided... Proceeding with the default");
        NL();
        STROUT("Portno: ");
        OUT(INT_FS, PORTNO);
        NL();
        NL();

        // Display the info about the command
        display_command_info(argv[0]);
        
        // Set input variables
        host = argv[1];
        portno = PORTNO;
    }

    else if (argc == 3) {
        // Set input variables
        host = argv[1];
        portno = atoi(argv[2]);
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

    // Create client instance
    client = create_client(portno);

    // Display program status
    STROUT("Starting connection process...");
    NL();
    NL();

    /* Make socket connection */
    create_socket(client);
    connect_socket(client, host);

    return 0;
}
