CPP_FILES:=$(wildcard src/*.cpp)
OBJ_FILES:=$(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS:=-lm
CC=g++ -std=c++14
CC_FLAGS=-w

KDTREE.o:$(OBJ_FILES)
	$(CC) $(OBJECTS) -o $@ $^
obj/%.o:src/%.cpp 
	$(CC) -c $(CC_FLAGS) $< -o $@
