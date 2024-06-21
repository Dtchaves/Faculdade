BUILD = ./build
HPP = ./include
CPP = ./src/entidades
MAIN = ./src


all: $(BUILD)/search_machine.exe

$(BUILD)/search_machine.exe: $(MAIN)/main.cpp $(BUILD)/word_list.o
	c++ $< $(BUILD)/*.o -I $(HPP) -o $@

$(BUILD)/word_list.o: $(CPP)/word_list.cpp $(HPP)/word_list.h
	c++ -c $< -I $(HPP) -o $@

test:$(BUILD)/search_machine_test.exe

$(BUILD)/search_machine_test.exe:$(CPP)/word_list_test.cpp $(BUILD)/word_list.o 
	c++ $< $(BUILD)/*.o -I $(HPP) -o $@

run_test:
	./$(BUILD)/search_machine_test.exe


run:
	./$(BUILD)/search_machine.exe

clean:
	rm $(BUILD)/*.o $(BUILD)/*.exe
