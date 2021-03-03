#include "../include/primes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_primes* create_prime_data(VAL_TYPE a, VAL_TYPE b, t_prime_algo_type type) {
    // Creating a prime data dynamically
    t_primes *prime_data = malloc(sizeof(t_primes));

    // Allocating the data to the prime data variable
    prime_data->a = a;
    prime_data->b = b;
    prime_data->type = type;

    // Creating the primes list of the prime data variable
    prime_data->primes_list = create_new_list();

    // Initializing the sum of prime data
    prime_data->sum = 0;

    return prime_data;
}

t_bool is_prime(VAL_TYPE num) {
    // If number is 1 or less than 1 return False
    if (num <= 1)
        return False;
    
    // Find the sqrt of the number in order to perform optimized search
    VAL_TYPE max_div = (VAL_TYPE) floorl(sqrtl(num));

    // Loop till the max_div and check for whether the num is prime or not
    for (VAL_TYPE i = 2; i <= max_div; i++) {
        if (!(num % i))
            return False;
    }

    return True;
}

void find_primes(t_primes *prime_data) {
    /* ---------- First check for the algo type to find the prime numbers ---------- */
    // SQRT method to find the prime numbers
    if (!prime_data->type) {
        t_bool res;

        // Loop through all the prime numbers one by one
        for (VAL_TYPE num = prime_data->a; num <= prime_data->b; num++) {
            // Get whether the number is prime or not
            res = is_prime(num);

            // Add the number to the list if its prime
            if (res) {
                prime_data->primes_list->values[prime_data->primes_list->length++] = num;
                prime_data->sum += num;
            }

            // If the length of the list reached its max length, extend the list
            if (prime_data->primes_list->length == prime_data->primes_list->max_length)
                extend_list(prime_data->primes_list);
        }
    }
}

void info(t_primes *prime_data) {
    // Output the info about the prime data
    printf("Prime Numbers in the range ");
    printf(VAL_FS, prime_data->a);
    printf(" and ");
    printf(VAL_FS, prime_data->b);
}

void display(t_primes *prime_data) {
    // Output text for display
    nl();
    info(prime_data);
    printf(" are: ");

    // Displaying the values in the primes list of prime data
    for (VAL_TYPE index = 0; index < prime_data->primes_list->length; index++) {
        printf(VAL_FS, prime_data->primes_list->values[index]);
        printf(" ");
    }

    nl();

    printf("Sum of ");
    info(prime_data);
    printf(" is: ");
    printf(VAL_FS, prime_data->sum);
    nl();
}