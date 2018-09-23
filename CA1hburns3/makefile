#
# Specifiy the target
filename1 = Voter
filename2 = VoterDB
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	${filename1}.o ${filename2}.o
	g++  ${filename1}.o ${filename2}.o  -o ${filename1}.exe

# Specify how the object files should be created from source files
${filename1}.o:	${filename1}.cpp
	g++ -c ${filename1}.cpp

${filename2}.o:	${filename2}.cpp
	g++ -c ${filename2}.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o ${filename1}.exe

