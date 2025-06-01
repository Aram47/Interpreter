# Name of executable file
TARGET = Interpreter

# Compiller and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Include
# CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -Include

# Folder for source files
SRC_DIR = src
INCLUDE_DIR = include

# All .cpp files
SOURCES = main.cpp $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)

# Target by default
all: $(TARGET)

# Build the executable file
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run
run: $(TARGET)
	./$(TARGET)


# Commands
# make 				-> 		build the project
# make run 		-> 		build and run the project
# make clean 	-> 		remove all object files and the executable