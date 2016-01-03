## "Stack" is very simple implementation of stack data structure
## Copyright (C) 2015  Robin Obůrka
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
