#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void pattern_2(int things) {
    srand(time(NULL)); 

    for (int iter = 1; iter <= things; iter++) {
        printf("Thing %d (PID %d) starting\n", iter, getpid());

        if (iter < things) {
            printf("Thing %d (PID %d) creating Thing %d\n", iter, getpid(), iter + 1);

            pid_t pid = fork();
            if (pid == 0) { 
                continue;
            } else if (pid > 0) { 
                break;
            } else {
                perror("Fork failed");
                exit(1);
            }
        }

        int sleep_time = (rand() % 8) + 1;
        sleep(sleep_time);

        printf("Thing %d (PID %d) exiting\n", iter, getpid());
        exit(0); 
    }

    wait(NULL);
}
