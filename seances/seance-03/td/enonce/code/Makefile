CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -fsanitize=address,undefined -g

.PHONY: all run clean

all: int_array

int_array: int_array.cpp main.cpp int_array.hpp
	$(CXX) $(CXXFLAGS) int_array.cpp main.cpp -o $@

run: int_array
	./int_array

clean:
	$(RM) int_array
	$(RM) -r int_array.dSYM
