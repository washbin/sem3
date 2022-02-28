CC=gcc
CFLAGS=-g -Wall
BIN=fork

all: $(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

$(BIN): $(BIN).c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN)
