MAIN = app
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude -Isrc

SRCS = $(shell find src -name "*.c")

BINS = $(patsubst %.c, bin/%.o, $(SRCS))

all: build

build: $(MAIN)

$(MAIN): $(BINS)
	$(CC) $(CFLAGS) $(BINS) -o bin/$(MAIN)

bin/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: build
	./bin/$(MAIN)

clean:
	rm -rf bin
	rm -f $(MAIN)

leaks:
	codesign --force --options runtime --sign - --entitlements entitlements.plist ./$(MAIN)
	leaks --atExit -- ./$(MAIN)