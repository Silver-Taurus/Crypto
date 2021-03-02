#include "../include/modulars.h"

// ----- Function Definition -----
long modular_exponent(long b, long exp, long mod)
{
    long c = 1;

    if (mod == 1)
        return 0;

    for (long exp_prime = 1; exp_prime <= exp; exp_prime++)
        c = (c * b) % mod;

    return c;
}

long right_to_left(long b, long exp, long mod)
{
    long ret = 1;

    if (mod == 1)
        return 0;
    b = b % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1) // if odd number
            ret = (ret * b) % mod;
        exp = exp >> 1;
        b = (b * b) % mod;
    }
    return ret;
}

long modular_inverse(long a, long c)
{
    a %= c;
    for (long i = 1; i < c; i++)
    {
        if ((a * i) % c == 1)
            return i;
    }
    return 0;
}