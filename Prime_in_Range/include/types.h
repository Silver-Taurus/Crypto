#ifndef __TYPES__
#define __TYPES__

// Giving an Alias to the datatype to be used later.
typedef long VAL_TYPE;

// Defining a Macro for the format specifier coresponding to the datatype used.
#define VAL_FS "%ld"

// Define the LENGTH value
#define LENGTH 16

// Defining a Macro for the scanf and newline
#define scan(x) scanf(VAL_FS, &x)
#define nl() printf("\n\n")

/*
Defining an enum to provide the boolean functionality.
    - False 0
    - True 1
*/
typedef enum boolean {
    False,
    True
} t_bool;

#endif