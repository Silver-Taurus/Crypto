/*
    PMS (Password Management System)
        - Program to store the password enterd by the user
        - Password will be stored in the encrypted form
        - Username and Application name will be associated with the password

    Functionality provided by PMS
        - Add new entry (To store a new password along with username and application name)
        - Search a password (based on the given username)
        - List all passwords (decrypted, along with their associated username and application name)
        - Update a password (based on the given username)
        - Delete a password (based on the given username)
*/


/* ---------- Including header files ---------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ---------- User Defined Structures ---------- */
/*
    Structure string aliased as "str_t" to store a string type data
        - content (char *)
            - to store the string content in the dynamic string
        - max_length (int)
            - current max length of the dynamic string
        - length (int)
            - current length of the dynamic string
*/
typedef struct string {
    char *content;
    int max_length;
    int length;
} str_t;

/*
    Structure node aliased as "node_t" to store individual entry
        - username (str_t) 
            - to store the unique username associated with a password
        - password (str_t)
            - to store the password in the encrypted format
        - appname (str_t)
            - to store the application name associated with a password
        - next (node_t *)
            - to store the address of the next entry
*/
typedef struct node {
    str_t *username;
    str_t *password;
    str_t *appname;
    struct node *next;
} node_t;

/*
    Structure linked_list aliased as "list_t" to store the whole list
    of entries in the system
        - head (node_t *)
            - to store the head (or start) of the list of entries
        - length (int)
            - to store the length of the list of entries
    
    Note: length field is an extra feature which can be used
        - just for getting the length of the list (or total entries)
        - for performing length based traversal of list instead of
        regular NULL based traversal.
*/
typedef struct linked_list {
    node_t *head;
    int length;
} list_t;

/*
    Macros to be used as constants in the program
        - STR_SIZE (8)
            - Default size of the dynamic string
*/
#define STR_SIZE 8
#define OK 1
#define ERR 0
#define KEY 6


/* ---------- Function Definitions ---------- */

/* ----- str_t functions ----- */
/*
    (str_t *) create_string ()
        - function to create a new string of type str_t
        - intialize the fields of the variable
        - allocate memory to the content
        - return the created new string
*/
str_t* create_string () {
    // Creating or Allocating memory to a new_string variable of type str_t
    str_t *new_string = (str_t *) malloc(sizeof(str_t));

    // Initializing the fields of new_string
    new_string->length = 0;
    new_string->max_length = STR_SIZE;

    // Allocate memory to the content
    new_string->content = (char *) malloc(sizeof(char) * new_string->max_length);

    // Return the new_string created
    return new_string;
}

/*
    (void) extend_string (str_t *)
            - function to extend the length of the passed string
            - increate the max length by a double of current max_length
            - allocate memory to the new_content
            - retain the content data
            - free the content
            - store the new_content to content
*/
void extend_string (str_t *string) {
    char *new_content;
    int index;

    // Increase the size of string by doubling the max_length
    string->max_length *= 2;

    // Creating or Allocating memory to a new_content
    new_content = (char *) malloc(sizeof(char) * string->max_length);

    // Retain the content data
    for (index = 0; index < string->length; index++)
        new_content[index] = string->content[index];
    
    // Free the content
    free(string->content);

    // Storing the new_content to content
    string->content = new_content;
}

/*
    (void) input_string (str_t *)
        - function to take the input to be stored in the string variable
        - if the length reaches the max length, extend the string
*/
void input_string (str_t *string) {
    char ch;

    // Loop to take the input character by character till a newline occurs
    do {
        // Take a single character input from the console
        ch = getchar();

        if (ch != '\n')
            // Store the character to the string content and increase the length
            string->content[string->length++] = ch;

        else
            // Store the NULL character at the end of the string
            string->content[string->length++] = '\0';

        // Check if the content of string is full, if full, extend the string
        if (string->length == string->max_length)
            extend_string(string);

    } while (ch != '\n');
}

/*
    (void) encrypt_string (str_t *)
        - function to encrypt the content of the string
        - based on the chosen KEY
        - store the encrypted form of key
*/
void encrypt_string (str_t *string) {
    int index;

    // Create new content of the same size as of the original string
    char *new_content = (char *) malloc(sizeof(char) * string->length);

    // Form the encrypted data
    for (index = 0; index < string->length-1; index++)
        new_content[index] = string->content[index] + KEY;
    
    new_content[index] = '\0';

    // Free the current content
    free(string->content);

    // Store the new content
    string->content = new_content;
}

