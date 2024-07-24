G++ = g++
FILES = main.cpp ./src/__Executer/Executer.cpp ./src/__Intersection/Intersection.cpp ./src/__Copywriter/Copywriter.cpp ./src/__Cache/Cache.cpp ./src/__Parser/Parser.cpp ./src/__Types/__Base_Type/Base_Type.cpp ./src/__Types/__Base_Type/__Fundamental_Type/Fundamental_Type.cpp ./src/__Types/__Base_Type/__Object/Object.cpp ./src/__Types/__Base_Type/__Fundamental_Type/__Number/Number.cpp ./src/__Types/__Base_Type/__Fundamental_Type/__Boolean/Boolean.cpp ./src/__Types/__Base_Type/__Fundamental_Type/__Null/Null.cpp ./src/__Types/__Base_Type/__Fundamental_Type/__String/String.cpp ./src/__Types/__Base_Type/__Fundamental_Type/__Undef/Undef.cpp ./src/__Types/__Base_Type/__Object/__Array/Array.cpp ./src/__Types/__Base_Type/__Object/__Function/Function.cpp ./src/__AST/AST.cpp
EXE = Interpreter
FILEPATH = ./test/test.mn
DEL = rm

all:
	$(G++) $(FILES) -o $(EXE)

run:
	./$(EXE) $(FILEPATH)

del:
	$(DEL) $(EXE)