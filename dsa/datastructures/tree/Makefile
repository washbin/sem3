CC=gcc
CFLAGS=-g -Wall
BINS=tree

all: $(BINS)

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BINS)

# $@ is the target
# $^ is dependency list
%: %.c
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) $(BINS)
