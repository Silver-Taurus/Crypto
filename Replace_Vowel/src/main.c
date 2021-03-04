/*
Objective: Given a string and a character
    - replace all the vowels in the string with that character
    - display the new string
*/
#include "../include/dstrings.h"
#include <stdio.h>
#include <ctype.h>

int main(void) {
    // Create the string and character variables
    t_str *string = create_new_string();
    CH_TYPE ch;

    // Take the input in the string's content
    printf("Enter the string: ");
    string_input(string);

    // Get the character that will replace the vowels
    nl();
    printf("Enter the character to replaced with vowels: ");
    ch = getchar();
    nl();
    
    // Replace the vowels in the string's content with ch
    replace(string, ch);

    // Display the new string to the console
    display(string);

    return 0;
}