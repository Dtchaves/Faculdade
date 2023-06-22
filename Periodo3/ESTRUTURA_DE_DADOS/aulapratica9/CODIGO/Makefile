CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/AVL_MOD.o 
HDRS = 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/AVL_MOD

run:  $(EXE)
	$(EXE)

$(BIN)/AVL_MOD: $(OBJS)
	$(CC) -o $(BIN)/AVL_MOD $(OBJS) $(LIBS)

$(OBJ)/AVL_MOD.o: $(HDRS) $(SRC)/AVL_MOD.c
	$(CC) $(CFLAGS) -o $(OBJ)/AVL_MOD.o $(SRC)/AVL_MOD.c 


clean:
	rm -f $(EXE) $(OBJS)
