#ifndef __PRIMES__
#define __PRIMES__

// Giving an Alias to the datatype to be used later.
typedef long VAL_TYPE;

// Defining a Macro for the format specifier coresponding to the datatype used.
#define VAL_FS "%ld"

/*
Defining an enum to provide the boolean functionality.
    - False 0
    - True 1
*/
typedef enum bool {
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

/*
Defining a structure primes and giving it an Alias - t_primes.

It stores
    - start number 'a'
    - end number 'b'
    - length of the list
    - list of prime numbers between' 'a' and 'b'
*/
typedef struct primes {
    t_prime_algo_type type;
    VAL_TYPE a;
    VAL_TYPE b;
    VAL_TYPE length;
    VAL_TYPE *list;
} t_primes;

/* ---------- Function Prototypes ---------- */
// Function to provide the sqrt prime finding algorithm.
t_bool is_prime(VAL_TYPE num);

// Function to provide the sieve of eratosthenes algorithm.
void sieve_of_eratosthenes(VAL_TYPE num);

// Function to find the prime numbers in the range using the sqrt functionality.
void find_primes(t_primes* prime_data);

#endif