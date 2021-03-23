#ifndef __RSA__
#define __RSA__

/*
    Limit to be used for the call to sieve_of_eratosthenes if
    not given prior to the rsa_keygen.

    This value MUST be positive and greater than 3.

    The higher the better.
*/
#define RSA_SIEVE_LIMIT 255

typedef struct {
    long n;
    long phi;
    long e;
    long d;
} t_rsa;


// ----- Function prototypes -----
// To generate RSA key
t_rsa rsa_keygen(long p, long q);

// To encrypt the message
long rsa_encrypt(long msg, long e, long n);

// To decrypt the cipher
long rsa_decrypt(long cipher, long d, long n);

#endif