/*
    (void) decrypt_string (str_t *)
        - function to decrypt the content of the string
        - based on the chosen KEY
        - return the decrypted key without storing it
*/
char* decrypt_string (str_t *string) {
    int index;

    // Create new content of the same size as of the original string
    char *new_content = (char *) malloc(sizeof(char) * string->length);

    // Form the decrypted data
    for (index = 0; index < string->length-1; index++)
        new_content[index] = string->content[index] - KEY;
    
    new_content[index] = '\0';

    return new_content;
}

/* ----- node_t functions ----- */
/*
    (node_t *) create_node ()
        - function to create a new_node to store one entry
        - initialize the fields of the new_node to NULL
        - return the new_node
*/
node_t* create_node () {
    // Creating or Allocating memory to a new_node
    node_t *new_node = (node_t *) malloc(sizeof(node_t));

    // Initialize the fields of the new_node
    new_node->username = create_string();
    new_node->password = create_string();
    new_node->appname = create_string();
    new_node->next = NULL;

    // Return the new_node
    return new_node;
}

/* ----- list_t functions ----- */
/*
    (list_t *) create_list ()
        - function to create a new_list to store all entries
        - initialize the fields of the new_list
        - return the new_list
*/
list_t* create_list () {
    // Creating of Allocating memory to a new_list
    list_t *new_list = (list_t *) malloc(sizeof(list_t));

    // Initializing the fields of the new_list
    new_list->head = NULL;
    new_list->length = 0;

    // Return the new_list
    return new_list;
}

/*
    (void) insert ()
        - function to insert new node or entry at the last of the list
        - increment the length of the list
*/
void insert (list_t *list, node_t *node) {
    // Declare a traversal temporary node and make it point the head
    node_t *temp = list->head;

    // If head is NULL
    if (!temp)
        list->head = node;

    // Else if the list exists, insert at the end of the list
    else {
        // Loop till we get the last node or entry
        while (temp->next)
            temp = temp->next;
        
        // Insert the node or entry at the last of the list
        temp->next = node;
    }
    
    // Increase the length of the list
    list->length++;
}

/*
    (int) search_password (list_t *, str_t *)
        - function to search the entry based on the entered username
        - print if found
        - return the status of the process (OK or ERR)
*/
int search_password (list_t *list, str_t *username) {
    // Declare a traversal temporary node and make it point the head
    node_t *temp = list->head;

    // Loop till the node of the list is not empty (or NULL)
    while (temp) {
        // Compare the store username of a node or entry to the passed username
        // for which the password is to be searched
        if (strcmp(temp->username->content, username->content) == 0) {
            // Print information to the console
            printf(
                "\n%40s%40s%40s\n",
                "Username",
                "Password",
                "Application"
            );

            printf(
                "%40s%40s%40s\n\n",
                temp->username->content,
                decrypt_string(temp->password),
                temp->appname->content
            );
            
            // Return OK signal to tell the username was found and
            // updation of password is successful
            return OK;
        }

        // Update
        temp = temp->next;
    }

    // In case the username was not found, Return ERR signal, denoting
    // the searching is failed.
    return ERR;
}

/*
    (int) update_password (list_t *, str_t *, str_t *)
        - function to update the password of the entry whose username is
        matched to the entered username
        - update if found
        - return the status of the process (OK or ERR)
*/
int update_password (list_t *list, str_t *username, str_t *new_password) {
    // Declare a traversal temporary node and make it point the head
    node_t *temp = list->head;

    // Loop till the node of the list is not empty (or NULL)
    while (temp) {
        // Compare the store username of a node or entry to the passed username
        // for which the password is to be updated
        if (strcmp(temp->username->content, username->content) == 0) {
            // Free the previous password
            free(temp->password);

            // Store the new_password
            temp->password = new_password;

            // Return OK signal to tell the username was found and
            // updation of password is successful
            return OK;
        }

        // Update
        temp = temp->next;
    }

    // In case the username was not found, Return ERR signal, denoting
    // the updation of password is failed
    return ERR;
}

/*
    (int) delete_password (list_t *, str_t *)
        - function to delete the password of the entry whose username is
        matched to the entered username
        - delete if found
        - return the status of the process (OK or ERR)
*/
int delete_password (list_t *list, str_t *username) {
    // Declare current and previous traversal nodes and make the current
    // node point the head of the list
    node_t *cur = list->head, *prev = NULL;

    // Loop till the node of the list is not empty (or NULL)
    while (cur) {
        // Compare the store username of a node or entry to the passed username
        // for which the password is to be deleted
        if (strcmp(cur->username->content, username->content) == 0) {
            if (prev)
                prev->next = cur->next;

            else 
                list->head = cur->next;

            // Free the current entry
            free(cur);

            // Return OK signal to tell the username was found and
            // deletion of password is successful
            return OK;
        }

        // Update the previous and current pointers
        prev = cur;
        cur = cur->next;
    }

    // In case the username was not found, Return ERR signal, denoting
    // the updation of password is failed
    return ERR;
}

