#Makefile: data records

#macro definitions
CC = gcc
DEBUG = -g
#DEBUG = -O2
CFLAGS = -Wall -ansi -std=c99 $(DEBUG) -c 
LFLAGS = -Wall -ansi -std=c99 $(DEBUG)
MAIN = -DMAIN

#dummy targets
all: Data DataList

test: all
		valgrind ./Data
		valgrind ./DataList

clean: 
		rm -f *.o 
		rm -f Data DataList

Data.o: Data.c Data.h
		$(CC) $(CFLAGS) Data.c -o Data.o

Data: Data.c Data.h
		$(CC) $(MAIN) $(LFLAGS) Data.c -o Data

DataList.o: DataList.c DataList.h Data.h
		$(CC) $(CFLAGS) Data.c -o DataList.c

DataList: DataList.c DataList.h Data.h Data.o 
		$(CC) $(MAIN) $(LFLAGS) DataList.c Data.o -o DataList