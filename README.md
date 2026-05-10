# mininit

## Update

- **boots** - it boots now and agetty properly loads. though XDG_RUNTIME_DIR isnt completely solved and no DE i have tested works. might require elogind

- mininit poweroff, reboot, and halt doesnt work, manually close apps and use sudo poweroff -f toshutdown or reboot system

## Info

- this is a init script to replace systemd and simplify a init to the bare minimum while allowing as much control as possible, allowing max user control and customization

- do not expect things like systemd services to work here, as they have a completely diffeerent format. to use them, you will have to convert the services yourself into scripts. tho some runit script might be compatible

- this purely a performance and feature init. if you want more compatibility and stability use openRC or similar

## Usage

- the service.list defines in which order everything should execute, stripping the extra calculation of dependencies but you have to order tham correctly yourself. recommended is to put custom scripts like intel-undervolt before the login manager(agetty)

- the env.source might have to be edited to contain correct paths and variables on exotic systems

- prefer using ttylog from env.source for logging + echoing to terminal

- scripts can be in any format, binary, shell, python, as long as they are executable or you have the correct interpreter installed and working and a correct shebang

- to fully background a script like a daemon, put the script(except shebang) inside parentheses an put & after the closing one. this will let the init continue running

- to make XDG_RUNTIME_DIR actually exist and work, you will have to edit /etc/passwd, fine the line with your username, for example `Munken:x:1000:1000::/home/Munken:/usr/bin/bash`, and change the `/usr/bin/bash` line to `/etc/mininit/extra/sessions/DEFAULT_SESSION`, you can change the shell at /etc/mininit/extra/SESSIONS/session.conf

- if you use mdev as your /dev populator, for /dev/null and similar to work without root, add this to your /etc/mdev.conf:

```/etc/mdev.conf
null 1:3 0666
zero 1:5 0666
random 1:8 0666
urandom 1:9 0666
```
