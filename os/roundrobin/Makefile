CC=gcc
CFLAGS=-g -Wall
BIN=roundrobin

all: $(BIN)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

# $@ is the target i.e $(BIN)
# $^ is dependency list i.e $(BIN).c
$(BIN): $(BIN).c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN)
