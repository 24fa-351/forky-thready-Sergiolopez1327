#include "pattern3.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void pattern_3(int things) {
    if (things < 1) {
        printf("At least 1 thing is required.\n");
        return;
    }

    int current_node = 1; 
    printf("Thing %d (PID %d) starting\n", current_node, getpid());

    while (current_node <= things) {
        int left_child = 2 * current_node;
        int right_child = 2 * current_node + 1;

        pid_t left_pid = -1, right_pid = -1;

        if (left_child <= things) {
            printf("Thing %d creating Thing %d\n", current_node, left_child);
        }
        if (right_child <= things) {
            printf("Thing %d creating Thing %d\n", current_node, right_child);
        }

        if (left_child <= things) {
            left_pid = fork();
            if (left_pid == 0) {
                current_node = left_child;
                printf("Thing %d (PID %d) starting\n", current_node, getpid());
                continue; 
            }
        }

        if (right_child <= things) {
            right_pid = fork();
            if (right_pid == 0) {
                current_node = right_child;
                printf("Thing %d (PID %d) starting\n", current_node, getpid());
                continue; 
            }
        }

        if (left_pid > 0) {
            waitpid(left_pid, NULL, 0);
        }
        if (right_pid > 0) {
            waitpid(right_pid, NULL, 0);
        }

        printf("Thing %d (PID %d) exiting\n", current_node, getpid());
        exit(0);
    }
}
