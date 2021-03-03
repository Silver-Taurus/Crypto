/*
Objective: Given a range 'a' to 'b' entered by the user
    - find all prime numbers in between inluding a and b.
    - print the prime numbers.
    - print the sum of these prime numbers.
*/
#include<stdio.h>
#include "../include/primes.h"

int main (void) {
    VAL_TYPE a, b;

    printf("Enter the number a and b: ");
    scan(a);
    scan(b);

    t_primes *prime_data = create_prime_data(a, b, SQRT);

    find_primes(prime_data);

    display(prime_data);
    
    return 0;
}
