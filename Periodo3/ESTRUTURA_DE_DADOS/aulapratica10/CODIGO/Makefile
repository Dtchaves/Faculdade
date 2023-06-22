CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/arvexp.o 
HDRS = 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/arvexp

run:  $(EXE) 
	$(EXE)

time: $(EXE)
	time ./$(EXE)

$(BIN)/arvexp: $(OBJS)
	$(CC) -Dm=2 -DCARGA=100 -o $(BIN)/arvexp $(OBJS) $(LIBS) -lm

$(OBJ)/arvexp.o: $(HDRS) $(SRC)/arvexp.c
	$(CC) $(CFLAGS) -o $(OBJ)/arvexp.o $(SRC)/arvexp.c


clean:
	rm -f $(EXE) $(OBJS)
