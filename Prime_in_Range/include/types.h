#ifndef __TYPES__
#define __TYPES__

// Giving an Alias to the datatype to be used later.
typedef long VAL_TYPE;
typedef char SIEVE_VAL_TYPE;
typedef int INT_TYPE;

// Defining a Macro for the format specifier coresponding to the datatype used.
#define VAL_FS "%ld"
#define STRING_FS "%s"
#define CHAR_FS "%c"

// Define the LENGTH value
#define LENGTH 16

// Defining a Macro for the scanf and newline
#define scan(x) scanf(VAL_FS, &x)
#define nl() printf("\n")

/*
Defining an enum to provide the boolean functionality.
    - False 0
    - True 1
*/
typedef enum boolean {
    False,
    True
} t_bool;

/*
Defining an enum to set the type of algorithm to be used to find the primes in range.
    - SQRT for the sqrt prime finding algorithm.
    - SIEVE for the sieve_of_eratosthenes prime finding algorithm.
*/
typedef enum prime_algo_type {
    SQRT,
    SIEVE
} t_prime_algo_type;

#endif