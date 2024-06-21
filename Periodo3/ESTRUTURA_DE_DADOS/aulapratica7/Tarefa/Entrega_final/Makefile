CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Heapsort.o $(OBJ)/Insertsort.o $(OBJ)/Shellsort.o $(OBJ)/Vetor.o $(OBJ)/Tempo.o $(OBJ)/main.o 
HDRS = $(INC)/Heapsort.h $(INC)/Insertsort.h $(INC)/Shellsort.h $(INC)/Vetor.h $(INC)/Tempo.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/Tempo.o: $(HDRS) $(SRC)/Tempo.c
	$(CC) $(CFLAGS) -o $(OBJ)/Tempo.o $(SRC)/Tempo.c 
	
$(OBJ)/Heapsort.o: $(HDRS) $(SRC)/Heapsort.c
	$(CC) $(CFLAGS) -o $(OBJ)/Heapsort.o $(SRC)/Heapsort.c 

$(OBJ)/Shellsort.o: $(HDRS) $(SRC)/Shellsort.c
	$(CC) $(CFLAGS) -o $(OBJ)/Shellsort.o $(SRC)/Shellsort.c 

$(OBJ)/Vetor.o: $(HDRS) $(SRC)/Vetor.c
	$(CC) $(CFLAGS) -o $(OBJ)/Vetor.o $(SRC)/Vetor.c 

$(OBJ)/Insertsort.o: $(HDRS) $(SRC)/Insertsort.c
	$(CC) $(CFLAGS) -o $(OBJ)/Insertsort.o $(SRC)/Insertsort.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out *.csv
