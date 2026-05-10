#include "common.h"

int do_poweroff() {
    sync();
    shutdown_safe();
    reboot(RB_POWER_OFF);
    return 0;
}
