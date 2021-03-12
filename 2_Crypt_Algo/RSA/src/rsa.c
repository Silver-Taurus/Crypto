#include "../include/modulars.h"
#include "../include/primes.h"
#include "../include/rsa.h"

static long	pick_e(long phi)
{
  //Ensure a list of pirmes has been generated
  //if length is 0, user didn't pass paramaters, use defined limit
  if (gen_prime_list.length == 0)
    sieve_of_eratosthenes(RSA_SIEVE_LIMIT);

  for (long i = 0; i < gen_prime_list.length; i++)
    {
      //This will simply pick the first, not a great idea,
      //but simple to understand algo
      if (gen_prime_list.primes[i] % phi != 0 && gcd(gen_prime_list.primes[i], phi) == 1)
	return gen_prime_list.primes[i];
    }

  //Value must be greater than 1, so this is sufficent to indicate failure
  return 0;
}

long		rsa_encrypt(long msg, long e, long n)
{
  return right_to_left(msg, e, n);
}

long		rsa_decrypt(long cyphertext, long d, long n)
{
  return right_to_left(cyphertext, d, n);
}

t_rsa		rsa_keygen(long p, long q)
{
  t_rsa		ret = { 0 };

  //Ensure that n >= 2**b where b is the number of bits per block
  //Example if encrypting a char, 2**8 = 256, thus n >= 256
  ret.n = p * q;
  ret.phi = (p - 1) * (q - 1);
  ret.e = pick_e(ret.phi);
  ret.d = modular_inverse(ret.e, ret.phi);
  return ret;
}