/*
    A normal C function that is executed as a thread,
    when its name is specified in pthresad_create()
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
    Global Variables
        - flag, to check the progress of thread.
*/
int flag = 1;

// Thread Function
void* myThread (void *argp) {
    // Counter to count till the thread function overs 
    int counter = 1;

    fprintf(stdout, "\nPrinting from Thread...\n");

    while (flag) {
        fprintf(stdout, "%d\n", counter++);
        sleep(1);
    }
    
    return NULL;
}

// Main Function parallel to thread function
void duringThread(unsigned int time) {
    // Perform the sleep process and after that change the flag to
    // mark the end of the thread.
    sleep(time);
    flag = 0;
}

int main (void) {
    /* Variables to store thread id and sleep count*/
    pthread_t thread_id;
    unsigned int time;

    /* Taking input for the sleep count */
    fprintf(stdout, "Enter the sleep count (in secs): ");
    fscanf(stdin, "%u", &time);

    /* Display Info before, in-between and after thread */
    // Before thread
    fprintf(stdout, "\nBefore Thread\n");

    // Creating Thread
    pthread_create(&thread_id, NULL, myThread, NULL);

    // Running in between process
    duringThread(time);

    // Joning thread
    pthread_join(thread_id, NULL);

    // After thread
    fprintf(stdout, "\nAfter Thread\n");

    return 0;
}
