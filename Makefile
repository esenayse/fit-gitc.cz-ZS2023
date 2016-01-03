BIN=stack
CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=gnu99 -O0 -g
LIBS=

$(BIN): main.o stack.o
	$(CC) $(CFLAGS) $(LIBS) -o $(BIN) main.o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o stack.o stack.c

clean:
	rm *.o
	rm $(BIN)
