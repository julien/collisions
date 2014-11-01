SHELL := /bin/bash
CC := gcc
CFLAGS := -Wall -O3

DEPS := $(shell find src -type f -name '*.h')
SRC  := src/main.c
BIN  := bin/a.out

default: clean $(BIN) run

clean:
	-@rm -fr bin

$(BIN): $(SRC) $(DEPS)
	@mkdir -p $(@D)
	$(CC) -o $@ $< $(CFLAGS)

run: $(BIN)
	@./$<


.PHONY: clean run

