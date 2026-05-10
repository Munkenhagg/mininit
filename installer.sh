#!/bin/sh
set -e
if [ ! "$BYPASS" = "Y" ]; then
    echo "Warning: this script is not finished, refusing to run. use `BYPASS=Y $(basename $0)` to run anyway"
    exit 1
fi
DIR="$(dirname $0)"
EDITOR=cat # safe default

# if got put in an editor then edit METHOD. install method is not created yet so dont use install method
METHOD="" # possibilities: "rsync" "install" "copy", rsync is recommended but can require installing rsync. copy is completely POSIX and universal

pre() {
    mkdir -p /etc/mininit
    chmod 0755 /etc/mininit
}
rsyncmd() {
    rsync $DIR/ /etc/mininit/
}
copymd() {
    cp -r $DIR/* /etc/mininit/
}
#installmd() {}

cd cpart_src
make clean
make install
cd ..
pre
case "$METHOD" in
    "rsync") rsyncmd ;;
    #"install") installmd ;;
    "copy") copymd ;;
    *)
    echo "No method set! please set a method."
    sleep 3
    "$EDITOR" "$0"
esac

cd /etc/mininit
chmod 755 init env.source $(find services/ -type f)
chmod 644 services.list rescue.list
chmod 444 README.md changelog.md
chown root:root -R .