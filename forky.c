#include "pattern1.h"
#include "pattern2.h"
#include "pattern3.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pattern_number> <number_of_things>\n", argv[0]);
        return 1;
    }

    int pattern = atoi(argv[1]);
    int things = atoi(argv[2]);

    if (things < 1 || things > 256) {
        printf("Number of things must be between 1 and 256.\n");
        return 1;
    }

    switch (pattern) {
    case 1:
        pattern_1(things);
        break;
    case 2:
        pattern_2(things);
        break;
    case 3:
        pattern_3(things);
        break;
    default:
        printf("Invalid pattern number. Use 1, 2, or 3.\n");
        return 1;
    }

    return 0;
}
