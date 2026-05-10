#include "common.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Not enough arguments!\n");
        usage(argv[0]);
        return 1;
    }
    if (argc > 2) {
        printf("Too many arguments!\n");
        usage(argv[0]);
        return 1;
    }
    char *signal = argv[1];
    printf("sending %s to /run/mininit.signal", signal);
    writesignal(signal);
    return 0;
}
