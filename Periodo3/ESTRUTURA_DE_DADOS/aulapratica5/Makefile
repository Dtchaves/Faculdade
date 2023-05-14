CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/geraarvbin.o 
HDRS = 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/geraarvbin

run:  $(EXE)
	$(EXE) -o saida.txt -n 12 -n 19

$(BIN)/geraarvbin: $(OBJS)
	$(CC) -pg -o $(BIN)/geraarvbin $(OBJS) $(LIBS)

$(OBJ)/geraarvbin.o: $(HDRS) $(SRC)/geraarvbin.c
	$(CC) $(CFLAGS) -o $(OBJ)/geraarvbin.o $(SRC)/geraarvbin.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out *.txt
