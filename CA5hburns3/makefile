CC = g++
CC_FLAGS = -Wall -pedantic -g -Wextra
 
# File names
EXEC = fly
SOURCES = $(wildcard *.cpp)
SOURCESHPP = $(wildcard *.hpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(SOURCES) $(SOURCESHPP) $(OBJECTS)
	$(CC) $(CC_FLAGS) $(SOURCES) -o $(EXEC)
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
checkmem:
	valgrind ./$(EXEC)
