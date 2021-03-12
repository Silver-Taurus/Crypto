/*
Objective: Given a range 'a' to 'b' entered by the user
    - find all prime numbers in between inluding a and b.
    - print the prime numbers.
    - print the sum of these prime numbers.
*/
#include "../include/primes.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

t_prime_algo_type check_input(INT_TYPE argc, SIEVE_VAL_TYPE **argv) {
    printf("You can run the program using either");
    nl();
    printf(STRING_FS, argv[0]);
    nl();
    
    printf("command or,");
    printf("by providing options like ");
    nl();
    printf(STRING_FS, argv[0]);
    printf(" <algo_type>");
    nl();

    printf("0 for SQRT 1 for SIEVE (by default it is - 1).");
    nl();
    nl();

    if (argc == 1)
        return SIEVE;

    else if (argc == 2) {
        if (argv[1][0] == '0')
            return SQRT;
        else if (argv[1][0] == '1')
            return SIEVE;
        else {
            printf("Invalid <algo_type> ");
            printf(CHAR_FS, argv[1][0]);
            nl();

            printf("Proceeding with default...");
            nl();
            nl();
            return SIEVE;
        }
    }

    else {
        printf("Invalid argument count... Aborting");
        nl();
        exit(1);
    }
}


INT_TYPE main (INT_TYPE argc, SIEVE_VAL_TYPE **argv) {
    VAL_TYPE a, b;

    // Check the command arguments
    t_prime_algo_type type = check_input(argc, argv);

    // Console the Algo type
    printf("Algo used: ");
    
    if (type)
        printf("SIEVE");
    else
        printf("SQRT");
    
    nl();
    nl();

    // Take the User input
    printf("Enter the number a and b: ");
    scan(a);
    scan(b);

    // Create the prime data
    t_primes *prime_data = create_prime_data(a, b, type);

    // Find and dispaly the primes
    find_primes(prime_data);
    display(prime_data);
    
    // Free the prime data variable
    free(prime_data);

    return 0;
}
