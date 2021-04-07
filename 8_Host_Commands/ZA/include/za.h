#ifndef __ZA__
#define __ZA__

/*
    Providing aliases for the data type to be used in the program
*/
typedef int INT;
typedef unsigned int UINT;
typedef char CHAR;

/*
    Defining macros for the format specifiers to be used in the program
*/
#define INT_FS "%d"
#define UINT_FS "%u"
#define CHAR_FS "%c"
#define STR_FS "%s"

/*
    Creating an enum for the LMK scheme
*/
typedef enum scheme {
    VARIANT,
    KEYBLOCK
} lmk_scheme_t;

/*
    Defining macros to provide the constants to be used in the program
*/
#define PIN_LEN 2
#define SALT_LEN 16
#define LMK_ID_LEN 2
#define LMK_SCHEME KEYBLOCK
#define ATTEMPTS 3

/*
    Defining macros to provide functionality in the program
*/
#define STROUT(str) fprintf(stdout, str)
#define STRERR(str) fprintf(stderr, str)
#define STRIN(var) fgets(var, sizeof(var), stdin)
#define OUT(format, var) fprintf(stdout, format, var)
#define NL() fprintf(stdout, "\n")
#define FLUSH() fflush(stdin)
#define CHECK_DEFAULT_PIN_FMT(pin_format) pin_format == "\n"
#define CHECK_VALID_PIN_FMT(pin_format) pin_format == '0' || pin_format == '1' || pin_format == '7'
#define CHECK_VALID_PIN_LEN_0(pin_length) pin_length >= 6 && pin_length <= 16
#define CHECK_VALID_PIN_LEN_1(pin_length) pin_length >= 6 && pin_length <= 20
#define CHECK_VALID_PIN_LEN_7(pin_length) pin_length >= 6 && pin_length <= 30
#define CHECK_PIN_SALT(pin_salt) strlen(pin_salt) == SALT_LEN || strlen(pin_salt) == 0

/*
    Creating a structure for the ZA command message
*/
typedef struct za_req {
    lmk_scheme_t lmk_scheme;
    CHAR an_pin_format;
    UINT block_size;
    CHAR an_pin_length[PIN_LEN + 1];
    CHAR *an_pin;
    CHAR an_pin_salt[SALT_LEN + 1];
    CHAR delimiter;
    CHAR lmk_identifier[LMK_ID_LEN + 1];
} za_req_t;


/* ---------- Function Prototypes ---------- */
// Function to terminate the process
void terminate(CHAR* msg, INT code);

// Function to create a za command request structure
za_req_t* create_za_request();

// Function to initialize pin format and block size after taking input of pin format
void initialize_pin_fomat(za_req_t *za_request);

// Function to initialize pin length and create pin field after taking input of pin length
void initialize_pin_length(za_req_t *za_request);

// Function to initialize rest of the fields with the inputs taken from the user
void initialize_fields(za_req_t *za_request);

// Function to generate an alphanumeric pin
void generate_an_pin(za_req_t *za_request);

// Function to encrypt the pin using lmk
void encrypt_pin(za_req_t *za_request);

/* ---------- Utility Function Prototypes ---------- */
// Function to take input pin format as well check for the validation
void input_pin_format(za_req_t *za_request);

// Function to take input pin length as well check for the validation
void input_pin_length(za_req_t *za_request);

// Function to take input pin salt as well check for the validation
void input_pin_salt(za_req_t *za_request);

// Function to take input delimeter as well check for the validation
// void input_delimiter(za_req_t *za_request);

// Function to take input lmk identifier as well check for the validation
// void input_lmk_identifier(za_req_t *za_request);

#endif