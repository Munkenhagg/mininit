#include "common.h"

void reaper(int sig) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}
