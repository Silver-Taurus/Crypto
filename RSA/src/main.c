#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/rsa.h"
#include "../include/primes.h"

int main(int ac, char **av)
{
    long p, q;

    //Seed for random
    srandom(time(NULL));
    printf("This program can accept 3 paramaters or no paramaters.\n\n");
    printf("To use:\n%s <p> <q> <limit>\n%s\n\n", av[0], av[0]);
    printf("Paramaters: p and q for RSA keygen, limit is to limit the Sieve. \n");
    printf("If no paramaters are given random values will be used for p and q,\n");
    printf("and the Sieve will default to a defined value.\n\nStarting...\n\n");
    if (ac >= 4)
    {
        p = atol(av[1]);
        q = atol(av[2]);
        //Generate a list of prime numbers, used by keygen
        sieve_of_eratosthenes(atol(av[3]));
    }
    else
    {
        sieve_of_eratosthenes(RSA_SIEVE_LIMIT);

        //to generate p and q
        p = gen_prime_list.primes[random() % gen_prime_list.length];
        q = gen_prime_list.primes[random() % gen_prime_list.length];
    }
    printf("P used: %ld, Q used: %ld\n", p, q);

    //Generate RSA keys
    t_rsa results = rsa_keygen(p, q);

    //Output Results
    printf("P: %ld\nQ: %ld\nN: %ld\nphi(N): %ld\nChosen e: %ld\nd: %ld\n",
           p, q, results.n, results.phi, results.e, results.d);

    if (gen_prime_list.length != 0)
        free(gen_prime_list.primes);
    return 0;
}