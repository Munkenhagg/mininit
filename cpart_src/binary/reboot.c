#include "common.h"

int do_reboot() {
    sync();
    shutdown_safe();
    reboot(RB_AUTOBOOT);
    return 0;
}
