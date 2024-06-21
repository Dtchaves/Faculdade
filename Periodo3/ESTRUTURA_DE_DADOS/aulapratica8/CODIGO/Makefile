CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Pilha.o $(OBJ)/Fila_Circular.o $(OBJ)/memlog.o $(OBJ)/main.o 
HDRS = $(INC)/Pilha.h $(INC)/Fila_Circular.h $(INC)/memlog.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/Pilha.o: $(HDRS) $(SRC)/Pilha.c
	$(CC) $(CFLAGS) -o $(OBJ)/Pilha.o $(SRC)/Pilha.c 
	
$(OBJ)/Fila_Circular.o: $(HDRS) $(SRC)/Fila_Circular.c
	$(CC) $(CFLAGS) -o $(OBJ)/Fila_Circular.o $(SRC)/Fila_Circular.c 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out
