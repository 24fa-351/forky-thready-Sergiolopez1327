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

// Pattern 3: Tree forking
void pattern_3() {
    int pid;

    // Fork thing 2
    pid = fork();
    if (pid == 0) {
        printf("Thing 1 creating Thing 2\n");
        // Fork thing 4 from thing 2
        int child_pid = fork();
        if (child_pid == 0) {
            process_work(2);
            exit(0);
        } else {
            wait(NULL);  // Thing 2 waits for Thing 4 to finish
            exit(0);
        }
    } else {
        // Fork thing 3 from main process
        pid = fork();
        if (pid == 0) {
            printf("Thing 1 creating Thing 3\n");
            process_work(3);
            exit(0);
        }
        // Wait for both Thing 2 and Thing 3 to complete
        wait(NULL);
        wait(NULL);
    }
}
