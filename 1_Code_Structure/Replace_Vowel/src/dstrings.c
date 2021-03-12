#include "../include/dstrings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_str* create_new_string() {
    // Creating a new string dynamically
    t_str *new_string = malloc(sizeof(t_str));

    // Creating the values array of new string based on the given length
    new_string->content = malloc(sizeof(CH_TYPE) * LENGTH);

    // Initializing the length and content data of the new string
    new_string->max_length = LENGTH;
    new_string->length = 0;
    memset(new_string->content, 0, sizeof(CH_TYPE) * LENGTH);

    return new_string;
}

void extend_string(t_str* existing_string) {
    // Creating a new content array of double length of that of the existing string's content array
    CH_TYPE* new_content = malloc(sizeof(CH_TYPE) * existing_string->max_length * 2);

    // Initializing the new content array
    memset(new_content, 0, sizeof(CH_TYPE) * existing_string->max_length * 2);

    // Copying the data of content array of existing string into the new content array
    for (VAL_TYPE index = 0; index < existing_string->length; index++)
        new_content[index] = existing_string->content[index];

    // Updating the length of the existing_string and the content array with the new content array
    // and free the old content
    existing_string->max_length *= 2;
    free(existing_string->content);
    existing_string->content = new_content;
}

void string_input(t_str *string) {
    CH_TYPE ch;

    // Take the input till the newline or end-of-line is reached
    while (1) {
        ch = getchar();

        if (ch == '\n' || ch == EOF)
            break;

        string->content[string->length++] = ch;

        // If the string's content array is full, extend its size
        if (string->length == string->max_length)
            extend_string(string);
    }
}

void replace(t_str *string, CH_TYPE ch) {
    // Check for string's content character by character and replace the vowels
    // with the given characeter ch.
    for (VAL_TYPE index = 0; index < string->length; index++)
        if (CEHCK_VOWEL(string->content[index]))
            string->content[index] = ch;
}

void display(t_str *string) {
    printf("New String is: ");
    
    // Display the string
    for (VAL_TYPE index = 0; index < string->length; index++)
        printf(CH_FS, string->content[index]);

    nl();
}
