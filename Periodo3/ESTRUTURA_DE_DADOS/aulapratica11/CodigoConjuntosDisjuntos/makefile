CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Relacao.o $(OBJ)/ConjuntoDisjunto.o $(OBJ)/main.o 
HDRS = $(INC)/Relacao.hpp $(INC)/ConjuntoDisjunto.hpp 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE) 
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) -lm

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Relacao.o: $(HDRS) $(SRC)/Relacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Relacao.o $(SRC)/Relacao.cpp

$(OBJ)/ConjuntoDisjunto.o: $(HDRS) $(SRC)/ConjuntoDisjunto.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ConjuntoDisjunto.o $(SRC)/ConjuntoDisjunto.cpp

clean:
	rm -f $(EXE) $(OBJS)