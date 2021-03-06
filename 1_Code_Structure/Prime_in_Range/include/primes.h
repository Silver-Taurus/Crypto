#include "list.h"

#ifndef __PRIMES__
#define __PRIMES__

/*
Defining a structure primes and giving it an Alias - t_primes.

It stores
    - start number 'a'
    - end number 'b'
    - length of the list
    - list of prime numbers between' 'a' and 'b'
*/
typedef struct primes {
    VAL_TYPE a;
    VAL_TYPE b;
    t_prime_algo_type type;
    t_list *primes_list;
    VAL_TYPE sum;
} t_primes;

/* ---------- Function Prototypes ---------- */
// Function to create a prime data of type t_primes
t_primes* create_prime_data(VAL_TYPE a, VAL_TYPE b, t_prime_algo_type type);

// Function to provide the sqrt prime finding algorithm.
t_bool is_prime(VAL_TYPE num);

// Function to provide the sieve of eratosthenes algorithm.
void sieve_of_eratosthenes(t_primes *prime_data);

// Function to find the prime numbers and store them.
void find_primes(t_primes *prime_data);

// Function to display the info for the prime data.
void info(t_primes *prime_data);

// Function to display the prime numbers to the console.
void display(t_primes *prime_data);

#endif