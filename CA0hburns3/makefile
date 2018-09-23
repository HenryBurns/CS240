#
# Specifiy the target
filename = BurnsHenry-hburns3-Hello
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	Hello.o Hello_class.o
	g++  ${filename}.o Hello_Class.o  -o ${filename}.exe

# Specify how the object files should be created from source files
Hello.o:	${filename}.cpp
	g++ -c ${filename}.cpp

Hello_class.o:	Hello_Class.cpp
	g++ -c Hello_Class.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o ${filename}.exe

