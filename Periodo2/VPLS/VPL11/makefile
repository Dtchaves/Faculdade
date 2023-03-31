BUILD = ./build
HPP = ./include
CPP = ./src/entidades
MAIN = ./src


all: vpl_execution

vpl_execution: libes 
	c++ $(BUILD)/*.o -I $(HPP) -o vpl_execution

libes: $(BUILD)/Pessoa.o $(BUILD)/Professor.o $(BUILD)/Funcionario.o  $(BUILD)/main.o

$(BUILD)/%.o: $(CPP)/%.cpp $(HPP)/%.hpp
	c++ -c $< -I $(HPP) -o $@

$(BUILD)/%.o: $(MAIN)/%.cpp 
	c++ -c $< $(BUILD)/*.o -I $(HPP) -o $@
	
run:
	./vpl_execution

clean:
	rm $(BUILD)/*.o
