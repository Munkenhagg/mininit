CC = gcc
CFLAGS = -Wall -Wextra -static -O2
OUT = ../out
BIN = ../../bin
SRC = cli.c usage.c writesignal.c

.PHONY: all api clean install

all: api install

api:
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)/api.cpart

clean:
	rm -f $(OUT)/api.cpart
	rm -f $(BIN)/api

install: api
	mkdir -p $(BIN)
	cp $(OUT)/api.cpart $(BIN)/api