/* ----- driver functions ----- */
/*
    (void) add_entry (list_t *)
        - function to create new entry
        - and take the input from the user
        - insert that new entry to the list 
*/
void add_entry (list_t *list) {
    // Create a new node or entry
    node_t *new_entry = create_node();

    // Take the inputs from the user
    printf("Enter username: ");
    input_string(new_entry->username);
    printf("Enter password: ");
    input_string(new_entry->password);
    printf("Enter application name: ");
    input_string(new_entry->appname);

    // Encrpyt the password and display it
    encrypt_string(new_entry->password);
    printf("\nEncrypted password: %s\n", new_entry->password->content);

    // Insert the new entry to the list
    insert(list, new_entry);

    // Response message
    printf("\nNew entry successfully added...\n\n");
}

/*
    (void) search_entry (list_t *)
        - function to create new entry
        - and take the input from the user
        - insert that new entry to the list 
*/
void search_entry (list_t *list) {
    int rc;
    str_t *username = create_string();

    // Take the input for the username from the user
    // for which the password to be searched
    printf("Enter the username to be searched: ");
    input_string(username);

    // Search the username in the list and display
    // the password with info if, username found
    rc = search_password(list, username);

    if (rc == ERR)
        printf("\nEntered username doesn't found...\n\n");
}

/*
    (void) list_all_passwords (list_t *)
        - function to print all the passwords along with their info
*/
void list_all_passwords (list_t *list) {
    // Declare a traversal temporary node and make it point the head
    node_t *temp = list->head;

    // Print information to the console
    printf(
        "%40s%40s%40s\n",
        "Username",
        "Password",
        "Application"
    );

    // Loop till the node of the list is not empty (or NULL)
    while (temp) {
        // Print each entry
        printf(
            "%40s%40s%40s\n",
            temp->username->content,
            decrypt_string(temp->password), 
            temp->appname->content
        );

        // Update
        temp = temp->next;
    }

    // Formatting after last line
    printf("\n");
}

/*
    (void) update_entry (list_t *)
        - function to take input the username and new_password
        - if found update the password
*/
void update_entry (list_t *list) {
    int rc;
    str_t *username = create_string();
    str_t *new_password = create_string();

    // Take the input for the username and new_password from the
    // user for which the password to be updated
    printf("Enter the username to be updated: ");
    input_string(username);
    printf("Enter the new password: ");
    input_string(new_password);

    // Encrpyt the password and display it
    encrypt_string(new_password);
    printf("\nEncrypted password: %s\n", new_password->content);

    // Update the username in the list if found
    rc = update_password(list, username, new_password);

    if (rc == ERR)
        printf("\nEntered username doesn't found...\n\n");
}

/*
    (void) delete_entry (list_t *)
        - function to take input the username
        - if found delete the password entry
*/
void delete_entry (list_t *list) {
    int rc;
    str_t *username = create_string();

    // Take the input for the username from the user for which the
    // password entry to be deleted
    printf("Enter the username to be deleted: ");
    input_string(username);

    // Delete the username entry in the list if found
    rc = delete_password(list, username);

    if (rc == ERR)
        printf("\nEntered username doesn't found...\n\n");
}

/* ----- utility functions ----- */
/*
    (void) flush ()
        - function to clear the stdin buffer
*/
void flush () {
    char ch;
    do {
        ch = getchar();
    } while (ch != '\n');
}

/* ----- Main driver function ----- */
int main (void) {
    // Create the list for all entries
    list_t *list = create_list();
    int choice;

    // Menu
    do {
        // Display Menu
        printf(
            "Menu:\n"
            "1 - Add new entry\n"
            "2 - Search\n"
            "3 - List all passwords\n"
            "4 - Update passwords\n"
            "5 - Delete passwords\n"
            "6 - Exit\n"
            "Enter your choice: "
        );

        // Take the user input
        // fflush(stdin);
        scanf("%d", &choice);
        // fflush(stdin);
        flush();

        // Perform switch operation
        switch (choice) {
            case 1:
                add_entry(list);
                break;
        
            case 2:
                search_entry(list);
                break;
            
            case 3:
                list_all_passwords(list);
                break;

            case 4:
                update_entry(list);
                break;

            case 5:
                delete_entry(list);
                break;

            case 6:
                free(list);
                break;

            default:
                printf("\nEntered Invalid Choice...\n\n");
                break;
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}

