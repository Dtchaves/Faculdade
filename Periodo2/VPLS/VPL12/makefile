all: jogo.exe

jogo.exe: main.cpp jogo_da_vida.o
	c++ main.cpp *.o -o jogo.exe

jogo_da_vida.o: jogo_da_vida.cpp jogo_da_vida.h
	c++ -c jogo_da_vida.cpp -o jogo_da_vida.o

run: 
	./jogo.exe