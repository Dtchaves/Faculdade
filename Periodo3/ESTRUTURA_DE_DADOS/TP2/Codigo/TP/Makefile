CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o  $(OBJ)/Ponto.o  $(OBJ)/Reta.o $(OBJ)/Leitura_Entrada.o $(OBJ)/Fecho_Convexo.o $(OBJ)/Tempo.o 
HDRS = $(INC)/Reta.hpp $(INC)/Ponto.hpp $(INC)/Leitura_Entrada.hpp $(INC)/Pilha.hpp $(INC)/Fecho_Convexo.hpp $(INC)/Tempo.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/fecho

make:  $(EXE)


$(BIN)/fecho: $(OBJS)
	$(CC) -o $(BIN)/fecho $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Reta.o: $(HDRS) $(SRC)/Reta.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Reta.o $(SRC)/Reta.cpp 

$(OBJ)/Ponto.o: $(HDRS) $(SRC)/Ponto.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Ponto.o $(SRC)/Ponto.cpp 

$(OBJ)/Fecho_Convexo.o: $(HDRS) $(SRC)/Fecho_Convexo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Fecho_Convexo.o $(SRC)/Fecho_Convexo.cpp 

$(OBJ)/Leitura_Entrada.o: $(HDRS) $(SRC)/Leitura_Entrada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Leitura_Entrada.o $(SRC)/Leitura_Entrada.cpp 

$(OBJ)/Tempo.o: $(HDRS) $(SRC)/Tempo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Tempo.o $(SRC)/Tempo.cpp 

clean:
	rm -f $(EXE) $(OBJS) *.csv
