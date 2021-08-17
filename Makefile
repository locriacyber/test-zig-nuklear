# remember to download libraylib.so at https://github.com/raysan5/raylib/releases

BINARIES = example-c example-zig example-c-zig-linked
CC = gcc
CFLAGS = -I. -lraylib -L.

default_target: $(BINARIES)
.PHONY : default_target, clean

clean:
	rm *.o $(BINARIES)

raylib-nuklear.o: raylib-nuklear.c raylib-nuklear.h
	$(CC) $(CFLAGS) -c raylib-nuklear.c

example-c.o: example.c
	$(CC) $(CFLAGS) -c -o example-c.o example.c

example-c: raylib-nuklear.o example-c.o
	$(CC) $(CFLAGS) example-c.o raylib-nuklear.o -o example-c

example-c-zig-linked: raylib-nuklear.o example-c.o
	zig cc $(CFLAGS) example-c.o raylib-nuklear.o -o example-c-zig-linked

example-zig: example.zig raylib-nuklear.o
	zig build-exe $(CFLAGS) -lc example.zig raylib-nuklear.o -femit-bin=example-zig

example-zig.o: example.zig
	zig build-obj $(CFLAGS) -lc example.zig raylib-nuklear.o -femit-bin=example-zig.o
