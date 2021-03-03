#ifndef __TYPES__
#define __TYPES__

// Giving an Alias to the datatype to be used later.
typedef long VAL_TYPE;

// Defining a Macro for the format specifier coresponding to the datatype used.
#define VAL_FS "%ld"

// Defining a Macro for the scanf
#define scan(x) scanf(VAL_FS, &x)

/*
Defining an enum to provide the boolean functionality.
    - False 0
    - True 1
*/
typedef enum boolean {
    False,
    True
} t_bool;

/*
Defining a struct to make a dynamic list to hold
    - max length of the list of type VAL_TYPE
    - length of the list of type VAL_TYPE
    - pointer to the list of type VAL_TYPE
*/
typedef struct list {
    VAL_TYPE max_length;
    VAL_TYPE length;
    VAL_TYPE* values;
} t_list;

/* ---------- Function Prototypes ---------- */
// Function to create a new list
t_list* create_new_list(VAL_TYPE length);

// Function to extend the length of an existing list
void extend_list(t_list* existing_list);

#endif