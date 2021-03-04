/*
Objective: Given a string
    - reverse the words in the string
    - display the new string
*/
#include "../include/dstrings.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    // Create the string variable
    t_str *string = create_new_string();
    
    // Take the input in the string's content
    printf("Enter the string: ");
    string_input(string);

    // Reverse the words in the string's content
    reverse(string);

    // Display the new string to the console
    display(string);

    // Free the string variable
    free(string);

    return 0;
}