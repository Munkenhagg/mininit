#include "common.h"

int do_halt() {
    sync();
    shutdown_safe();
    reboot(RB_HALT_SYSTEM);
    return 0;
}
