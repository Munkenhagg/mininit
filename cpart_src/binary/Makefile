CC = gcc
CFLAGS = -Wall -Wextra -static -O2
OUT = ../out
BIN = ../../bin
SRC = binary.c shutdown_safe.c halt.c reboot.c poweroff.c reaper.c usage.c

.PHONY: all mininit clean install

all: mininit install

mininit:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)/mininit.cpart

install: mininit
	mkdir -p $(BIN)
	cp $(OUT)/mininit.cpart $(BIN)/mininit

clean:
	rm -f $(OUT)/mininit.cpart
	rm -f $(BIN)/mininit