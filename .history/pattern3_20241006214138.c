#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "pattern3.h"

// Function for each process to simulate work
void process_work(int thing_number) {
    int sleep_time = (rand() % 8) + 1;  // Sleep for 1-8 seconds
    printf("Thing %d (PID %d) starting\n", thing_number, getpid());
    sleep(sleep_time);
    printf("Thing %d (PID %d) exiting\n", thing_number, getpid());
}

// Pattern 3: Min-Heap process creation entirely within this function
void pattern_3(int things) {
    if (things < 1) {
        printf("At least 1 thing is required.\n");
        return;
    }

    srand(time(NULL));  // Initialize random seed

    int thing_number = 1;  // Start with the root process
    printf("Thing %d (root) starting\n", thing_number);

    // Min-Heap structure forking
    for (thing_number = 1; thing_number <= things; thing_number++) {
        int left_child = 2 * thing_number;
        int right_child = 2 * thing_number + 1;
        int left_pid = -1, right_pid = -1;

        // Fork the left child if it exists
        if (left_child <= things) {
            left_pid = fork();
            if (left_pid == 0) {
                // In the left child process
                printf("Thing %d creating Thing %d\n", thing_number, left_child);
                process_work(left_child);  // Left child simulates work
                exit(0);  // Left child exits after work
            }
        }

        // Fork the right child if it exists
        if (right_child <= things) {
            right_pid = fork();
            if (right_pid == 0) {
                // In the right child process
                printf("Thing %d creating Thing %d\n", thing_number, right_child);
                process_work(right_child);  // Right child simulates work
                exit(0);  // Right child exits after work
            }
        }

        // Parent process waits for both children (if they exist)
        if (left_child <= things) {
            wait(NULL);  // Wait for left child to finish
        }
        if (right_child <= things) {
            wait(NULL);  // Wait for right child to finish
        }

        // Parent finishes its work (this simulates the heap-like exit)
        if (thing_number == 1) {
            printf("Thing %d (PID %d) exiting\n", thing_number, getpid());
        }
    }
}
