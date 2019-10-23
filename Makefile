
SRC = src
PROJECT = bin/FullCode
CC = gcc
CFLAGS = -ansi -std=c99 -Wall -c 
LFLAGS = -Wall -ansi -std=c99
BIN = bin
# OBJS = 

# Dummy targets
all: $(PROJECT)

clean:
	rm -rf ./$(SRC)/*.o ./$(PROJECT)

test:
	./$(PROJECT)

# Object files

$(SRC)/structures.o: $(SRC)/structures.h $(SRC)/structures.c
	$(CC) $(CFLAGS) $(SRC)/structures.c -o $(SRC)/structures.o

$(SRC)/main.o: $(SRC)/main.c $(SRC)/structures.h
	$(CC) $(CFLAGS) $(SRC)/main.c -o $(SRC)/main.o 

# Executables

$(PROJECT): $(SRC)/structures.o $(SRC)/main.o
	$(CC) $(LFLAGS) $(SRC)/structures.o $(SRC)/main.o -o $(PROJECT)

# EOF
