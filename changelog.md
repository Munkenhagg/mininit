## changelog

- changed reaper to do nothing on SIGCHLD as it caused it to hang before

- now boots but upon entering username in agetty no password prompt appears and agetty restarts

- add sulogin.base because agetty is broken

- fix typo in dhcp.plugin

- add cmdline parser, now uses a safe service list if mininit.rescue is provided

- fix accidentally sourcing the directory in ready-indicator.plugin

- make udev.base also source env.source

- add cpu-tune.plugin to solve cpu problems as mine ran 400Mhz when clock speed is not set, also as cache ratio(uncore) control in the plugin to reduce temps

- make agetty.base not wait forever and instead only spawn once

- make init sleep forever so it never dies when/if the last service exits

- change shutdown to timeout 3 wait instead of sleeping 3s and then timeout 3 wait

- changed hostname.plugin in services.list to match the actual name hostname.base

- changed udev.base from using --daemon to -d to be compatible with busybox mdev aswell

- made udev.base default to mdev as udevd is unreliable because systemd uses its own udev which does not work on custom inits most of the time

- made a PAM-fixer to make PAM work by creating utmp, wtmp and btmp. might not do anything in some cases

- fix cpu-tune.plugin setting too low values

- added installer

- added setsid to agetty so that it now works

- add workaround for XDG_RUNTIME_DIR

- add kernel module loader

- add static session for xdg_runtime_dir fixer

- add system command parser

- ~~make seperate udev and mdev services as syntax heavily varies~~

- abandon udevd as mdev is often more reliable and predictable

- add mininit binary for basic features that are only possible in C like a reaper

- add policy system

- add policy compilation into tempoary ramdisk(tmpfs) at /etc/mininit/tmp to reduce I/O

- make shutdown called on poweroff, reboot, and halt instead of a shutdown function

- make cmdline actually work by replacing the while loop with a actually functional for loop

- add timeout to services

- remove time measure

- move mininit logs to /var/log/mininit

- change logs from mininit.log to services.log

- move the mininit binary from raw cpart_src/ to cpart_src/binary

- make the mininit binary be able to run shutdown logic only and never shutdown fully

- add session bus plugin for dbus and seatd

- add debug message for mounter-fstab-all.base
