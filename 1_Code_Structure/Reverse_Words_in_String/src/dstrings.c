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

void fill_string(t_str *string, CH_TYPE ch) {
    // Fill the string
    string->content[string->length++] = ch;

    // If the string's content array is full, extend its size
    if (string->length == string->max_length)
        extend_string(string);
}

void string_input(t_str *string) {
    CH_TYPE ch;

    // Take the input till the newline or end-of-line is reached and the fill the string
    while (1) {
        ch = getchar();
        fill_string(string, ch);
    
        if (ch == '\n' || ch == EOF)
            break;
    }
}

void reverse(t_str *string) {
    // Create the word string
    t_str *word = create_new_string();

    // Variables to mark the start and end of the word in string
    VAL_TYPE start = 0, end = -1;

    // Check for string's content word by word and reverse it
    for (VAL_TYPE index = 0; index < string->length; index++) {
        // Reverse the word and store it in the string
        if (CHECK_SPACE(string->content[index])) {
            end = index;

            // Reverse the word in the string
            for (VAL_TYPE word_index = 0; word_index < (VAL_TYPE) (word->length / 2); word_index++) {
                string->content[start++] = word->content[word->length - word_index - 1];
                string->content[end-- - 1] = word->content[word_index];
            }

            // Update the start and end
            start = index + 1;
            end = index;

            // Update the word string
            free(word);
            word = create_new_string();
        }

        else
            fill_string(word, string->content[index]);
    }

    // Free the word string
    free(word);
}

void display(t_str *string) {
    printf("New String is: ");
    
    // Display the string
    for (VAL_TYPE index = 0; index < string->length; index++)
        printf(CH_FS, string->content[index]);

    nl();
}
