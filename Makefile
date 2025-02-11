CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -g -Wall -c 
TARGETS = sort main

# all the targets to be compiled
all: $(TARGETS)

sort: sort.c sort.h
	$(CC) $(OBJFLAGS) $@.c
main: sort.o main.c
	$(CC) $(CFLAGS) $@.c sort.o -o $@

clean:
		rm *.o main
		rm -r *.dSYM