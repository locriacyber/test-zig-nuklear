# remember to download libraylib.so at https://github.com/raysan5/raylib/releases

default_target: example-c example-zig
.PHONY : default_target, clean

clean:
	rm *.o example-c example-zig

CC = gcc
CFLAGS = -I. -lraylib -L.

raylib-nuklear.o: raylib-nuklear.c
	$(CC) $(CFLAGS) -c raylib-nuklear.c

example-c: example.c raylib-nuklear.o
	$(CC) $(CFLAGS) example.c raylib-nuklear.o -o example-c

example-zig: example.zig raylib-nuklear.o
	zig build-exe $(CFLAGS) -lc example.zig raylib-nuklear.o -femit-bin=example-zig
