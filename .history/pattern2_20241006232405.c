#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "pattern2.h"

// Sequential forking process
void pattern_2(int things) {
    srand(time(NULL));
    int pid;

    for (int iter = 1; iter <= things; iter++) {
        pid = fork();
        if (pid == 0) {
            int sleep_time = (rand() % 8) + 1;
            printf("Thing %d (PID %d) starting\n", iter, getpid());
            printf("Thing %d (PID %d) creating Thing %d\n", iter, getpid(), iter + 1);
            sleep(sleep_time);
            printf("Thing %d (PID %d) exiting\n", iter, getpid());
            exit(0);
        } else if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else {
            wait(NULL);
        }
    }
}
