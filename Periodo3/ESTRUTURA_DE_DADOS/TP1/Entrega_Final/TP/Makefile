CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Arvore.o $(OBJ)/Pilha.o $(OBJ)/No.o $(OBJ)/Leitura_Entrada.o $(OBJ)/main.o 
HDRS = $(INC)/Pilha.hpp $(INC)/Arvore.hpp $(INC)/No.hpp $(INC)/Leitura_Entrada.hpp
CFLAGS = -Wall -c -pg -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) $(MAKECMDGOALS)

$(MAKECMDGOALS):	

$(BIN)/main: $(OBJS)
	$(CC) -pg -I$(INC) -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/No.o: $(HDRS) $(SRC)/No.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/No.o $(SRC)/No.cpp

$(OBJ)/Leitura_Entrada.o: $(HDRS) $(SRC)/Leitura_Entrada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Leitura_Entrada.o $(SRC)/Leitura_Entrada.cpp

$(OBJ)/Pilha.o: $(HDRS) $(SRC)/Pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Pilha.o $(SRC)/Pilha.cpp

$(OBJ)/Arvore.o: $(HDRS) $(SRC)/Arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Arvore.o $(SRC)/Arvore.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
