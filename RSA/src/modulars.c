#include "../include/modulars.h"

// ----- Function Definition -----
long modular_exponent(long b, long exp, long mod) {
    long c = 1;

    if (mod == 1)
        return 0;
    
    for(long exp_prime = 1; exp_prime <= exp; exp_prime++)
        c = (c * b) % mod;
    
    return c;
}
