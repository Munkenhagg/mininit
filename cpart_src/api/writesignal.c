#include "common.h"

int writesignal(char *signal) {
    FILE *signal_file;
    signal_file = fopen("/run/mininit.signal", "w");
    fprintf(signal_file, "%s\n", signal);
    fclose(signal_file);
    return 0;
}