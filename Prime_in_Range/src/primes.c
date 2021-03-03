#include "../include/primes.h"
#include <math.h>

t_bool is_prime(VAL_TYPE num) {
    if (num <= 1)
        return False;
    
    VAL_TYPE max_div = (VAL_TYPE)floorl(sqrtl(num));

    for (VAL_TYPE i = 2; i <= max_div; i++) {
        if (!(num % i))
            return False;
    }

    return True;
}

void find_primes(t_primes* prime_data) {
    if (!prime_data->type) {
        t_bool res;

        for (VAL_TYPE num = prime_data->a; num <= prime_data->b; num++) {
            res = is_prime(num);
        }
    }
}