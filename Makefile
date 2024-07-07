G++ = g++
FILES = main.cpp ./src/__Executer/Executer.cpp ./src/__Copywriter/Copywriter.cpp ./src/__Cache/Cache.cpp ./src/__Parser/Parser.cpp ./src/__Types/__Base_Type/Base_Type.cpp ./src/__Types/__Fundamental_Type/Fundamental_Type.cpp ./src/__Types/__Number/Number.cpp ./src/__AST/AST.cpp
EXE = Interpreter
DEL = rm

all:
	$(G++) $(FILES) -o $(EXE)
del:
	$(DEL) $(EXE)