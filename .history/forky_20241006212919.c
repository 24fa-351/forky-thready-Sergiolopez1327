#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "forky.h"

void process_work(int process_number) {
    int sleep_time = (rand() % 8) + 1;  
    printf("Process %d (PID %d) starting\n", process_number, getpid());
    sleep(sleep_time);
    printf("Process %d (PID %d) exiting\n", process_number, getpid());
}

// Pattern 1: Concurrent forking
void pattern2(int n) {
    int pid;
    for (int i = 1; i <= n; i++) {
        pid = fork();
        if (pid == 0) {
            process_work(i);
            exit(0); 
        } else if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
    }

    for (int i = 1; i <= n; i++) {
        wait(NULL);
    }
}

// Pattern 2: Sequential forking
void pattern2(int n) {
    int pid;
    for (int i = 1; i <= n; i++) {
        pid = fork();
        if (pid == 0) {
            process_work(i);
            exit(0);  
        } else if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else {
            wait(NULL);
        }
    }
}

// Pattern 3: Tree forking (Extra credit)
void pattern3() {
    int pid;
    pid = fork();
    if (pid == 0) {
        printf("Process 1 creating Process 2\n");
        int child_pid = fork();
        if (child_pid == 0) {
            process_work(2);
            exit(0);
        } else {
            wait(NULL); 
            exit(0);
        }
    } else {
        pid = fork();
        if (pid == 0) {
            printf("Process 1 creating Process 3\n");
            process_work(3);
            exit(0);
        }
        wait(NULL);
        wait(NULL);
    }
}
