#ifndef __MODULAR_EXPONENT__
#define __MODULAR_EXPONENT__

/*
    Used by RSA for solving
        c = (msg ** e) mod n

    Uses the fact that:
        c mod n = (p * q) mod n
    is equivalent to
        c mod n = [(p mod n) *  (b mod n)] mod n

    Uses repeated multiplication with the modulo to obtain a result
    without having to store a large number for the modulo universe
*/
long modular_exponent(long b, long exp, long mod);

/*
    Optimized version of the above using Right to Left binary method

    Careful of overflows.
*/
long right_to_left(long b, long exp, long mod);

/*
    A number multiplied by its inverse is 1.

    In modulo arithmetic, the modular inverse exists,
        A % C == A ** -1

    Only numbers coprime to C have a modular inverse (mod C)

    Can be optimized using the Euclidean Algorithm
*/
long modular_inverse(long e, long phi);

#endif