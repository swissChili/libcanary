CC=gcc 
CFLAGS=-Wall

all: demo
demo: demo.o
demo.o: demo.c libcanary/libcanary.h

clean:
	rm -f demo demo.o
run: demo
	./demo