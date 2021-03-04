#include "types.h"

#ifndef __LIST__
#define __LIST__

/*
Defining a struct to make a dynamic list to hold
    - max length of the list of type VAL_TYPE
    - length of the list of type VAL_TYPE
    - pointer to the list of type VAL_TYPE
*/
typedef struct list {
    VAL_TYPE max_length;
    VAL_TYPE length;
    void* values;
} t_list;

/* ---------- Function Prototypes ---------- */
// Function to create a new list
t_list* create_new_list();

// Function to extend the length of an existing list
void extend_list(t_list* existing_list);

#endif