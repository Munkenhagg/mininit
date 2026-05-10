#include "common.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Not enough arguments!\n");
        usage(argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "reboot") == 0) {
        do_reboot();
    } else if (strcmp(argv[1], "poweroff") == 0) {
        do_poweroff();
    } else if (strcmp(argv[1], "halt") == 0) {
        do_halt();
    } else if (strcmp(argv[1], "reaper") == 0) {
        signal(SIGCHLD, reaper);
        while (1) pause();
    } else if (strcmp(argv[1], "shutdownlogic") == 0) {
        shutdown_safe();
    } else {
        printf("Unknown command: %s\n", argv[1]);
        usage(argv[0]);
        return 1;
    }
}
