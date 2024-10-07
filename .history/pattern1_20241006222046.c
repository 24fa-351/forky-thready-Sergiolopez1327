#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "pattern1.h"

void pattern_1(int things) {
    srand(time(NULL));
    pid_t pids[things];

    for (int iter = 1; iter <= things; iter++) {
        pids[iter] = fork();
        if (pids[iter] == 0) {
            int sleep_time = (rand() % 8) + 1;
            printf("Thing %d (PID %d) starting\n", iter, getpid());
            sleep(sleep_time);
            printf("Thing %d (PID %d) exiting\n", iter, getpid());
            exit(EXIT_SUCCESS);
        } else if (pids[iter] < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int iter = 1; iter <= things; iter++) {
        wait(NULL);
    }
}
