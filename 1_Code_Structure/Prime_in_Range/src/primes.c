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

    // Creating the primes list of the prime data variable based on algo type
    if (type)
        prime_data->primes_list = create_new_list(type, b + 1);
    else
        prime_data->primes_list = create_new_list(type, LENGTH);

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

void sieve_of_eratosthenes(t_primes *prime_data) {
    // Find the sqrt of the number in order to perform optimized search
    VAL_TYPE prime_opt = (VAL_TYPE) floorl(sqrtl(prime_data->primes_list->max_length));

    // Remove the first two numbers 0 and 1
    ((SIEVE_VAL_TYPE *) prime_data->primes_list->values)[0] = False;
    ((SIEVE_VAL_TYPE *) prime_data->primes_list->values)[1] = False;

    // Apply the Sieve of eratosthenes algo to find prime numbers and update length
    for (VAL_TYPE index = 2; index <= prime_opt; index++) {
        if (((SIEVE_VAL_TYPE *) prime_data->primes_list->values)[index]) {
            for (VAL_TYPE mul = index * index; mul < prime_data->primes_list->max_length; mul += index) {
                ((SIEVE_VAL_TYPE *) prime_data->primes_list->values)[mul] = False;
                prime_data->primes_list->length--;
            }
        }
    }
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
                ((VAL_TYPE *) prime_data->primes_list->values)[prime_data->primes_list->length++] = num;
                prime_data->sum += num;
            }

            // If the length of the list reached its max length, extend the list
            if (prime_data->primes_list->length == prime_data->primes_list->max_length)
                extend_list(prime_data->primes_list);
        }
    }

    // SIEVE of eratosthenes method to find the prime numbers
    else
        sieve_of_eratosthenes(prime_data);
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

    // Displaying the values in the primes list of prime data based on the algo type
    if (prime_data->type) {
        for (VAL_TYPE index = 0; index < prime_data->primes_list->max_length; index++)
            if (((SIEVE_VAL_TYPE *) prime_data->primes_list->values)[index]) {
                printf(VAL_FS, index);
                printf(" ");        
   
                // For the SIEVE method also calculate the sum
                prime_data->sum += index;
            }       
    }
    else {
        for (VAL_TYPE index = 0; index < prime_data->primes_list->length; index++) {
            printf(VAL_FS, ((VAL_TYPE *) prime_data->primes_list->values)[index]);
            printf(" ");
        }
    }

    nl();
    nl();

    printf("Sum of ");
    info(prime_data);
    printf(" is: ");
    printf(VAL_FS, prime_data->sum);
    nl();
}