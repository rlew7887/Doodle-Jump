# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
# -std=c++11 -Wall -Wextra 

# Executable name

TARGET = game

# Source files

SRCS = main.cpp

# Build and run tests

.PHONY: all

all:

	$(CXX) $(SRCS) $(CXXFLAGS) -o $(TARGET) 

	./$(TARGET)

# Clean rule

.PHONY: clean

clean:

	rm -f $(TARGET)