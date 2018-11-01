CC = g++
CC_FLAGS = -Wall
 
# File names
EXEC = war.exe
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(SOURCES) PlayingCard.o
	$(CC) $(SOURCES) -o $(EXEC)
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
checkmem:
	valgrind ./$(EXEC)
