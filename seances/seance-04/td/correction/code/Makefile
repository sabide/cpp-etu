CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic \
	-fsanitize=address,undefined -g

.PHONY: all run clean

all: int_array

int_array: int_array.cpp int_array.hpp main.cpp
	$(CXX) $(CXXFLAGS) int_array.cpp main.cpp -o $@

run: int_array
	./int_array

clean:
	rm -f int_array
	rm -rf int_array.dSYM
