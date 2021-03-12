#include "../include/list.h"
#include "../include/primes.h"
#include <stdlib.h>
#include <string.h>

t_list* create_new_list(t_prime_algo_type type, VAL_TYPE length) {
    // Creating a new list dynamically
    t_list *new_list = malloc(sizeof(t_list));

    // Creating the values array of new list based on the given length based on algo type
    if (type)
        new_list-> values = malloc(sizeof(SIEVE_VAL_TYPE) * length);
    else
        new_list->values = malloc(sizeof(VAL_TYPE) * length);

    // Initializing the length and values data of the new list based on algo type
    new_list->max_length = length;

    if (type) {
        new_list->length = length - 2;
        memset(new_list->values, 1, sizeof(SIEVE_VAL_TYPE) * length);
    }
    else {
        new_list->length = 0;
        memset(new_list->values, 0, sizeof(VAL_TYPE) * length);
    }

    return new_list;
}

void extend_list(t_list* existing_list) {
    // Creating a new values array of double length of that of the existing list's values array
    void *new_values = malloc(sizeof(VAL_TYPE) * existing_list->max_length * 2);

    // Initializing the new values array
    memset(new_values, 0, sizeof(VAL_TYPE) * existing_list->max_length * 2);

    // Copying the data of values array of existing list into the new values array
    for (VAL_TYPE index = 0; index < existing_list->length; index++)
        ((VAL_TYPE *) new_values)[index] = ((VAL_TYPE *) existing_list->values)[index];

    // Updating the length of the existing_list and the values array with the new values array
    // and free the old values
    existing_list->max_length *= 2;
    free(existing_list->values);
    existing_list->values = new_values;
}
