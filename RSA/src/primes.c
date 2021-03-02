#include <math.h>
#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include "../include/primes.h"

// Initializing the global variable
t_primes gen_prime_list = {0};

// ----- Function definition -----
// For Greatest Common Divisor
long gcd(long a, long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// For memory efficient way to determine whether a number is prime
char is_prime(long num) {
    if (num < 2)
        return 0;

    for (long i = 2; i < (long)lround(sqrtl(num)) + 1; i++) {
        if (num % i == 0)
            return 0;   
    }

    return 1;
}

// For sieve of eratosthenes
void sieve_of_eratosthenes(long limit) {
    long prime_optimization = (long)lround(sqrtl(limit)) + 1;
    long prime_count = limit - 2;

    char* primes = malloc(sizeof(char) * limit);

    memset(primes, 1, limit * sizeof(char));

    primes[0] = 0;
    primes[1] = 0;

    for (long i = 2; i < prime_optimization; i++) {
        if (primes[i]) {
            for (long j = i * i; j < limit; j += i) {
                if (primes[j]) {
                    primes[j] = 0;
                    prime_count--;
                }
            }
        }
    }

    if (gen_prime_list.length != 0)
        free(gen_prime_list.primes);

    gen_prime_list.limit_used = limit;
    gen_prime_list.length = prime_count;
    gen_prime_list.primes = malloc(sizeof(long) * prime_count);

    long index = 0;
    for (long i = 0; i < limit; i++) {
        if (primes[i]) {
            gen_prime_list.primes[index] = i;
            index++;
        }
    }

    free(primes);
}