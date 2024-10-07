#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "pattern2.h"

// Function for each process to simulate work
void process_work(int thing_number) {
    int sleep_time = (rand() % 8) + 1;  // Sleep for 1-8 seconds
    printf("Thing %d (PID %d) starting\n", thing_number, getpid());
    sleep(sleep_time);
    printf("Thing %d (PID %d) exiting\n", thing_number, getpid());
}

// Pattern 2: Sequential forking
void pattern_2(int things) {
    int pid;
    for (int i = 1; i <= things; i++) {
        pid = fork();
        if (pid == 0) {
            // In child process
            process_work(i);
            exit(0);  // Child process exits
        } else if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else {
            // Parent waits for each child process before forking the next
            wait(NULL);
        }
    }
}
