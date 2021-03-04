#include "types.h"

#ifndef __DSTRINGS__
#define __DSTRINGS__

/*
Defining a struct to make a dynamic string to hold
    - max length of the string of type VAL_TYPE
    - length of the string of type VAL_TYPE
    - pointer to the string of type CH_TYPE
*/
typedef struct dstring {
    VAL_TYPE max_length;
    VAL_TYPE length;
    CH_TYPE *content;
} t_str;

// Defining a macro for new line
#define nl() printf("\n")

// Defining a Macro to check whether the character ch is a vowel or not.
#define CEHCK_VOWEL(ch) ch == 'a' || ch == 'A' || ch == 'e' || ch =='E' || ch == 'i' || ch == 'I' || \
                        ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'

/* ---------- Function Prototypes ---------- */
// Function to create a new string
t_str* create_new_string();

// Function to extend the length of an existing string
void extend_string(t_str *existing_string);

// Function to take input to the string
void string_input(t_str *string);

// Function to Replace the vowels of the string with the given character
void replace(t_str *string, CH_TYPE ch);

// Function to display the string to the console
void display(t_str *string);

#endif