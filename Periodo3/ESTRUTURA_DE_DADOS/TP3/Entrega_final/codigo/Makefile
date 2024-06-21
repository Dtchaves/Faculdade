CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o  $(OBJ)/entrada.o  $(OBJ)/compactar.o $(OBJ)/hash.o  $(OBJ)/huffman.o $(OBJ)/utilidades.o $(OBJ)/descompactar.o $(OBJ)/tempo.o 
HDRS = $(INC)/entrada.hpp $(INC)/compactar.hpp $(INC)/hash.hpp $(INC)/huffman.hpp $(INC)/utilidades.hpp $(INC)/descompactar.hpp	$(INC)/descompactar.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/entrada.o: $(HDRS) $(SRC)/entrada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/entrada.o $(SRC)/entrada.cpp 

$(OBJ)/compactar.o: $(HDRS) $(SRC)/compactar.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/compactar.o $(SRC)/compactar.cpp 

$(OBJ)/hash.o: $(HDRS) $(SRC)/hash.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/hash.o $(SRC)/hash.cpp 

$(OBJ)/huffman.o: $(HDRS) $(SRC)/huffman.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/huffman.o $(SRC)/huffman.cpp 
	
$(OBJ)/utilidades.o: $(HDRS) $(SRC)/utilidades.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/utilidades.o $(SRC)/utilidades.cpp 

$(OBJ)/descompactar.o: $(HDRS) $(SRC)/descompactar.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/descompactar.o $(SRC)/descompactar.cpp 

$(OBJ)/tempo.o: $(HDRS) $(SRC)/tempo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tempo.o $(SRC)/tempo.cpp 

clean:
	rm -f $(EXE) $(OBJS) *.csv
