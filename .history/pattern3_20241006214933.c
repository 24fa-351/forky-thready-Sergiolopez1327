#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "pattern3.h"

void pattern_3(int things) {
    if (things < 1) {
        printf("At least 1 thing is required.\n");
        return;
    }

    srand(time(NULL));

    int thing_number = 1;
    printf("Thing %d (root) starting\n", thing_number);

    for (thing_number = 1; thing_number <= things; thing_number++) {
        int left_child = 2 * thing_number;
        int right_child = 2 * thing_number + 1;
        int left_pid = -1, right_pid = -1;

        if (left_child <= things) {
            left_pid = fork();
            if (left_pid == 0) {
                printf("Thing %d creating Thing %d\n", thing_number, left_child);
                int sleep_time = (rand() % 8) + 1;
                printf("Thing %d (PID %d) starting\n", left_child, getpid());
                sleep(sleep_time);
                printf("Thing %d (PID %d) exiting\n", left_child, getpid());
                exit(0);
            }
        }

        if (right_child <= things) {
            right_pid = fork();
            if (right_pid == 0) {
                printf("Thing %d creating Thing %d\n", thing_number, right_child);
                int sleep_time = (rand() % 8) + 1;
                printf("Thing %d (PID %d) starting\n", right_child, getpid());
                sleep(sleep_time);
                printf("Thing %d (PID %d) exiting\n", right_child, getpid());
                exit(0);
            }
        }

        if (left_child <= things) {
            wait(NULL);
        }
        if (right_child <= things) {
            wait(NULL);
        }

        if (thing_number == 1) {
            printf("Thing %d (PID %d) exiting\n", thing_number, getpid());
        }
    }
}
