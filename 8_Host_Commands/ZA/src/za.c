#include "za.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ---------- Functions ---------- */
za_req_t* create_za_request() {
    // Creating za command request structure
    za_req_t *za_request = (za_req_t *) malloc(sizeof(za_req_t));

    // Flushing the stdin
    FLUSH();

    // Initialize lmk scheme
    za_request->lmk_scheme = KEYBLOCK;

    // Initializing the pin format, pin_length and other fields
    initialize_pin_format(za_request);
    initialize_pin_length(za_request);
    initialize_fields(za_request);

    return za_request;
}

void initialize_pin_format(za_req_t *za_request) {
    // Take the input for pin format and initialize it
    input_pin_format(za_request);

    // Initialize the block size based on the pin format
    if (za_request->an_pin_format == '0')
        za_request->block_size = 32;
    else if (za_request->an_pin_format == '1')
        za_request->block_size = 48;
    else if (za_request->an_pin_format == '7')
        za_request->block_size = 64;
}

void initialize_pin_length(za_req_t *za_request) {
    // Take the input for pin length, validate it and then initialize it
    input_pin_length(za_request);

    // Create the pin field based on the pin length
    za_request->an_pin = (CHAR *) malloc(sizeof(CHAR) * atoi(za_request->an_pin_length));
}



/* ---------- Utility Functions ---------- */
void terminate(CHAR *msg, INT code) {
    STRERR("Terminating process... ");
    STRERR(msg);
    NL();
    NL();
    exit(code);
}

void input_pin_format(za_req_t *za_request) {
    CHAR pin_format;
    INT attempts;

    // Validation loop
    do {
        // Set number of attempts
        attempts = ATTEMPTS;;

        // User info to enter pin format
        STROUT("Enter the pin format 0/1/7 (Press Enter for default 7): ");
        pin_format = getchar();

        // Flush the stdin
        FLUSH();

        // Perform validation
        if (CHECK_DEFAULT_PIN_FMT(pin_format))
            za_request->an_pin_format = '7';
        else if (CHECK_VALID_PIN_FMT(pin_format))
            za_request->an_pin_format = pin_format;
        else {
            if (attempts == 0)
                terminate("Invalid PIN format... (3 attempts made!)", 4);
            else {
                attempts--;
                NL();
            }
        }
    } while (!(CHECK_VALID_PIN_FMT(pin_format)));
}

void input_pin_length(za_req_t *za_request) {
    CHAR pin_length[PIN_LEN + 1];
    INT attempts, check;

    // Validation loop
    do {
        // Set number of attempts
        attempts = ATTEMPTS;

        // User info to enter input of pin length
        if (za_request->an_pin_format == '0') {
            STROUT("Enter pin length >=6 and <=16: ");
            STRIN(pin_length);
            check = CHECK_VALID_PIN_LEN_0(pin_length);
        }
        else if (za_request->an_pin_format == '1') {
            STROUT("Enter pin length >=6 and <=20: ");
            STRIN(pin_length);
            check = CHECK_VALID_PIN_LEN_1(pin_length);
        }
        else {
            STROUT("Enter pin length >=6 and <=30: ");
            STRIN(pin_length);       
            check = CHECK_VALID_PIN_LEN_7(pin_length);
        }

        // Validation for the entered pin length
        if (check && !attempts)
            terminate("Invalid PIN length... (3 attempts made!)", 15);
        else {
            attempts--;
            NL();
        }

    } while (!check);

    // Initialize the pin length
    strcpy(za_request->an_pin_length, pin_length);
}

void input_pin_salt(za_req_t *za_request) {
    CHAR pin_salt[SALT_LEN + 1];
    INT attempts = ATTEMPTS;

    // Take the input for the pin salt and perform validation
    if (za_request->an_pin_format == '7') {
        // Validation loop
        do {
            // User info to enter pin salt
            STROUT("Enter pin salt of length 16 (press Enter for random salt): ");
            STRIN(pin_salt);

            // Remove the last newline character from the pin salt
            pin_salt[strcspn(pin_salt, "\n")] = 0;

            // Validate the pin salt
            if (!(CHECK_PIN_SALT(pin_salt)) && attempts == 0)
                terminate("Invalid PIN salt... (3 attemtps made!)", 16);
            else {
                attempts--;
                NL();
            }
        } while (!(CHECK_PIN_SALT(pin_salt)));

        // Initialize the pin salt
        strcpy(za_request->an_pin_salt, pin_salt);
    }
}