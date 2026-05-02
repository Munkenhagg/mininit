# mininit

## Info

- this is just a side-project for a custom init script, which i will be using on a future gentoo installation

- do not expect things like systemd services to work here, as they have a completely diffeerent format. to use them, you will have to convert the services yourself into scripts. tho some runit script might be compatible

- this purely a performance and speed init. if you want more compatibility use openRC

## Usage

- the service.list defines in which order everything should execute, stripping the extra calculation of dependencies but you have to order tham correctly yourself. recommended is to put custom scripts like intel-undervolt before the login manager(agetty)

- the env.source might have to be edited to contain correct paths and variables on exotic systems

- prefer using ttylog from env.source for logging + echoing to terminal

- scripts can be in any format, binary, shell, python, as long as they are executable or you have the correct interpreter installed and working

- to fully background a script like a daemon, put the script(except shebang) inside parentheses an put & at the closing one. this will let the init continue running.