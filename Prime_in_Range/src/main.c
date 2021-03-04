/*
Objective: Given a range 'a' to 'b' entered by the user
    - find all prime numbers in between inluding a and b.
    - print the prime numbers.
    - print the sum of these prime numbers.
*/
#include<stdio.h>
#include <stdlib.h>
#include "../include/primes.h"

int main (void) {
    // Take the User input
    VAL_TYPE a, b;

    printf("Enter the number a and b: ");
    scan(a);
    scan(b);

    // Create the prime data
    t_primes *prime_data = create_prime_data(a, b, SQRT);

    // Find and dispaly the primes
    find_primes(prime_data);
    display(prime_data);
    
    // Free the prime data variable
    free(prime_data);

    return 0;
}
