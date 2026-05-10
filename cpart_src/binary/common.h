#include <unistd.h>
#include <sys/reboot.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <libgen.h>

#ifndef COMMON_H
#define COMMON_H

int do_halt();
int do_poweroff();
int do_reboot();
int shutdown_safe();
void usage(char *Pname);
void reaper(int sig);


#endif
