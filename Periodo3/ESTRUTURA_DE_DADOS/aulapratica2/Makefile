CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Factorial.o $(OBJ)/Fibonacci.o $(OBJ)/Time_Counter.o
HDRS = $(INC)/Factorial.h $(INC)/Fibonacci.h $(INC)/Time_Counter.h
CFLAGS = -Wall -c -pg -ftest-coverage -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) 1 5
	$(EXE) 0 5

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/Factorial.o: $(HDRS) $(SRC)/Factorial.c
	$(CC) $(CFLAGS) -o $(OBJ)/Factorial.o $(SRC)/Factorial.c 

$(OBJ)/Fibonacci.o: $(HDRS) $(SRC)/Fibonacci.c
	$(CC) $(CFLAGS) -o $(OBJ)/Fibonacci.o $(SRC)/Fibonacci.c 

$(OBJ)/Time_Counter.o: $(HDRS) $(SRC)/Time_Counter.c
	$(CC) $(CFLAGS) -o $(OBJ)/Time_Counter.o $(SRC)/Time_Counter.c 

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
