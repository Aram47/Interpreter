G++ = g++ -std=c++11
FILES = main.cpp ./src/FileHandler_/FileHandler.cpp
EXE = Interpreter
DELETE = rm
all:
	$(G++) $(FILES) -o $(EXE)
del:
	$(DELETE) $(EXE)