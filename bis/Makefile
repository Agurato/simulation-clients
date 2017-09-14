#Makefile

CPP_FILES = $(wildcard *.cpp)
OBJ = $(CPP_FILES:.cpp=.o)
CC_FLAGS = -std=c++11
LD_FLAGS = 

all: simulation

simulation: $(OBJ)
	c++ $(CC_FLAGS) $(OBJ) -o simulation.out

%.o: %.cpp %.hpp
	c++ $(CC_FLAGS) -c $< -o $@

clean: clean_object
	rm -rfv mk.tmp
	rm -rfv *.out

clean_object:
	rm -rfv *.o
