BINARIES = example-c example-zig
CC = zig cc
CFLAGS = -I. -g

default_target: $(BINARIES)
.PHONY : default_target, clean

clean:
	rm *.o $(BINARIES)

dummy.o: dummy.c dummy.h
	$(CC) -c $(CFLAGS) dummy.c -o dummy.o

example-c: example.c dummy.o
	$(CC) $(CFLAGS) example.c dummy.o -o example-c

example-zig: example.zig dummy.o
	$(CC) $(CFLAGS) example.zig dummy.o -o example-zig
