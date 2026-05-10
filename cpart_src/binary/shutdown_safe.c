#include "common.h"

int shutdown_safe() {
    char *arg[] = {"/bin/sh", "/etc/mininit/bin/shutdown", NULL};
    char *env[] = {NULL};
    execve("/bin/sh", arg, env);
    return 1;
}
