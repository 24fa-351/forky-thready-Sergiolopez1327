
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "forky.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number_of_processes> <pattern_number>\n", argv[0]);
        return 1;
    }

    int num_processes = atoi(argv[1]);
    int forky_pattern = atoi(argv[2]);

    if (num_processes < 1 || num_processes > 256) {
        printf("Number of processes must be between 1 and 256.\n");
        return 1;
    }

    srand(time(NULL));  // Initialize random seed

    if (forky_pattern == 1) {
        concurrent_forky(num_processes);
    } else if (forky_pattern == 2) {
        sequential_forky(num_processes);
    } else if (forky_pattern == 3) {
        tree_forky();
    } else {
        printf("Invalid pattern number. Use 1, 2, or 3.\n");
        return 1;
    }

    return 0;
}